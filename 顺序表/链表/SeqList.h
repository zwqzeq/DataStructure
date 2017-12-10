#include<stdio.h>
typedef int DataType;          //����DataType����int����
#define MaxSize 100            //����ȫ�ֳ���
typedef struct 
{
	DataType list[MaxSize];      //����������Ԫ�ص�����
	int size;                                //���嵱ǰ����Ԫ�ظ���
}SeqList;                                   //����SeqList�ṹ�����ͣ�������SeqListȥ�������

//��ʼ��
void ListInitiate(SeqList *L) {
	L ->size = 0;                       //����˳����г�ʼ������Ԫ�صĸ���Ϊ0
}

//��ǰ����Ԫ�صĸ���
int ListLength(SeqList L) {                 
	return L.size;                      //����˳���ǰ����Ԫ�صĸ���
}

//��������Ԫ��
int ListInsert(SeqList *L, int i, DataType x) {
	int j;
	if (L->size >= MaxSize) {  //�ж�˳����Ƿ�����
		printf("˳��������޷����룡\n");
		return 0;                         //����ʧ�ܷ���0
	}
	else if (i < 0 || i > L-> size)  //�жϲ����λ���Ƿ�Ϸ�
	{
		printf("����i���Ϸ���\n");
		return 0;                           //����ʧ�ܷ���0
	}
	else                                     //˳���δ���Ҳ����λ�úϷ�
	{
		//������ǰ�������ƣ�Ϊ������׼��
		for (j = L->size-1; j >= i; j--) //��ΪҪ�����һ������Ԫ�أ������ұߣ���ʼ�ƶ���������˳����е����ݸ���size�йأ�������j�ĳ�ֵ����˳��������һ��Ԫ�ص��±꣨�±��Ǵ�0��ʼ�ģ�
		{
			L->list[j+1] = L->list[j];  //���ν���ߵ�Ԫ�ظ�ֵ���ұߵ�Ԫ��
		}
		L->list[i] = x;                 //����Ԫ��x
		L->size++;                   //��ǰԪ�صĸ�����һ
		return 1;                       //����ɹ�����1
	}
}

//ɾ������Ԫ��
int ListDelete(SeqList *L, int i, DataType* x) {
	int j;
	if (L->size <= 0) {             //�ж��Ƿ�Ϊ�ձ�
		printf("���ݱ��ѿ������ݿ�ɾ����\n");
		return 0;                         //ɾ��ʧ�ܷ���0
	}
	else if (i<0 || i > L->size - 1) //�ж�ɾ����λ���Ƿ�Ϸ�
	{
		printf("����i���Ϸ���\n");
		return 0;                       //ɾ��ʧ�ܷ���0
	}
	else                        //˳���Ϊ����ɾ����λ�úϷ�
	{
		*x = L->list[i];                        //��Ҫɾ����Ԫ�ش����x��
		//����������������
		for (j = i; j < L->size - 1; j++) { //��ΪҪ��ɾ����Ԫ�ص���һ��Ԫ�ؿ�ʼ�����ƶ���������ɾ����λ��i�йأ�������j�ĳ�ֵ����i
			L->list[j] = L->list[j+1];
		}
		L->size--;               //����Ԫ�ظ�����һ
		return 1;                 //ɾ���ɹ�����1
	}
}

//ȡ����Ԫ��
int ListGet(SeqList L, int i, DataType *x) {
	if (i<0 || i>L.size - 1) {                                   //�ж�ȡ���ݵ�λ���Ƿ�Ϸ�
		printf("����i���Ϸ���\n");
		return 0;                                                   //ȡ����ʧ��
	}
	else                    //ȡ���ݵ�λ�úϷ�
	{
		*x = L.list[i];                //��ȡ�������ݴ����x��
		return 1;                     //ȡ���ݳɹ�
	}
}