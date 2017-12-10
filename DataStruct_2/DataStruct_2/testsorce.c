#include "SLNode.h"
#include <stdlib.h>
typedef int DataType;
int main()
{
	void Delete(SLNode *head);                //删除结点函数声明              
	SLNode *head;                            //定义头指针变量
	int i, x, z; 
	ListInitiate(&head);                    //初始化
	printf("请输入10个可重复的数据：");     //输入
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &z);
		ListInsert(head, i, z);
	}
	Delete(head);                        //删除结点函数调用                    
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);            //取数据元素
		printf("%d   ", x);              //输出到控制台
	}
	printf("\n");
	Destory(&head);                    //撤销链表
	return 0;
}

//定义删除结点的函数
void Delete(SLNode *head)
{
	SLNode *p, *s, *q;                               //定义三个指针变量指向SLNode类型的结点
	p = head->next;                                  //p指向头结点的下一个结点
	while(p != NULL && p->next != NULL)              //p指向的结点不为空且p指向的结点的下一个结点不为空
	{
		s = p;                                       //s指向要删除结点的前驱
		q = p->next;                                 //q指向下一个结点
		while(q != NULL)                             
		{//q指向的结点不为空
			if(q->data == p->data)                  //如果两结点数据相同
			{
				s->next = q->next;                  //删除q结点
				free(q);                            //释放q结点
				q = s->next;                       //q指向下一个元素
			}
			else
				//两结点数据不等
			{
				s = q;            //s向后移动一位                      
				q = q->next;      //q向后移动一位
			}
			
		}
		p = p->next;//p向后移动一位
	}
}