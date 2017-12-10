#include<stdio.h>            //Ԥ����ָ��
#define MaxLength 100       //�궨��

typedef int Datatype;


//����һ��˳���
typedef struct
{
	Datatype list[MaxLength];    //����  
	int size;              //��ǰ����       
}Seq;

//��ȡ��ǰ����Ԫ�ظ���
int ListLength(Seq L) {
	return L.size;
}

//��ʼ��
int InitList(Seq *L) {
	L->size = 0;
}

//����
int ListInsert(Seq *L,int i,Datatype x) {
	int j;
	if (L->size >= MaxLength) {
		printf("˳��������޷����룡");
		return 0;
	} 
	else if (i<0 || i>L->size) {//��size��Ԫ��֮�����
		printf("�����λ�ò��Ϸ�!");
		return 0; 
	}
	else {
		for (j = L->size; j > i; j--) {
			L->list[j] = L->list[j - 1];
		}
			L->list[i] = x;
			L->size ++;
			return 1;
	}
}


//ɾ��
int ListDelete(Seq*L, int i,Datatype *x) {
	int j;
	if (L->size <= 0) {
		printf("˳����ѿ��޷�ɾ����");
		return 0;
	} 
	else if (i<0 || i>L->size - 1) {
		printf("ɾ��λ��i���Ϸ���");
		return 0;
	}
	else {
		*x = L->list[i];
		for (j = i+1; j < L->size; j++) {
			L->list[j - 1] = L->list[j];
		}
		L->size--;
		return 1;
	}

}

//ȡ����
int  ListGet(Seq L, int i, Datatype*x) {
	if (L.size <= 0) {
		printf("˳���Ϊ�գ��޷�ȡ���ݣ�");
		return 0;
	}
	else if (i < 0 || i>L.size - 1) {
		printf("����i���Ϸ���");
	}
	else {
		*x = L.list[i];
		return 1;
	}
}

int main() {
	Seq myseq;
	Datatype x=0;
	int i;
	InitList(&myseq);
	for (i = 0; i < 10; i++) {
		ListInsert(&myseq, i, i + 1);
	}
	ListDelete(&myseq, 5, &x);
	ListDelete(&myseq, 5, &x);
	for (i = 0; i < ListLength(myseq); i++) {
		ListGet(myseq, i, &x);
		printf("%d   ", x);
	}
	printf("\n");
	return 0;
}