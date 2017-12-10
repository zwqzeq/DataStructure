#include "Huffman.h"
#include<iostream>
using namespace std;
int HuffmanTree(HuffmanTree &pHT,int *w,int n){

	return 0;
}

//查找树节点数组中权值最小的结点
int Select(HuffmanTree pHT,int nSize) {
     int minValue=0x7FFFFFFF;//最小值
	 int min=0;//元素序号
	 int i;
	 //找到最小权值的元素序号
	 for(i=1;i<nSize;i++){
		 if(pHT[i].parent==0&&pHT[i].weight<minValue){
		       minValue = pHT[i].weight;
			   min=i;		 
		 }
	 
	 }

	 return min;
}


//测试函数
void TestHuffmanTreeN(int root,HuffmanTree pHT){
     cout<<pHT[root].weight<<"";
	 if(pHT[root].lchild!=0){
		 TestHuffmanTreeN(pHT[root].lchild,pHT);
	 }
	 if(pHT[root].rchild!=0){
	     TestHufTreeN(pHT[root].rchild,pHT);
	 }
}

//测试输出每个叶子结点的编码
void TestHufCode(int root,HuffmanTree pHT,HuffmanCode pHC){
	if(pHT[root].lchild==0 && pHT[root].rchild==0){
	    printf("0x%02X%s\n",i,root-1,pHC[root-1]);
	}
	if(pHT[root].lchild){//访问左孩子
	   TestHufCode(pHT[root].lchild,pHT,pHC);
	}
	if(pHT[root].rchild){//访问右孩子
        TestHufCode(pHT[root].rchild,pHT,pHC);
	}

}