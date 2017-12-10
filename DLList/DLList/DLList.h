#pragma once
typedef int Datatype;

//˫�������ÿ���������Ҫ��
typedef struct Node
{
	Datatype  data;    //������
	struct Node * next;//ָ����ָ����һ�����
	struct Node * prior;//ָ����ָ��ǰһ�����
}Dll;


void InitDLL(Dll **head);
int DLLInsert(Dll*head, int i, Datatype x);
int DLLLength(Dll *head);
int DLLDelete(Dll * head, int i, Datatype*x);
int DLLGet(Dll *head, int i, Datatype *x);
int DLLDestroy(Dll **head);

void ListInitiate(Dll **head);
int ListLength(Dll*head);
void Destroy(Dll **head);


















