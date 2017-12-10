#include <stdio.h>                                    
#include <malloc.h>                                          //预处理指令
typedef int DataType;                                         //定义DataType类型代替int类型

//定义结构体，名称为Node，类型为SLNode，SLNode类型代替了struct Node类型
typedef struct Node {
	DataType data;                                               //数据域，用于存放可用数据元素
	struct Node* next;                                          //指针域，存放下一个结点的首地址
}SLNode;

//初始化
//因为该函数中head的改变要保留到主调函数，所以要用双指针
void ListInitiate(SLNode **head) {                     //参数head是一个指针变量指向另一个指针变量（注意head指向的这个指针变量必须是指向SLNode类型的），根据前面所述，实参应该是一个地址，且是SLNode * 类型的变量的地址
	*head = (SLNode*)malloc(sizeof(SLNode));  //申请头结点，由head指示其地址
	(*head)->next = NULL;                                  //头指针的指针域置结束标记NULL
}

//插入
int ListInsert(SLNode *head, int i, DataType x) {    //参数head是一个指针变量指向一个SLNode类型变量    ，根据前面所述，实参是一个地址，且是SLNode类型（结构体类型）变量的地址
	//在带头结点的单链表第i个结点前插入一个存放数据元素x的结点，首先要找到第i-1个结点并由p只指示
	SLNode *p, *q;  
	int j;                                                                 
	p = head;                                                
	j = -1;     //p从头指针开始遍历    ，头结点的序号记为-1，第一个存放数据元素的结点记为0，然后依此类推
	while (p->next != NULL && j < i - 1) {      //p->next != NULL判断保证指针所指的结点存在 ，j < i - 1保证最终让指针p指向第i-1个结点（即要删除的结点的左边一个结点）
		//最终让p指向第i-1个结点
		p = p->next;                                           //让p右移一位
		j++;                                                          
	}
	if (j != i - 1) {
		printf("插入元素位置参数错误！");
		return 0;                                                  //插入失败返回0
	}

	//插入的位置正确时执行
	q = (SLNode *)malloc(sizeof(SLNode));                        //创建一个结点，q指向该结点，这个结点作为要插入的结点
	q->data = x;                   //给要插入的结点的数据域赋值

	//以下两句顺序不能交换，如果先让p->next = q，再执行q->next = p->next时， p->next的值就是q，此时相当于q->next = q;这样并没有实现插入结点的要求
	q->next = p->next;       
	p->next = q;

	return 1;  //插入成功返回1
}

//删除
int ListDelete(SLNode *head, int i, DataType *x) {
	SLNode *p, *s;
	int j;
	p = head;               //head是指针变量，p首先指向头指针head指向的头结点
	j = -1;
	while (p->next  != NULL  &&  p->next->next  !=  NULL && j < i - 1) {//p->next != NULL，p->next->next != 保证要删除的结点的左边和右边都有结点 ，j < i - 1保证最终让指针p指向第i-1个结点（即要删除的结点的左边一个结点）
		p = p->next;
		j++;
	}
	if (j != i - 1) {//退出循环时判断p是否移动到指向第i-1个结点
		printf("删除元素位置参数错误！");
		return 0;//删除失败返回0
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);                           //释放s结点
	return 1;//删除成功返回1
}

//求当前数据元素个数                        
int ListLength(SLNode *head) {
	SLNode *p = head;                                       //p指向头结点
	int size = 0;                                                   //数据元素个数为0

	while (p->next != NULL) {           //判断p指向的结点的下一个结点是否存在
		p = p->next;                          //p向右移动一位
		size++;                                  //个数加一
	}
	return size; //返回数据元素个数
}


//取数据元素
int ListGet(SLNode *head, int i, DataType *x) {
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL&&j < i) {//p->next != NULL保证p指向的结点的下一个结点存在这样才能p = p->next;  j < i保证p最终移动到要取元素的那个结点（即第i个结点）
		p = p->next;
		j++;
	}
	if (j != i) {//判断p是否移动到指向第i个结点，（即要取元素的那个结点）
		printf("取元素位置参数错！");
			return 0;//取元素失败返回0
	}
	*x = p->data;                          //  将取出的元素存放到x中
	return 1;//取元素成功返回0
}

//撤销单链表
//因为head的改变要保留到主调函数，所以用双指针
void Destroy(SLNode **head) {
	SLNode *p, *p1;
	p = *head;                                   //p指向头结点
	while (p != NULL) {                     //判断p指向的结点是否存在
		p1 = p;                                    //让p1指向要释放到结点
		p = p->next;                           //向右移动p结点
		free(p1);                                  //释放p1指向的结点
	}
	*head = NULL;                           //循环结束时头结点置空
}