#include<stdio.h>
#include<stdlib.h>
#include"Huffman.h"
#include"Compress.h"
#include<iostream>
using namespace std;
int main()
{
	cout<<"======Huffman文件压缩======"<<endl;
	cout<<"请输入文件名："<<endl;
	char filename[256];//文件名
	cin>>filename;
	//压缩文件
	Compress(filename);

	int weight[256]={0};
     //以二进制流形式打开文件
	FILE *in=fopen(filename,"rb");
	if(!in)
	{
		cerr<<"打开源文件失败"<<endl;
		return 0;
	}
	//扫描文件，获得权重
	int ch;
	while(ch=getc(in)!=EOF)
	{
		weight[ch]++;
	}
	//关闭文件，释放文件指针
	fclose(in);

	//显示256种字节的出现的次数
	cout<<"Byte  "<<"weight"<<endl;
	for(int i=0;i<256;i++)
	{
		printf("0x%02X   %d\n",i,weight[i]);
	}
	

	system("pause");
	return 0;
}