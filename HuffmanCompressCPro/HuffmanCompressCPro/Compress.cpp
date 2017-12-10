#include"Compress.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

/*
 *�������ܣ������ļ�
 *˼·����Compress���������е���Encode����������ʵ���ļ����롣���������ݱ������ڴ滺������
 */
int Compress(const char * pFilename){
	//������
	//��ԭ�ļ�����ѹ������
	char *pBuffer= NULL;
	//Encode(pFilename,pHC,pBuffer,nSize);
	if(!pBuffer){
	//  return ERROR;
	}
	//...
}
     //
	//HuffmanTree(pHT,weight)//���ɹ�������
	//{
	//}
	//

	//HuffmanCoding(pHC,pHT);//���ɹ���������

	/*
	 *�������ܣ�д�ļ�
	 *˼·���ڵõ����ļ�ͷ��Ϣ��ѹ����ı���֮�󣬽���Щ��Ϣд�뵽�ļ���ȥ�����ɵõ�ѹ������µ��ļ�
	 */
	int WriteFile(const char *pFilename,const HEAD sHead ,const BUFFER pBuffer,const int size){
	  // �����ļ���
		char filename[256]={0};
		strcpy(filename,pFilename):
		strcat(filename,".huf"):

		//�Զ���������ʽ���ļ�
		FILE *out = fopen(filename,"wb");
		//��������
		//дͷ�ļ�
		fwrite(&sHead,sizeof(HEAD),1,out);

		//дѹ����ı���
		fwrite(pBuffer,sizeof(char),nSize,out);
		//�ر��ļ����ͷ��ļ�ָ��
		fclose(out);
		out=NULL;

		cout<<"����ѹ���ļ���"<<filename<<endl;
		int len = sizeof(HEAD)+strlen(Filename)+1+nSize;
		return len;

	}


}

/*
 * �������ܣ�����ɨ���ļ��ͳ�ʼ���ļ�ͷ����Ϣ
 * ˼·����ɨ���ļ���ʱ�򣬿���ʹ���ۼӵķ����������ԭ�ļ��Ĵ�С
 */
int InitHead(const char * pFilename,HEAD &sHead)
{
   //��ʼ���ļ�ͷ
	strcpy(sHead.type,"HUF");//�ļ�����
	sHead.length=0;//ԭ�ļ�����
	for(int i=0;i<SIZE;i++){
		sHead.weight[i]=;//Ȩֵ
	}
	//�Զ���������ʽ���ļ�
	FILE*in=fopen(pFilename,"rb");
	//...
	//ɨ���ļ������Ȩ��
	while((ch=fgetc(in))!=EOF){
		sHead.weight[ch]++;
		sHead.length++;
	}
	//�ر��ļ�
	fclose(in);
	in = NULL;
	return OK;
}

/*
 * �������ܣ�ѹ���ļ�
 * ˼·��һ�߶�ȡһ�߲���Huffman�������ÿ���ַ�����Ӧ�ñ����滻���������͵õ������±������ļ�����ʱ
 * �µ��ļ���ԭ�����ļ���Ҫ�����ԶԵõ��ı������ѹ��
 */
int Encode(const char * pFilename,const HuffmanCode pHC,char *pBuffer,const int nSize){
    //....
	//���ٻ�����
	pBuffer=(char *)malloc(nSize * sizeof(char));
	if(!pBuffer){
	   cerr<<"���ٻ�����ʧ��"<<endl;
	   return ERROR;
	}
	char cd[SIZE]={0};//������
	int pos=0;//������ָ��
	int ch;
	while((ch=fgetc(in))!=EOF){
	   strcat(cd,pHC[ch]);//��HC���Ʊ��봮��cd

	   //ѹ������
	   while(strlen(cd)>=8){
	      //��ȡ�ַ�����ߵ�8���ַ���������ֽ�
		   pBuffer[pos++]=str2byte(cd);
		   //�ַ�����������8���ֽ�
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
     b=b<<1;//����1λ
	 if(pBinStr[i]=='1'){
	    b=b/0x01;
	 }
   }
   return b;
}