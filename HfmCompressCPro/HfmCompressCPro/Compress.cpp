#include"Huffman.h"
#include"Compress.h"
#include<iostream>
#define SIZE 256
using namespace std;

/*
*�Զ��������ķ�ʽֻ����ԭ�ļ������ֽڶ�ȡ�ļ��е����ݣ�ʹ��Huffman�����ԭ�ļ��е��ֽ����±��� �����ѹ������ļ����ݣ�������һ��char������
*1.����ѹ�������ֽ������õ���Huffman����֮����Ҫ��������������ļ���Ҫ�Ŀռ��С�����㷽�����ȼ���ÿ���ַ���Ȩֵ���Ը��ַ�����ĳ��ȣ�
*��������Ϊͬһ���ַ��ڱ����ļ�����ռ�Ĵ�С����256��������ֵ��Ӽ�Ϊ���������ļ�����Ҫ�Ŀռ��С������8��Ϊ���ֽ���
*/
int Compress(const char *pFilename)
{
    int nSize=0;
	//��ȡ�ļ�����ʼ���ļ�ͷ
	HEAD sHead;
	if(InitHead(pFilename,sHead)==0)
	{
		return 0;
	}
	cout<<sHead.nLength<<"�ֽ�"<<endl;

	//����Huffman��
	HTree pHT=NULL;
	HuffmanTree(pHT,sHead.aWeight);
	if(!pHT)
	{
		return 0;
	}

	//����Huffman�����
	HCode pHC=NULL;
	HuffmanCoding(pHC,pHT);
	free(pHT);  //�ͷ�Huffman���ռ�
	if(!pHC)
	{
		return 0;
	}

	//������뻺������С
	for(int i=0;i<256;i++)
	{
		nSize+=sHead.aWeight[i]*strlen(pHC[i]); 
	}
	nSize=(nSize%8)?nSize/8+1:nSize/8;

	//��ԭ�ļ�����ѹ������
	char *pBuffer=NULL;
	Encode(pFilename,pHC,pBuffer,nSize);
	//free(pHC);//�ͷ�Huffman�����
	if(!pBuffer)
	{
		return 0;
	}

	//���ѹ���ļ�
	int len=WriteFile(pFilename,sHead,pBuffer,nSize);
	//free(pBuffer);
	if(len<0)
	{
		return 0;
	}
	cout<<len<<"�ֽ�"<<endl;
	cout<<"ѹ�����ʣ�"<<(double)len/(double)sHead.nLength*100<<"%"<<endl;
}

/*һ�߶�ȡһ�߲���Huffman�������ÿ���ַ�����Ӧ�ı����滻���������͵õ������±������ļ���
 *��ʱ�ᷢ���µ��ļ���ԭ���Ļ���������Ҫ������ĵ��ı������ѹ��
 Encode�����룬���룩
 */
int Encode(const char *pFilename,const HCode pHC,char *pBuffer,const int nSize)
{
	//�Զ���������ʽ���ļ�
	FILE *in=fopen(pFilename,"rb");
	if(!in)
	{
		cerr<<"��Դ�ļ�ʧ��"<<endl;
		return 0;
	}

	//���ٻ�����
	pBuffer=(char *)malloc(nSize*sizeof(char));
	if(!pBuffer)
	{
		cerr<<"���ٻ�����ʧ��"<<endl;
		return 0;
	}

	//ɨ���ļ�������Huffman�����������ѹ����ѹ������ݴ浽��������
	char cd[SIZE]={0};//������
	int pos=0;//������ָ��
	int ch;
	//ɨ���ļ�������Huffman�����������ѹ����ѹ������ݴ浽������
	while(ch=fgetc(in)!=EOF)
	{
		strcat(cd,pHC[ch]);//��HC���Ʊ��봮��cd
		while(strlen(cd)>=8)
		{
		    //��ȡ�ַ�����ߵ�8���ַ���������ֽ�
			pBuffer[pos++]=Str2byte(cd);
			//�ַ�����������8�ֽ�
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
*ɨ���ļ��ͳ�ʼ���ļ�ͷ
*/
int InitHead(const char *pFilename,HEAD &sHead)
{
	//��ʼ���ļ�ͷ
	strcpy(sHead.aType,"HUF");//�ļ�����
	sHead.nLength=0;//ԭ�ļ�����
	for(int i=0;i<SIZE;i++)
	{
		sHead.aWeight[i]=0;//Ȩֵ
	}
	//�Զ���������ʽ���ļ�
	FILE *in=fopen(pFilename,"rb");
	if(!in)
	{
		cerr<<"��ʼ���ļ�ͷʧ�ܣ�"<<endl;
		return 0;
	}

	//ɨ���ļ������Ȩ��
	int ch;
	while(ch=fgetc(in)!=EOF)
	{
		sHead.aWeight[ch]++;
		sHead.nLength++;
	}
	//�ر��ļ����ͷ��ļ�ָ��
	fclose(in);
	in=NULL;
	return sHead.nLength;
}

/*�ַ�������������ַ��������ʽ����ģ����±��������ݽ���һ���ܳ����ַ���������Str2byte��˰������01010101�ַ���ת��Ϊ�ֽڣ����ܵõ����յı���*/
char Str2byte(const char *pBinStr)
{
	char b=0x00;
	for(int i=0;i<8;i++)
	{
		b = b<<1;//����һλ
		if(pBinStr[i]=='1')
		{
			b=b|0x01;
		}
	}
	return b;
}

/*д�ļ�
*����һ���µ��ļ����ļ���Ϊ��ԭ�ļ�����+.huf��,��ѹ���������д���ļ�
*Ϊ�˱�֤ѹ����������ܱ�������ȷ��ѹ�����뽫��صĽ�ѹ������д�뵽�ļ���ȥ������Ľ������ʵ���Ͼ�
*��Ȩֵ����weight����ѹ��ʱֻҪ����Ȩֵ��Ϣ����Huffman���Ϳ��Ը��ݱ�����н�ѹ��
*Ϊ����֤��ѹ�����ļ��Ƿ���ȷ������Ҫ���ļ��Ĵ�С�����ļ���ȥ��ͬʱҲ���Խ��ļ������ʹ������ļ��������ж��Ƿ�����Ҫ��ѹ���ļ�������Ĭ�ϵ���HUF����
*��ˣ�ѹ���ļ�����������������ɣ�1.�ļ�ͷ�������ļ����ͣ��ļ����ȣ�Ȩֵ���飩2. ѹ�����ݣ�ѹ��ԭ�ļ���õ�������
*/
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer,const int nSize)
{
	//�����ļ���
	char filename[256]={0};
	strcpy(filename,pFilename);
	strcat(filename,".huf");

	//�Զ���������ʽ���ļ�
	FILE *out=fopen(filename,"wb");


	//д�ļ�
	fwrite(&sHead,sizeof(HEAD),1,out);

	//дѹ����ı���
	fwrite(pBuffer,sizeof(char),nSize,out);

	//�ر��ļ����ͷ��ļ�ָ��
	fclose(out);
	out=NULL;

	cout<<"����ѹ���ļ���"<<filename<<endl;
	int len=sizeof(HEAD)+strlen(pFilename)+1+nSize;
	return len;

}