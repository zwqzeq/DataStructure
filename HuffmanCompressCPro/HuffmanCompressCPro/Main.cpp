#include<iostream>//������cout��cin �Ⱥ���
#include<stdlib.h>//���а�����fopen,fclose�Ⱥ���
#include "Huffman.h"
#include"Compress.h"
using namespace std;
int main(){
	cout<<"=======Huffman�ļ�ѹ��========="<<endl;
	cout<<"�������ļ�����";
	char ch;
	char filename[256];
	int weight[256]={0};
	cin>>filename;//�����ļ���

	//�Զ�������ʽ���ļ�
	FILE*in=fopen(filename,"rb");
	



	//ɨ���ļ����Ȩ��
	while((ch=getc(in))!=EOF){
		weight[ch]++;
	}
		//�ر��ļ�
		fclose(in);

		//��ʾ256���ֽڳ��ֵĴ���
		cout<<"Byte"<<"Weight"<<endl;
		for(int i=0;i<256;i++){
			printf("0x%02X%d\n",i,weight[i]);
		}

	return 0;
}