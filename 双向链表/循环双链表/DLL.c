#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct Node {
	DataType data;                  //ʹ�õ�����Ԫ��
	struct Node *next;              //ָ����һ�����
	struct Node *prior;             //ָ����һ�����
}DLNode;                         //����ṹ������ΪDLNode

								 //��ʼ��
void ListInitiate(DLNode **head) {
	*head = (DLNode *)malloc(sizeof(DLNode));            //����ͷ���
	(*head)->prior = *head;                             //����ǰ��ָ��ѭ������
	(*head)->next = *head;                              //���ɺ��ָ��ѭ������
}

//��������Ԫ��
int ListInsert(DLNode *head, int i, DataType x) {
	DLNode *p, *s;
	int j;
	p = head->next;
	j = 0;
	while (p != head &&j < i) {
		p = p->next;
		j++;
	}

	if (j != i) {
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	s = (DLNode*)malloc(sizeof(DLNode));
	s->data = x;
	s->prior = p->prior;            //���벽��1
	p->prior->next = s;             //���벽��2
	s->next = p;                    //���벽��3
	p->prior = s;                   //���벽��4
	return 1;
}

//ɾ������Ԫ��
int ListDelete(DLNode * head, int i, DataType *x) {
	DLNode *p;
	int j;
	p = head->next;
	j = 0;
	while (p->next != head&&j < i) {
		p = p->next;
		j++;
	}
		if (j != i) {
			printf("ɾ��Ԫ��λ�ò�������\n");
			return 0;
		}
		*x = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return 1;
	}


//��ǰ����Ԫ�صĸ���
int ListLength(DLNode*head) {
	DLNode *p = head;
	int size = 0;
	while (p->next != head) {
		p = p->next;
		size++;
	}
	return size;
}

//�����ڴ�ռ�
void Destroy(DLNode **head) {
	DLNode *p, *p1;
	int i, n = ListLength(*head);
	p = *head;
	for (i = 0; i <= n; i++) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
//ȡ����
int DLLGet(DLNode *head, int i, DataType *x) {
	DLNode *p;
	int j = -1;//���ָ��p��λ��
	p = head;
	while (p->next != NULL&&j<i) {
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("ȡԪ��λ�ô���");
		return 0;
	}
	else {
		*x = p->data;
		return 1;
	}
}


void main(void) {
	DLNode *head;
	DataType x = 0;
	int i = 0;
	ListInitiate(&head);
	for (i = 0; i < 10; i++) {
		ListInsert(head, i, i + 1);
	}
	ListDelete(head, 4, &x);
	for (i = 0; i < ListLength(head); i++) {
		DLLGet(head, i, &x);
		printf("%d    ", x);
	}
	printf("\n");
	Destroy(&head);
}