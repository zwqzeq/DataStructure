#include"DLList.h"
#include<stdlib.h>

//初始化
void ListInitiate(Dll **head) {
	*head = (Dll *)malloc(sizeof(Dll));          //让head指针指向第一个结点（即让这个结点作为头结点）
	if (*head == NULL) {
		printf("结点创建失败！");
	}
	(*head)->prior = *head; //此处定义的是双向循环链表所以(*head)->prior 和	(*head)->next都是等于*head而不是NULL
	(*head)->next = *head;
}
/*//初始化
void InitDLL(Dll **head) {
	*head = (Dll *)malloc(sizeof(Dll));          //让head指针指向第一个结点（即让这个结点作为头结点）
	if (*head == NULL) {
		printf("结点创建失败！");
	}
	(*head)->prior =NULL; //此处定义的是双向循环链表所以(*head)->prior 和	(*head)->next都是等于*head而不是NULL
	(*head)->next = NULL;
}*/
//插入
int DLLInsert(Dll*head, int i, Datatype x) {
	Dll *p, *s;
	int j;
	p = head->next;//p指向头结点的下一个元素
	j = 0;//标记p指针的位置，（头结点序号为-1,头结点下一个元素为0，以此类推）
	while (p != head, j < i) {
		p = p->next;
		j++;  //标记p指针的位置
	}
	if (j != i) {
		printf("插入位置参数i不合法！");
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

//求链表中元素的个数
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
//求当前数据元素的个数
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

//删除
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
		printf("删除位置错误！");
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

//取数据
int DLLGet(Dll *head, int i, Datatype *x) {
	Dll *p;
	int j = -1;//标记指针p的位置
	p = head;
	while (p->next != NULL&&j<i) {
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("取元素位置错误！");
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
//撤销
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