//文件头结构体
struct HEAD
{
	char type[4];//文件类型
	int length;//原文件长度
	int weight[256];//权值数值
};


//函数声明
int Compress(const char * pFilename);
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer);
int InitHead(const char *pFilename,HEAD &sHead);
int Encode(const char * pFilename,const HuffmanCode pHC,char *pBuffer,const int nSize);
char Str2byte(const char *pBinStr);