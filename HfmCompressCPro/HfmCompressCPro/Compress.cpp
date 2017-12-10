#include"Huffman.h"
#include"Compress.h"
#include<iostream>
#define SIZE 256
using namespace std;

/*
*以二进制流的方式只读打开原文件，逐字节读取文件中的数据，使用Huffman编码对原文件中的字节重新编码 ，获得压缩后的文件数据，保存在一个char数组中
*1.计算压缩数据字节数：得到了Huffman编码之后，需要计算编码完整个文件需要的空间大小，计算方法：先计算每个字符的权值乘以该字符编码的长度，
*这样即认为同一个字符在编码文件中所占的大小，将256个这样的值相加即为编码整个文件所需要的空间大小，除以8即为总字节数
*/
int Compress(const char *pFilename)
{
    int nSize=0;
	//读取文件，初始化文件头
	HEAD sHead;
	if(InitHead(pFilename,sHead)==0)
	{
		return 0;
	}
	cout<<sHead.nLength<<"字节"<<endl;

	//生成Huffman树
	HTree pHT=NULL;
	HuffmanTree(pHT,sHead.aWeight);
	if(!pHT)
	{
		return 0;
	}

	//生成Huffman编码表
	HCode pHC=NULL;
	HuffmanCoding(pHC,pHT);
	free(pHT);  //释放Huffman树空间
	if(!pHC)
	{
		return 0;
	}

	//计算编码缓冲区大小
	for(int i=0;i<256;i++)
	{
		nSize+=sHead.aWeight[i]*strlen(pHC[i]); 
	}
	nSize=(nSize%8)?nSize/8+1:nSize/8;

	//对原文件进行压缩编码
	char *pBuffer=NULL;
	Encode(pFilename,pHC,pBuffer,nSize);
	//free(pHC);//释放Huffman编码表
	if(!pBuffer)
	{
		return 0;
	}

	//输出压缩文件
	int len=WriteFile(pFilename,sHead,pBuffer,nSize);
	//free(pBuffer);
	if(len<0)
	{
		return 0;
	}
	cout<<len<<"字节"<<endl;
	cout<<"压缩比率："<<(double)len/(double)sHead.nLength*100<<"%"<<endl;
}

/*一边读取一边查找Huffman编码表，将每个字符用相应的编码替换掉，这样就得到了重新编码后的文件，
 *此时会发现新的文件比原来的还大，所以需要对这个的到的编码进行压缩
 Encode（编码，译码）
 */
int Encode(const char *pFilename,const HCode pHC,char *pBuffer,const int nSize)
{
	//以二进制流形式打开文件
	FILE *in=fopen(pFilename,"rb");
	if(!in)
	{
		cerr<<"打开源文件失败"<<endl;
		return 0;
	}

	//开辟缓冲区
	pBuffer=(char *)malloc(nSize*sizeof(char));
	if(!pBuffer)
	{
		cerr<<"开辟缓冲区失败"<<endl;
		return 0;
	}

	//扫描文件，根据Huffman编码表对其进行压缩，压缩结果暂存到缓冲区中
	char cd[SIZE]={0};//工作区
	int pos=0;//缓冲区指针
	int ch;
	//扫描文件，根据Huffman编码表对其进行压缩，压缩结果暂存到缓冲区
	while(ch=fgetc(in)!=EOF)
	{
		strcat(cd,pHC[ch]);//从HC复制编码串到cd
		while(strlen(cd)>=8)
		{
		    //截取字符串左边的8个字符，编码成字节
			pBuffer[pos++]=Str2byte(cd);
			//字符串整体左移8字节
			for(int i=0;i<SIZE-8;i++)
			{
			    cd[i]=cd[i+8];
			}
		}
	}
	if(strlen(cd)>0)
	{
	     pBuffer[pos++]=Str2byte(cd);
	}
	//......
}

/**
*扫描文件和初始化文件头
*/
int InitHead(const char *pFilename,HEAD &sHead)
{
	//初始化文件头
	strcpy(sHead.aType,"HUF");//文件类型
	sHead.nLength=0;//原文件长度
	for(int i=0;i<SIZE;i++)
	{
		sHead.aWeight[i]=0;//权值
	}
	//以二进制流形式打开文件
	FILE *in=fopen(pFilename,"rb");
	if(!in)
	{
		cerr<<"初始化文件头失败！"<<endl;
		return 0;
	}

	//扫描文件，获得权重
	int ch;
	while(ch=fgetc(in)!=EOF)
	{
		sHead.aWeight[ch]++;
		sHead.nLength++;
	}
	//关闭文件，释放文件指针
	fclose(in);
	in=NULL;
	return sHead.nLength;
}

/*字符串编码表是以字符数组的形式保存的，重新编码后的数据将是一个很长的字符串，定义Str2byte含税将形如01010101字符串转换为字节，才能得到最终的编码*/
char Str2byte(const char *pBinStr)
{
	char b=0x00;
	for(int i=0;i<8;i++)
	{
		b = b<<1;//左移一位
		if(pBinStr[i]=='1')
		{
			b=b|0x01;
		}
	}
	return b;
}

/*写文件
*建立一个新的文件，文件名为“原文件名字+.huf”,将压缩后的数据写入文件
*为了保证压缩后的数据能被重新正确解压，必须将相关的解压缩规则写入到文件中去，这里的解码规则实际上就
*是权值数组weight，解压缩时只要根据权值信息表构建Huffman数就可以根据编码进行解压缩
*为了验证解压缩的文件是否正确，还需要将文件的大小存入文件中去，同时也可以将文件的类型存入问文件，用于判断是否是需要解压的文件，这里默认的是HUF类型
*因此，压缩文件中数据有两部分组成：1.文件头（包含文件类型，文件长度，权值数组）2. 压缩数据：压缩原文件后得到的数据
*/
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer,const int nSize)
{
	//生成文件名
	char filename[256]={0};
	strcpy(filename,pFilename);
	strcat(filename,".huf");

	//以二进制流形式打开文件
	FILE *out=fopen(filename,"wb");


	//写文件
	fwrite(&sHead,sizeof(HEAD),1,out);

	//写压缩后的编码
	fwrite(pBuffer,sizeof(char),nSize,out);

	//关闭文件，释放文件指针
	fclose(out);
	out=NULL;

	cout<<"生成压缩文件："<<filename<<endl;
	int len=sizeof(HEAD)+strlen(pFilename)+1+nSize;
	return len;

}