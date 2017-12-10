
#include<stdio.h>
typedef int Datatype;

//链表的每个结点的构成
typedef struct Node
{
	Datatype data;              //数据域
	struct Node* next;          //指针域
}Sll;

//初始化
void InitSLList(Sll**head) {
	/*因为初始化操作前，头指针参数head没有具体的地址值，在初始化操作时，头指针参数head才得到了具体的值，而这个地址值要返回给调用函数
	所以，头指针head应该设计为指针的指针类型，如果此时head设计为指针类型，那么调用函数将无法得到在初始化函数中被赋值的头指针参数head的数值
	*/
	*head = (Sll*)malloc(sizeof(Sll));
	if (*head == NULL) {
		printf("创建结点失败！");
	}
	(*head)->next=NULL;//头结点指针域置空
}

//插入
int SLListInsert(Sll*head,int i,Datatype x) {
	Sll *p, *q;
	int j = -1;             //j用来标记p指针指向的结点的序号，头结点序号记为-1
	p = head;            //p先指向头结点（所以此时j=-1），然后p逐渐后移( j 逐渐增大)
	if (head == NULL) {
		printf("链表不存在！"); 
		return 0;
	}
	//移动p指针到要插入位置的前一个结点(即第i-1个结点)
	while (p->next != NULL&&j < i - 1) {//只有当p->next != NULL时，下面的语句才有意义
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("插入元素位置参数错误！");
	}
	else {
		q = (Sll*)malloc(sizeof(Sll));
		q->data = x;
		q->next = p->next;
		p->next = q;
		return 1;
	}
}

//求链表元素个数
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
//删除
int SLListDelete(Sll*head, int i, Datatype *x) {
	Sll*p, *s;
	int j = -1;
	p = head;
	if (head == NULL) {
		printf("链表不存在不能删除！");
	}
	//移动p指针到要删除的结点的前一个结点
	while (p->next != NULL&&p->next->next != NULL&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("删除位置参数错误");
		return 0;
	}
	s = p->next;//s指向要删除的结点
	*x = s->data;
	p->next = p->next->next;
	free(s);//释放s指向的结点（即要删除的结点）
	return 1;
}

//取数据
int SSListGet(Sll *head,int i,Datatype *x) 
{
	Sll *p;
	int j;
	p = head;
	j = -1;  //头结点序号为-1
	//移动p指针到要取数据的结点即第i个结点
	while (p->next != NULL&&j < i) {
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("取数据位置i错误！");
		return 0;
	}
	*x = p->data;
	return 1;
}

//销毁单链表
void SLListDestroy(Sll**head) {
	Sll *p,*q;
	p = *head;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);//从头结点开始逐一释放结点
	}
	*head = NULL;
}


void main(void) {
	int i=0;
	Datatype x=0;
	Sll *head;//创建头指针变量，此时head没有被赋值，head不指向任何结点
	InitSLList(&head);//初始化，创建头结点，使head指向它
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