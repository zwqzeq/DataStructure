#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"model.h"                         

//添加学生信息
void addStu() {
	struct Student stu;        //创建struct Student类型的结构体变量stu，用来存放输入的学生信息
	printf("\n添加学生信息\n");
	printf("请输入学号：");
	scanf("%d", &stu.nNum);
	printf("请输入分数：");
	scanf("%f", &stu.fScore);

	//添加学生信息
	if (addNode(&stu)==0) {          
		printf("添加失败\n");               //添加结点的函数返回值为0时添加失败
	}
	else {
		printf("添加成功\n");
	}
}

//显示学生信息
void displayStu() {
	struct Student * pStu = NULL;
	int i = 0;
	int nCount = 0;
	printf("学号\t分数\n");
	//获取学生信息和个数
	pStu = traverseList(&nCount);
	if (pStu == NULL) {
		printf("显示失败！\n");
		return;
	}
	//显示学生信息
	for (i = 0; i < nCount; i++) {
		printf("%d\t%0.1f\n", pStu[i].nNum, pStu[i].fScore);
	}
	//释放动态分配的内存
	free(pStu);
	pStu = NULL;
}

//删除学生信息
void deleteStu() {
	struct Node*node = NULL;
	struct Node*pTemp = NULL;
	int nNum = 0;
	printf("请输入删除的学生学号：");
		scanf("%d",&nNum);
		if (0 == deleteNode(nNum)) {
			printf("删除失败\n");
			return;
		}
		else {
			printf("删除成功\n");
			return;
		}
		while (node -> next != NULL) {
		//如果遍历到的结点（当前结点）的学号与删除的学号相同
		if (node->next->data.nNum == nNum) {
			//将当前结点的上一个结点，指向当前点的下一个结点
			pTemp = node->next;
			node->next = pTemp->next;
			//释放当前结点
			free(pTemp);
		}
		node = node->next;
	}
	return 0;
}


//程序入口
int main() {
	int nSelection = -1;
	do {
		printf("1. 添加学生信息\n");            //菜单
		printf("2. 显示学生信息\n");
		printf("3. 删除学生信息\n");
		printf("0. 退出\n");
		printf("请输入操作序号：");
		scanf("%d", &nSelection);
		switch (nSelection) {
		case 1:
			addStu();           //添加学生信息
			break;
		case 2:
			displayStu();       //显示学生信息
			break;
		case 3:
			deleteStu();        //删除学生信息
			break;
		case 0:
			printf("感谢您的使用！");
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入！");
			scanf("%d", &nSelection);
			break;
		}

	} while(nSelection != 0);        //注意：while里面的nSelection应该定义在do以外
	
	return 0;
}