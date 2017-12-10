#include "Huffman.h"
#include<iostream>
using namespace std;
int HuffmanTree(HuffmanTree &pHT,int *w,int n){

	return 0;
}

//�������ڵ�������Ȩֵ��С�Ľ��
int Select(HuffmanTree pHT,int nSize) {
     int minValue=0x7FFFFFFF;//��Сֵ
	 int min=0;//Ԫ�����
	 int i;
	 //�ҵ���СȨֵ��Ԫ�����
	 for(i=1;i<nSize;i++){
		 if(pHT[i].parent==0&&pHT[i].weight<minValue){
		       minValue = pHT[i].weight;
			   min=i;		 
		 }
	 
	 }

	 return min;
}


//���Ժ���
void TestHuffmanTreeN(int root,HuffmanTree pHT){
     cout<<pHT[root].weight<<"";
	 if(pHT[root].lchild!=0){
		 TestHuffmanTreeN(pHT[root].lchild,pHT);
	 }
	 if(pHT[root].rchild!=0){
	     TestHufTreeN(pHT[root].rchild,pHT);
	 }
}

//�������ÿ��Ҷ�ӽ��ı���
void TestHufCode(int root,HuffmanTree pHT,HuffmanCode pHC){
	if(pHT[root].lchild==0 && pHT[root].rchild==0){
	    printf("0x%02X%s\n",i,root-1,pHC[root-1]);
	}
	if(pHT[root].lchild){//��������
	   TestHufCode(pHT[root].lchild,pHT,pHC);
	}
	if(pHT[root].rchild){//�����Һ���
        TestHufCode(pHT[root].rchild,pHT,pHC);
	}

}