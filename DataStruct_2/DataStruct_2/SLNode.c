#include "SLNode.h"

//初始化顺序表
void ListInitiate(SLNode **head)
{
	*head = (SLNode *)malloc(sizeof(SLNode));//申请头结点，由head指向其地址
	(*head)->next = NULL;//置结束标记NULL
}
//求当前数据元素个数
int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;
	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}
//插入数据元素
int ListInsert(SLNode *head, int i, DataType x)
{
	SLNode *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1)//最终让p指向第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("插入元素位置参数错误！\n");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));//生成新结点
	q->data = x;//新结点数据域赋值
	q->next = p->next;//插入步骤1
	p->next = q;//插入步骤2
	return 1;
}

//删除数据元素个数
//删除带头结点单链表head的第i个结点
//被删除结点的数据域值由x带回，成功返回1，失败0
int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i -1)
	{
		p = p->next;//循环结束时p指向i-1个结点
		j++;
	}
	if (j != i - 1)
	{
		printf("删除元素位置参数错误！\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);
	return 1;
}
//取数据元素
int ListGet(SLNode *head, int i, DataType *x)
{
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("去元素参数位置错误！\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
//撤销单链表
void Destory(SLNode **head)
{
	SLNode *p, *p1;
	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}