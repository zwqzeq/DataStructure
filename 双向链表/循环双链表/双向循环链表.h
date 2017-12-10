#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct Node {
	DataType data;                  //使用的数据元素
	struct Node *next;              //指向下一个结点
	struct Node *prior;             //指向上一个结点
}DLNode;                         //定义结构体类型为DLNode

//初始化
void ListInitiate(DLNode **head) {
	*head = (DLNode *)malloc(sizeof(DLNode));            //申请头结点
	(*head)->prior = *head;                             //构成前驱指针循环链表
	(*head)->next = *head;                              //构成后继指针循环链表
}

//插入数据元素
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
		printf("插入元素位置参数错误！\n");
		return 0;
	}
	s = (DLNode*)malloc(sizeof(DLNode));
	s->data = x;
	
	//1,2必须在3,4的前面
	//1,2位置可互换
	s->prior = p->prior;            //插入步骤1
	p->prior->next = s;             //插入步骤2

	//3,4位置可互换
	s->next = p;                    //插入步骤3
	p->prior = s;                   //插入步骤4
	return 1;
}

//删除数据元素
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
			printf("删除元素位置参数出错！\n");
			return 0;
		}
		*x = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return 1;
	}

//求当前数据元素的个数
int ListLength(DLNode*head) {
	DLNode *p = head;
	int size = 0;
	while (p->next != head) {
		p = p->next;
		size++;
	}
	return size;
}

//撤销内存空间
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