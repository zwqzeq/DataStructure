#include<stdio.h>
#include<malloc.h>
typedef int DataType;

//定义单链表中每个结点
typedef struct {
	DataType data;
	struct Node *next;
}SLNode;

//初始化单链表
void ListInitiate(SLNode **head) {
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}

//插入数据元素
int ListInsert(SLNode *head, int i, DataType x) {
	SLNode *p;              //p指向要插入的位置的前一个结点即i-1个结点
    SLNode *q;              //q指向要插入的结点
	int j = -1;
	p = head;
	
	while ( p -> next != NULL && j < i - 1) {
		//最终让p指向第i-1个结点
		p = p->next;
		j++;
	}
	//判断p是否指向第i-1个结点
	if (j != i - 1) {
		printf("插入元素位置参数错误！\n");
		return 0;
	}
	
	q = (SLNode*)malloc(sizeof(SLNode));        //生成新结点
	q->data = x;                               //新结点数据域赋值
	q->next = p->next;                         //插入步骤1，注意1和2顺序不能反
	p->next = q;                               //插入步骤2
	return 1;                                //插入成功则返回1

}

//求当前数据元素的个数
int ListLength(SLNode *head) {
	SLNode *p = head;                 //p指向头结点
	int size = 0;                    //size初始为0
	while (p->next != NULL) {        //循环计数
		p = p->next;
		size++;
	}
	return size;
}

//取元素
int ListGet(SLNode * head, int i, DataType *x) {
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i) {
		//指针变量移动到指向第i个结点
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("取数据元素位置参数错误！\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
//数据元素的倒置
int ListReverse(SLNode * head) {
	SLNode *p,*q;
	int i;
	p = head;    //p指向头结点
	q = head;
	ListLength(head);
	while (q->next != NULL) {
		//使q移动到指向尾结点
		q = q->next;
	}
	for (i = 0; i < ListLength(head) / 2; i++) {
		p->data = q->data;
		p = p->next;

	}


}

int main() {
	SLNode *head;          //定义头指针变量
	int i, x;              
	ListInitiate(&head);   //初始化
	for(i = 0; i < 10; i++) {
		ListInsert(head,i,i+1);     //插入元素
	}
	for (i = 0; i < ListLength(head); i++) {
		ListGet(head, i, &x);
		printf("%d   ", x);
	}
	return 0;
}