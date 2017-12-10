
#include<stdio.h>
typedef int Datatype;

//�����ÿ�����Ĺ���
typedef struct Node
{
	Datatype data;              //������
	struct Node* next;          //ָ����
}Sll;

//��ʼ��
void InitSLList(Sll**head) {
	/*��Ϊ��ʼ������ǰ��ͷָ�����headû�о���ĵ�ֵַ���ڳ�ʼ������ʱ��ͷָ�����head�ŵõ��˾����ֵ���������ֵַҪ���ظ����ú���
	���ԣ�ͷָ��headӦ�����Ϊָ���ָ�����ͣ������ʱhead���Ϊָ�����ͣ���ô���ú������޷��õ��ڳ�ʼ�������б���ֵ��ͷָ�����head����ֵ
	*/
	*head = (Sll*)malloc(sizeof(Sll));
	if (*head == NULL) {
		printf("�������ʧ�ܣ�");
	}
	(*head)->next=NULL;//ͷ���ָ�����ÿ�
}

//����
int SLListInsert(Sll*head,int i,Datatype x) {
	Sll *p, *q;
	int j = -1;             //j�������pָ��ָ��Ľ�����ţ�ͷ�����ż�Ϊ-1
	p = head;            //p��ָ��ͷ��㣨���Դ�ʱj=-1����Ȼ��p�𽥺���( j ������)
	if (head == NULL) {
		printf("�������ڣ�"); 
		return 0;
	}
	//�ƶ�pָ�뵽Ҫ����λ�õ�ǰһ�����(����i-1�����)
	while (p->next != NULL&&j < i - 1) {//ֻ�е�p->next != NULLʱ�����������������
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("����Ԫ��λ�ò�������");
	}
	else {
		q = (Sll*)malloc(sizeof(Sll));
		q->data = x;
		q->next = p->next;
		p->next = q;
		return 1;
	}
}

//������Ԫ�ظ���
int SLListLength(Sll*head) {
	int size = 0;
	Sll *p;
	p = head;
	while (p->next != NULL) {       
		p = p->next;
		size++;
	}
	return size;
}
//ɾ��
int SLListDelete(Sll*head, int i, Datatype *x) {
	Sll*p, *s;
	int j = -1;
	p = head;
	if (head == NULL) {
		printf("�������ڲ���ɾ����");
	}
	//�ƶ�pָ�뵽Ҫɾ���Ľ���ǰһ�����
	while (p->next != NULL&&p->next->next != NULL&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("ɾ��λ�ò�������");
		return 0;
	}
	s = p->next;//sָ��Ҫɾ���Ľ��
	*x = s->data;
	p->next = p->next->next;
	free(s);//�ͷ�sָ��Ľ�㣨��Ҫɾ���Ľ�㣩
	return 1;
}

//ȡ����
int SSListGet(Sll *head,int i,Datatype *x) 
{
	Sll *p;
	int j;
	p = head;
	j = -1;  //ͷ������Ϊ-1
	//�ƶ�pָ�뵽Ҫȡ���ݵĽ�㼴��i�����
	while (p->next != NULL&&j < i) {
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("ȡ����λ��i����");
		return 0;
	}
	*x = p->data;
	return 1;
}

//���ٵ�����
void SLListDestroy(Sll**head) {
	Sll *p,*q;
	p = *head;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);//��ͷ��㿪ʼ��һ�ͷŽ��
	}
	*head = NULL;
}


void main(void) {
	int i=0;
	Datatype x=0;
	Sll *head;//����ͷָ���������ʱheadû�б���ֵ��head��ָ���κν��
	InitSLList(&head);//��ʼ��������ͷ��㣬ʹheadָ����
	for (i = 0; i < 10; i++) {
		SLListInsert(head, i, i + 1);
	}
	SLListDelete(head, 4, &x);
	for (i = 0; i < SLListLength(head); i++) {
		SSListGet(head, i, &x);
		printf("%d    ", x);
	}
	SLListDestroy(&head);
	printf("\n");
}