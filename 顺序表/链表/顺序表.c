#include<stdio.h>                                            //Ԥ����ָ��
#define MaxSize 100                                        //˳�����󳤶�
typedef int DataType;                                      //�ض�������DataType����int
#include"SeqList.h"                                         //�����Զ����ͷ�ļ�                           

//�������
void main() 
{
	SeqList myList;                                            //����ṹ�����
	int i, x;
	ListInitiate(&myList);                                  //��ʼ��
	for (i = 0; i < 10; i++) {
		ListInsert(&myList, i, i + 1);                    //��������Ԫ��
	}
	ListDelete(&myList, 4, &x);                        //ɾ������Ԫ��
	for (i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &x);                             //ȡ����Ԫ��
		printf("%d    ",x);
	}
	printf("\n");
}