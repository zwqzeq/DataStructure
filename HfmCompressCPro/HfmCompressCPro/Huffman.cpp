#include<stdio.h>
#include<malloc.h>
#include"Huffman.h"
#include<iostream>
using namespace std;

/*
 *1.��������
 *2. ��ȡԭ�ļ�
 *3. ����Huffman��
 *4.����Huffman����
 *5. ѹ������
 *6.�����ļ�
 */
//����Huffman��
int HuffmanTree(HTree &pHT, int *aWeight)
{
	//���ٿռ�
	int m=2*256-1;
	pHT=(HTree)malloc((m+1)*sizeof(HTNode));
	if(!pHT)
	{
		cerr<<"���ٻ�����ʧ��"<<endl;
		return 0;
	}
	//��ʼ����
	HTree p=pHT+1;//0�ŵ�Ԫδʹ��
	for(int i=0;i<m;i++)
	{
		p->weight=(i<256)?aWeight[i]:0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
		p++;
	}

	//����Huffman��
	for(int i=256+1;i<=m;i++)
	{
		//��һ����СԪ��
		int s1=Select(pHT,i-1);
		pHT[s1].parent=i;

		//�ڶ�����СԪ��
		int s2=Select(pHT,i-1);
		pHT[s2].parent=i;

		pHT[i].weight=pHT[s1].weight+pHT[s2].weight;
		pHT[i].lchild=s1;
		pHT[i].rchild=s2;

	}
	return 1;
}

//�������Huffman���Ȩֵ
void  PreorderTraverse(int root,HTree pHT)
{
   cout<<pHT[root].weight<<"";//���ʽ��
   if(pHT[root].lchild);//����
   {
      PreorderTraverse(pHT[root].lchild,pHT);
   }
   if(pHT[root].rchild)//�Һ���
   {
      PreorderTraverse(pHT[root].rchild,pHT);
   }
}




int Select(HTree pHT,int nSize)
{
	int minValue=0x7FFFFFFF;//��Сֵ
	int min=0;//Ԫ�����

	//�ҵ���СȨֵ��Ԫ�����
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


//����Huffman��������Huffman����
int HuffmanCoding(HCode &pHC,HTree &pHT)
{
	//��ջ�ǵݹ����Huffman������Huffman����
	char cd[256]={'\0'};//��¼����·��
	int cdlen=0;//��¼��ǰ·������
	for(int i=1;i<512;i++)
	{
		pHT[i].weight=0;//����Huffman��ʱ�����ڵ��״̬��־
	}

	int p=511;//���ڵ�
	while(p!=0)
	{
		if(pHT[p].weight==0)//����
		{
			pHT[p].weight=1;
			if(pHT[p].lchild!=0)
			{
				p=pHT[p].lchild;
				cd[cdlen++]='0';
			}
			else if(pHT[p].rchild==0)//�Ǽ�Ҷ�ӽڵ���ַ��ı���
			{
				//����������
				pHC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0';
				strcpy(pHC[p],cd);//���Ʊ���
			}
		}
		else if(pHT[p].weight==1)//����
		{
          pHT[p].weight=2;
		  if(pHT[p].rchild!=0) //�Һ���ΪҶ�ӽڵ�
			{
				p=pHT[p].rchild;
				cd[cdlen++]='1';
			}
		}
		else
		{
			//�˻ظ��ڵ㣬���볤�ȼ�1
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

//���Ժ������������ÿ��Ҷ�ӽ��ı���
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