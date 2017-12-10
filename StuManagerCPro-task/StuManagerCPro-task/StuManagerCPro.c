//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>        
#include<string.h>                            //预处理指令

//新的类型Student代替原有类型struct Student1
typedef  struct Student1
{
	int num;      //学号
	char name[20];//姓名
	int nSex;     //性别
	float fScore; //分数
}Student;

int nCount = 0;
Student *pStu=NULL;

//初始化
int init() {
	if (pStu == NULL) {
		pStu = (Student*)malloc(sizeof(Student));                      //申请内存空间，让pStu指向该内存空间
	}
	else {
		pStu = (Student*)realloc(pStu, sizeof(Student)*(nCount + 1));  //将pStu所指向的已分配的内存区的大小改为sizeof(Student)*(nCount + 1)，sizeof(Student)*(nCount + 1)可以比原来分配的空间大或小
	}
	if (pStu == NULL) {
		return 0;               //初始化失败返回0
	}
	return 1;                   //初始化成功返回1
}

//添加学生信息
void add() {
	Student student;//定义结构体变量，用来保存学生信息
	       
		//将输入的学生信息保存到结构体中
		printf("请输入学生信息\n");
		printf("学号：");
		scanf("%d", &student.num);
		printf("姓名：");
		scanf("%s", student.name);
		if (strlen(student.name) > 20) {
			do {
				printf("输入错误，请重新输入:\n");
				scanf("%s", student.name);
			} while (strlen(student.name) > 20);
		}
		printf("性别：（1为男，0为女）");
		scanf("%d", &student.nSex);
		if (student.nSex != 1 && student.nSex != 0) {
			do {
				printf("输入错误，请重新输入:\n");
				printf("性别：（1为男，0为女）");
				scanf("%d", &student.nSex);
			} while (student.nSex != 1 && student.nSex != 0);    // &&是两者同时满足就循环，||是至少一个满足就循环
		}
		printf("分数：（0--100）");
		scanf("%f", &student.fScore);
		if (student.fScore<0 || student.fScore>100) {
			do {
				printf("输入错误，请重新输入:\n");
				printf("分数：（0--100）");
				scanf("%f", &student.fScore);
			} while (student.fScore < 0 || student.fScore > 100);
		}

		if(init()==1){                                  //初始化成功
		/*	*(pStu + nCount) = student;                 指针法，等价于下面一句*/
			pStu[nCount] = student;                    //下标法
			nCount++;                                 //学生个数加一
	}
}

//显示学生信息
void display() {
	int i = 0;
	printf("学生信息如下：\n");
	printf("学号\t姓名\t性别\t分数\n");
	for (i = 0; i < nCount; i++) {
		printf("%d\t%s\t%d\t%0.1f\n", pStu[i].num, pStu[i].name, pStu[i].nSex, pStu[i].fScore);
	}
}

//保存学生信息
void save(Student * pStudent) {
	FILE *fp = NULL;
	int i = 0;
	fp = fopen("student.txt","a");//如果fp不为空，则说明存在student.txt文件，直接向student.txt文件末尾写入内容

	if (fp == NULL) {       
		fp = fopen("student.txt","w");//以只写的方式创建student.txt文件
		if (fp == NULL) {
			printf("保存学生信息失败\n");
			exit(0);
		}
	}
	//写入学生信息
	for (i = 0; i < nCount; i++) {
		fprintf(fp, "%d##%s##%d##%0.1f\n", pStudent[i].num, pStudent[i].name, pStudent[i].nSex, pStudent[i].fScore);
	}

	//刷新
	fflush(fp);

	//关闭文件
	fclose(fp);
	printf("添加学生信息成功\n");
}

//释放空间
void release() {
	if (pStu!=NULL) {
		free(pStu);
		pStu = NULL;
	}
}

//程序入口函数
int main() {
	int nSelection = -1; //接收用户输入的变量的初始化
	do {
	//输出系统菜单
	printf("1. 添加学生信息\n");
	printf("2. 显示学生信息\n");
	printf("3. 保存学生信息\n");
	printf("0. 退出\n");

	//提示并接受用户的输入
	printf("请输入操作编号：");
	scanf("%d", &nSelection);

	switch (nSelection)
	{
	case 1:
		add();          //添加学生信息
		break;
	case 2:
		display();       //显示学生信息
		break;
	case 3:
		save(pStu);      //保存学生信息
		break;
	case 0:
		release();      //释放结点空间
		break;
	default:
		printf("输入的菜单项错误\n");
		break;
	}
	} while (nSelection!=0);
	return 0;
}