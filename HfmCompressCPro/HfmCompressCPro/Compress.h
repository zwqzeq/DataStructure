#ifndef COMPRESS_H
#define COMPRESS_H

//文件头
struct HEAD
{
	char aType[4];//文件类型
	int nLength;//原文件长度
	int aWeight[256];//权值数值
};

//缓冲区
typedef char *BUFFER;

int Compress(const char *pFilename);//压缩文件
int InitHead(const char *pFilename,HEAD &sHead);//初始化文件头
int Encode(const char *pFilename,const HCode pHC,char *pBuffer,const int nSize);//对文件进行编码压缩
char Str2byte(const char *pBinStr);//将“010101...”字符串编码成字节
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer,const int nSize);//写文件

#endif