#include<stdio.h>
#include<malloc.h>
#include"Huffman.h"
#include<iostream>
using namespace std;

/*
 *1.创建工程
 *2. 读取原文件
 *3. 生成Huffman树
 *4.生成Huffman编码
 *5. 压缩编码
 *6.保存文件
 */
//生成Huffman树
int HuffmanTree(HTree &pHT, int *aWeight)
{
	//开辟空间
	int m=2*256-1;
	pHT=(HTree)malloc((m+1)*sizeof(HTNode));
	if(!pHT)
	{
		cerr<<"开辟缓冲区失败"<<endl;
		return 0;
	}
	//初始化树
	HTree p=pHT+1;//0号单元未使用
	for(int i=0;i<m;i++)
	{
		p->weight=(i<256)?aWeight[i]:0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
		p++;
	}

	//创建Huffman树
	for(int i=256+1;i<=m;i++)
	{
		//第一个最小元素
		int s1=Select(pHT,i-1);
		pHT[s1].parent=i;

		//第二个最小元素
		int s2=Select(pHT,i-1);
		pHT[s2].parent=i;

		pHT[i].weight=pHT[s1].weight+pHT[s2].weight;
		pHT[i].lchild=s1;
		pHT[i].rchild=s2;

	}
	return 1;
}

//先序遍历Huffman输出权值
void  PreorderTraverse(int root,HTree pHT)
{
   cout<<pHT[root].weight<<"";//访问结点
   if(pHT[root].lchild);//左孩子
   {
      PreorderTraverse(pHT[root].lchild,pHT);
   }
   if(pHT[root].rchild)//右孩子
   {
      PreorderTraverse(pHT[root].rchild,pHT);
   }
}




int Select(HTree pHT,int nSize)
{
	int minValue=0x7FFFFFFF;//最小值
	int min=0;//元素序号

	//找到最小权值的元素序号
	for(int i=1;i<=nSize;i++)
	{
		if(pHT[i].parent==0&&pHT[i].weight<minValue)
		{
			minValue=pHT[i].weight;
			min=i;
		}
	}
	return min;
}


//遍历Huffman树，生成Huffman编码
int HuffmanCoding(HCode &pHC,HTree &pHT)
{
	//无栈非递归遍历Huffman树，求Huffman编码
	char cd[256]={'\0'};//记录访问路径
	int cdlen=0;//记录当前路径长度
	for(int i=1;i<512;i++)
	{
		pHT[i].weight=0;//遍历Huffman树时用作节点的状态标志
	}

	int p=511;//根节点
	while(p!=0)
	{
		if(pHT[p].weight==0)//向左
		{
			pHT[p].weight=1;
			if(pHT[p].lchild!=0)
			{
				p=pHT[p].lchild;
				cd[cdlen++]='0';
			}
			else if(pHT[p].rchild==0)//登记叶子节点的字符的编码
			{
				//这里有问题
				pHC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0';
				strcpy(pHC[p],cd);//复制编码
			}
		}
		else if(pHT[p].weight==1)//向右
		{
          pHT[p].weight=2;
		  if(pHT[p].rchild!=0) //右孩子为叶子节点
			{
				p=pHT[p].rchild;
				cd[cdlen++]='1';
			}
		}
		else
		{
			//退回父节点，编码长度减1
			pHT[p].weight=0;
			p=pHT[p].parent;
			--cdlen;
		}
     }
	return 1;
}

void TestHufTreeN(int root,HTree pHT)
{
	cout<<pHT[root].weight<<"";
	if(pHT[root].lchild!=0){
	  TestHufTreeN(pHT[root].lchild,pHT);
	}
	if(pHT[root].rchild!=0){
	   TestHufTreeN(pHT[root].rchild,pHT);
	}
}

//测试函数，测试输出每个叶子结点的编码
void TestHufCode(int root,HTree pHT,HTree pHC){
	if(pHT[root].lchild==0&&pHT[root].rchild==0){
	//   printf("0x%02X%s\n",i,root-1,pHC[root-1]);
	}
	if(pHT[root].lchild)
	{
	  TestHufCode(pHT[root].lchild,pHT,pHC);

	}
	if(pHT[root].rchild){
		TestHufCode(pHT[root].rchild,pHT,pHC);
	}
}