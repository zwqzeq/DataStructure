
#include<stdio.h>
#include <stdlib.h>
#include"model.h"
struct Node * stuList = NULL;           //链表 ，---全局变量

//初始化链表
int init() {
	struct Node * head = NULL;         //创建头指针变量
	if (stuList == NULL)               //如果链表为空
	{
		head = (struct Node *)malloc(sizeof(struct Node));//创建头结点(为头结点分配内存)     
		if (head == NULL) {
			return 0;                  //创建头结点失败返回0，即初始化失败
		}
		head ->next = NULL;//此时头结点创建成功，让头结点的指针域为空（即此时只有一个头结点，且头结点指针域不指向任何结点）
		stuList = head;    //让stuList和head指向同一头结点
		return 1;          //创建头结点成功返回1，即初始化成功
	}
	return 0;              //链表已经存在时返回0，即初始化失败
}

//添加结点
int addNode(struct Student * pStu) {
	struct Node * node = NULL;
	struct Node * cur = NULL;

	if (stuList == NULL) {
		//如果链表为空，就初始化链表
		if (init() == 0) {
			//如果初始化失败就返回0
			return 0;
		}
	}

	//为添加的结点分配内存
	cur = (struct Node*)malloc(sizeof(struct Node));        //cur指向新创建的结点
	if (cur == NULL) {
		return 0;         //创建一个结点失败时返回0
	}

	cur->data = *pStu;              //将添加的学生信息保存到创建的结点中                      
	cur->next = NULL;
	//遍历链表，将结点添加到链表尾部
	node = stuList;
	while (node->next != NULL)
	{
		node = node->next;     //遍历

	}
	node->next = cur;          //此时已经遍历到链表尾，让尾结点的指针域指向新创建的且包含学生信息的结点（即cur指向的结点）
	return 1;                  //添加结点成功返回1
}

//遍历链表
struct Student* traverseList(int *pCount) {
	struct Node*node = NULL;
	int i = 0;
	struct Student*pStu = NULL;
	node = stuList->next;
	if (node == NULL) {
		return NULL;
	}
	//获取链表结点个数
	node = stuList->next;
	do {
		(*pCount)++;
		node = node->next;
	} while (node != NULL);
	//动态分配内存
	pStu = (struct Student*)malloc(sizeof(struct Student)*(*pCount));
	
	//取出链表结点中的数据
	node = stuList->next;
	while (node != NULL) {
		pStu[i] = node->data;
		node = node->next;
		i++;
	}
	return pStu;
}

//删除结点
int deleteNode(int nNum) {
	struct Node * node = stuList;
	struct Node * pTemp = NULL;
	if (node == NULL) {
		return 0;
	}
	//从链表的第一个结点开始遍历
	while (node->next != NULL) {
		//如果遍历到的结点（当前结点）的学号与删除的学号相同
		if (node->next->data.nNum == nNum) {
			//将当期结点的上一个结点指向当前结点的上一个 结点
			pTemp = node ->next;
			node -> next =pTemp -> next;
			//释放当前结点
			free(pTemp);
			pTemp = NULL;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

//释放空间
void release() {
	struct Node*cur = stuList;
	struct Node *next = NULL;
	while (cur!=NULL) {
		next = cur->next;//结点内存释放前，next保存其后继
		free(cur);//释放结点内存
		cur = next;
	}
	stuList = NULL;
}