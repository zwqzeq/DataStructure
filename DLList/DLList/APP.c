#include<stdio.h>
#include<malloc.h>
#include"DLList.h"

//�������
void main(void) {
	Dll *head;//����ͷָ�����
	Datatype x=0;
	int i = 0;
	ListInitiate(&head);      //��ʼ��
	for (i = 0; i < 10; i++) {
		DLLInsert(head,i,i+1);//����
	}
	DLLDelete(head, 8, &x);//ɾ��
	for (i = 0; i < ListLength(head); i++) {
		DLLGet(head, i, &x);//��ȡ
		printf("%d    ", x);
	}
	printf("\n");
	//DLLDestroy(&head);
	void Destroy(Dll **head);
}

