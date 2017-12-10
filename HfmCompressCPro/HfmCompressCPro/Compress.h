#ifndef COMPRESS_H
#define COMPRESS_H

//�ļ�ͷ
struct HEAD
{
	char aType[4];//�ļ�����
	int nLength;//ԭ�ļ�����
	int aWeight[256];//Ȩֵ��ֵ
};

//������
typedef char *BUFFER;

int Compress(const char *pFilename);//ѹ���ļ�
int InitHead(const char *pFilename,HEAD &sHead);//��ʼ���ļ�ͷ
int Encode(const char *pFilename,const HCode pHC,char *pBuffer,const int nSize);//���ļ����б���ѹ��
char Str2byte(const char *pBinStr);//����010101...���ַ���������ֽ�
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer,const int nSize);//д�ļ�

#endif