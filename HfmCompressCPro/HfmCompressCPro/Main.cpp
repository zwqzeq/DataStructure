#include<stdio.h>
#include<stdlib.h>
#include"Huffman.h"
#include"Compress.h"
#include<iostream>
using namespace std;
int main()
{
	cout<<"======Huffman�ļ�ѹ��======"<<endl;
	cout<<"�������ļ�����"<<endl;
	char filename[256];//�ļ���
	cin>>filename;
	//ѹ���ļ�
	Compress(filename);

	int weight[256]={0};
     //�Զ���������ʽ���ļ�
	FILE *in=fopen(filename,"rb");
	if(!in)
	{
		cerr<<"��Դ�ļ�ʧ��"<<endl;
		return 0;
	}
	//ɨ���ļ������Ȩ��
	int ch;
	while(ch=getc(in)!=EOF)
	{
		weight[ch]++;
	}
	//�ر��ļ����ͷ��ļ�ָ��
	fclose(in);

	//��ʾ256���ֽڵĳ��ֵĴ���
	cout<<"Byte  "<<"weight"<<endl;
	for(int i=0;i<256;i++)
	{
		printf("0x%02X   %d\n",i,weight[i]);
	}
	

	system("pause");
	return 0;
}