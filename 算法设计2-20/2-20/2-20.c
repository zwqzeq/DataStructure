#include<stdio.h>
#include<malloc.h>
typedef int DataType;

//���嵥������ÿ�����
typedef struct {
	DataType data;
	struct Node *next;
}SLNode;

//��ʼ��������
void ListInitiate(SLNode **head) {
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}

//��������Ԫ��
int ListInsert(SLNode *head, int i, DataType x) {
	SLNode *p;              //pָ��Ҫ�����λ�õ�ǰһ����㼴i-1�����
    SLNode *q;              //qָ��Ҫ����Ľ��
	int j = -1;
	p = head;
	
	while ( p -> next != NULL && j < i - 1) {
		//������pָ���i-1�����
		p = p->next;
		j++;
	}
	//�ж�p�Ƿ�ָ���i-1�����
	if (j != i - 1) {
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	
	q = (SLNode*)malloc(sizeof(SLNode));        //�����½��
	q->data = x;                               //�½��������ֵ
	q->next = p->next;                         //���벽��1��ע��1��2˳���ܷ�
	p->next = q;                               //���벽��2
	return 1;                                //����ɹ��򷵻�1

}

//��ǰ����Ԫ�صĸ���
int ListLength(SLNode *head) {
	SLNode *p = head;                 //pָ��ͷ���
	int size = 0;                    //size��ʼΪ0
	while (p->next != NULL) {        //ѭ������
		p = p->next;
		size++;
	}
	return size;
}

//ȡԪ��
int ListGet(SLNode * head, int i, DataType *x) {
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {
		//ָ������ƶ���ָ���i�����
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("ȡ����Ԫ��λ�ò�������\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
//����Ԫ�صĵ���
int ListReverse(SLNode * head) {
	SLNode *p,*q;
	int i;
	p = head;    //pָ��ͷ���
	q = head;
	ListLength(head);
	while (q->next != NULL) {
		//ʹq�ƶ���ָ��β���
		q = q->next;
	}
	for (i = 0; i < ListLength(head) / 2; i++) {
		p->data = q->data;
		p = p->next;

	}


}

int main() {
	SLNode *head;          //����ͷָ�����
	int i, x;              
	ListInitiate(&head);   //��ʼ��
	for(i = 0; i < 10; i++) {
		ListInsert(head,i,i+1);     //����Ԫ��
	}
	for (i = 0; i < ListLength(head); i++) {
		ListGet(head, i, &x);
		printf("%d   ", x);
	}
	return 0;
}