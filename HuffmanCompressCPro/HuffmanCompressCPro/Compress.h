//�ļ�ͷ�ṹ��
struct HEAD
{
	char type[4];//�ļ�����
	int length;//ԭ�ļ�����
	int weight[256];//Ȩֵ��ֵ
};


//��������
int Compress(const char * pFilename);
int WriteFile(const char *pFilename,const HEAD sHead,const BUFFER pBuffer);
int InitHead(const char *pFilename,HEAD &sHead);
int Encode(const char * pFilename,const HuffmanCode pHC,char *pBuffer,const int nSize);
char Str2byte(const char *pBinStr);