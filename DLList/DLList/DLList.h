#pragma once
typedef int Datatype;

//双向链表的每个结点的组成要素
typedef struct Node
{
	Datatype  data;    //数据域
	struct Node * next;//指针域，指向下一个结点
	struct Node * prior;//指针域，指向前一个结点
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


















