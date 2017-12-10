#include <stdio.h>                                    
#include <malloc.h>                                          //Ԥ����ָ��
typedef int DataType;                                         //����DataType���ʹ���int����

//����ṹ�壬����ΪNode������ΪSLNode��SLNode���ʹ�����struct Node����
typedef struct Node {
	DataType data;                                               //���������ڴ�ſ�������Ԫ��
	struct Node* next;                                          //ָ���򣬴����һ�������׵�ַ
}SLNode;

//��ʼ��
//��Ϊ�ú�����head�ĸı�Ҫ��������������������Ҫ��˫ָ��
void ListInitiate(SLNode **head) {                     //����head��һ��ָ�����ָ����һ��ָ�������ע��headָ������ָ�����������ָ��SLNode���͵ģ�������ǰ��������ʵ��Ӧ����һ����ַ������SLNode * ���͵ı����ĵ�ַ
	*head = (SLNode*)malloc(sizeof(SLNode));  //����ͷ��㣬��headָʾ���ַ
	(*head)->next = NULL;                                  //ͷָ���ָ�����ý������NULL
}

//����
int ListInsert(SLNode *head, int i, DataType x) {    //����head��һ��ָ�����ָ��һ��SLNode���ͱ���    ������ǰ��������ʵ����һ����ַ������SLNode���ͣ��ṹ�����ͣ������ĵ�ַ
	//�ڴ�ͷ���ĵ������i�����ǰ����һ���������Ԫ��x�Ľ�㣬����Ҫ�ҵ���i-1����㲢��pָֻʾ
	SLNode *p, *q;  
	int j;                                                                 
	p = head;                                                
	j = -1;     //p��ͷָ�뿪ʼ����    ��ͷ������ż�Ϊ-1����һ���������Ԫ�صĽ���Ϊ0��Ȼ����������
	while (p->next != NULL && j < i - 1) {      //p->next != NULL�жϱ�ָ֤����ָ�Ľ����� ��j < i - 1��֤������ָ��pָ���i-1����㣨��Ҫɾ���Ľ������һ����㣩
		//������pָ���i-1�����
		p = p->next;                                           //��p����һλ
		j++;                                                          
	}
	if (j != i - 1) {
		printf("����Ԫ��λ�ò�������");
		return 0;                                                  //����ʧ�ܷ���0
	}

	//�����λ����ȷʱִ��
	q = (SLNode *)malloc(sizeof(SLNode));                        //����һ����㣬qָ��ý�㣬��������ΪҪ����Ľ��
	q->data = x;                   //��Ҫ����Ľ���������ֵ

	//��������˳���ܽ������������p->next = q����ִ��q->next = p->nextʱ�� p->next��ֵ����q����ʱ�൱��q->next = q;������û��ʵ�ֲ������Ҫ��
	q->next = p->next;       
	p->next = q;

	return 1;  //����ɹ�����1
}

//ɾ��
int ListDelete(SLNode *head, int i, DataType *x) {
	SLNode *p, *s;
	int j;
	p = head;               //head��ָ�������p����ָ��ͷָ��headָ���ͷ���
	j = -1;
	while (p->next  != NULL  &&  p->next->next  !=  NULL && j < i - 1) {//p->next != NULL��p->next->next != ��֤Ҫɾ���Ľ�����ߺ��ұ߶��н�� ��j < i - 1��֤������ָ��pָ���i-1����㣨��Ҫɾ���Ľ������һ����㣩
		p = p->next;
		j++;
	}
	if (j != i - 1) {//�˳�ѭ��ʱ�ж�p�Ƿ��ƶ���ָ���i-1�����
		printf("ɾ��Ԫ��λ�ò�������");
		return 0;//ɾ��ʧ�ܷ���0
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                           //�ͷ�s���
	return 1;//ɾ���ɹ�����1
}

//��ǰ����Ԫ�ظ���                        
int ListLength(SLNode *head) {
	SLNode *p = head;                                       //pָ��ͷ���
	int size = 0;                                                   //����Ԫ�ظ���Ϊ0

	while (p->next != NULL) {           //�ж�pָ��Ľ�����һ������Ƿ����
		p = p->next;                          //p�����ƶ�һλ
		size++;                                  //������һ
	}
	return size; //��������Ԫ�ظ���
}


//ȡ����Ԫ��
int ListGet(SLNode *head, int i, DataType *x) {
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL&&j < i) {//p->next != NULL��֤pָ��Ľ�����һ����������������p = p->next;  j < i��֤p�����ƶ���ҪȡԪ�ص��Ǹ���㣨����i����㣩
		p = p->next;
		j++;
	}
	if (j != i) {//�ж�p�Ƿ��ƶ���ָ���i����㣬����ҪȡԪ�ص��Ǹ���㣩
		printf("ȡԪ��λ�ò�����");
			return 0;//ȡԪ��ʧ�ܷ���0
	}
	*x = p->data;                          //  ��ȡ����Ԫ�ش�ŵ�x��
	return 1;//ȡԪ�سɹ�����0
}

//����������
//��Ϊhead�ĸı�Ҫ����������������������˫ָ��
void Destroy(SLNode **head) {
	SLNode *p, *p1;
	p = *head;                                   //pָ��ͷ���
	while (p != NULL) {                     //�ж�pָ��Ľ���Ƿ����
		p1 = p;                                    //��p1ָ��Ҫ�ͷŵ����
		p = p->next;                           //�����ƶ�p���
		free(p1);                                  //�ͷ�p1ָ��Ľ��
	}
	*head = NULL;                           //ѭ������ʱͷ����ÿ�
}