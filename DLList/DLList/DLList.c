#include"DLList.h"
#include<stdlib.h>

//��ʼ��
void ListInitiate(Dll **head) {
	*head = (Dll *)malloc(sizeof(Dll));          //��headָ��ָ���һ����㣨������������Ϊͷ��㣩
	if (*head == NULL) {
		printf("��㴴��ʧ�ܣ�");
	}
	(*head)->prior = *head; //�˴��������˫��ѭ����������(*head)->prior ��	(*head)->next���ǵ���*head������NULL
	(*head)->next = *head;
}
/*//��ʼ��
void InitDLL(Dll **head) {
	*head = (Dll *)malloc(sizeof(Dll));          //��headָ��ָ���һ����㣨������������Ϊͷ��㣩
	if (*head == NULL) {
		printf("��㴴��ʧ�ܣ�");
	}
	(*head)->prior =NULL; //�˴��������˫��ѭ����������(*head)->prior ��	(*head)->next���ǵ���*head������NULL
	(*head)->next = NULL;
}*/
//����
int DLLInsert(Dll*head, int i, Datatype x) {
	Dll *p, *s;
	int j;
	p = head->next;//pָ��ͷ������һ��Ԫ��
	j = 0;//���pָ���λ�ã���ͷ������Ϊ-1,ͷ�����һ��Ԫ��Ϊ0���Դ����ƣ�
	while (p != head, j < i) {
		p = p->next;
		j++;  //���pָ���λ��
	}
	if (j != i) {
		printf("����λ�ò���i���Ϸ���");
		return 0;
	}
	s = (Dll*)malloc(sizeof(Dll));
	s->data = x;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}

//��������Ԫ�صĸ���
/*int DLLLength(Dll *head) {
	Dll * p;
	int size = 0;
	p = head;
	while (p->next != NULL) {
		p = p->next;
		size++;
	}
	return size;
}*/
//��ǰ����Ԫ�صĸ���
int ListLength(Dll*head) {
	Dll *p;
	int size;
	p = head;
	size = 0;
	while (p->next != head) {
		p = p->next;
		size++;
	}
	return size;
}

//ɾ��
int DLLDelete(Dll * head, int i, Datatype*x) {
	Dll *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL&&j<i - 1) {
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("ɾ��λ�ô���");
		return 0;
	}
	else {
		s = p->next;
		p->next->next->prior = p;
		p->next = p->next->next;
		free(s);
		return 1;
	}
}

//ȡ����
int DLLGet(Dll *head, int i, Datatype *x) {
	Dll *p;
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
void Destroy(Dll **head) {
	Dll  *p, *p1;
	int i, n = ListLength(*head);
	p = *head;
	for (i = 0; i <= n; i++) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
//����
/*int DLLDestroy(Dll **head) {
	Dll *p, *s;
	p = *head;
	while (p->next != NULL) {
		s = p;
		p = p->next;
		free(s);
	}
	*head = NULL;
	return 1;
}*/