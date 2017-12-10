#include"Compress.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

/*
 *函数功能：编码文件
 *思路：在Compress（）函数中调用Encode（）函数，实现文件编码。编码后的数据保存在内存缓冲区中
 */
int Compress(const char * pFilename){
	//。。。
	//对原文件进行压缩编码
	char *pBuffer= NULL;
	//Encode(pFilename,pHC,pBuffer,nSize);
	if(!pBuffer){
	//  return ERROR;
	}
	//...
}
     //
	//HuffmanTree(pHT,weight)//生成哈夫曼树
	//{
	//}
	//

	//HuffmanCoding(pHC,pHT);//生成哈夫曼编码

	/*
	 *函数功能：写文件
	 *思路：在得到了文件头信息，压缩后的编码之后，将这些信息写入到文件中去，即可得到压缩后的新的文件
	 */
	int WriteFile(const char *pFilename,const HEAD sHead ,const BUFFER pBuffer,const int size){
	  // 生成文件名
		char filename[256]={0};
		strcpy(filename,pFilename):
		strcat(filename,".huf"):

		//以二进制流形式打开文件
		FILE *out = fopen(filename,"wb");
		//。。。。
		//写头文件
		fwrite(&sHead,sizeof(HEAD),1,out);

		//写压缩后的编码
		fwrite(pBuffer,sizeof(char),nSize,out);
		//关闭文件，释放文件指针
		fclose(out);
		out=NULL;

		cout<<"生成压缩文件："<<filename<<endl;
		int len = sizeof(HEAD)+strlen(Filename)+1+nSize;
		return len;

	}


}

/*
 * 函数功能：用来扫描文件和初始化文件头的信息
 * 思路：在扫描文件的时候，可以使用累加的方法，计算出原文件的大小
 */
int InitHead(const char * pFilename,HEAD &sHead)
{
   //初始化文件头
	strcpy(sHead.type,"HUF");//文件类型
	sHead.length=0;//原文件长度
	for(int i=0;i<SIZE;i++){
		sHead.weight[i]=;//权值
	}
	//以二进制流形式打开文件
	FILE*in=fopen(pFilename,"rb");
	//...
	//扫描文件，获得权重
	while((ch=fgetc(in))!=EOF){
		sHead.weight[ch]++;
		sHead.length++;
	}
	//关闭文件
	fclose(in);
	in = NULL;
	return OK;
}

/*
 * 函数功能：压缩文件
 * 思路：一边读取一边查找Huffman编码表，将每个字符用相应得编码替换掉，这样就得到了重新编码后的文件，此时
 * 新的文件比原来的文件还要大，所以对得到的编码进行压缩
 */
int Encode(const char * pFilename,const HuffmanCode pHC,char *pBuffer,const int nSize){
    //....
	//开辟缓冲区
	pBuffer=(char *)malloc(nSize * sizeof(char));
	if(!pBuffer){
	   cerr<<"开辟缓冲区失败"<<endl;
	   return ERROR;
	}
	char cd[SIZE]={0};//工作区
	int pos=0;//缓冲区指针
	int ch;
	while((ch=fgetc(in))!=EOF){
	   strcat(cd,pHC[ch]);//从HC复制编码串到cd

	   //压缩编码
	   while(strlen(cd)>=8){
	      //截取字符串左边的8个字符，编码成字节
		   pBuffer[pos++]=str2byte(cd);
		   //字符串整体左移8个字节
		   for(int i=0;i<SIZE-8;i++){
		      cd[i]=cd[i+8];
		   }
	   }
	
	}
	if(strlen(cd)>0){
	   pBuffer[pos++]=str2byte(cd);
	}
	//....
}

char Str2byte(const char *pBinStr){
   char b=0x00;
   for(int i=0;i<8;i++){
     b=b<<1;//左移1位
	 if(pBinStr[i]=='1'){
	    b=b/0x01;
	 }
   }
   return b;
}