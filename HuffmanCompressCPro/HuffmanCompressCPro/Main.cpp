#include<iostream>//包含了cout，cin 等函数
#include<stdlib.h>//其中包含了fopen,fclose等函数
#include "Huffman.h"
#include"Compress.h"
using namespace std;
int main(){
	cout<<"=======Huffman文件压缩========="<<endl;
	cout<<"请输入文件名：";
	char ch;
	char filename[256];
	int weight[256]={0};
	cin>>filename;//输入文件名

	//以二进制形式打开文件
	FILE*in=fopen(filename,"rb");
	



	//扫描文件获得权重
	while((ch=getc(in))!=EOF){
		weight[ch]++;
	}
		//关闭文件
		fclose(in);

		//显示256种字节出现的次数
		cout<<"Byte"<<"Weight"<<endl;
		for(int i=0;i<256;i++){
			printf("0x%02X%d\n",i,weight[i]);
		}

	return 0;
}