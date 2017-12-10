#include<stdio.h>                                            //预处理指令
#define MaxSize 100                                        //顺序表最大长度
typedef int DataType;                                      //重定义类型DataType代替int
#include"SeqList.h"                                         //导入自定义的头文件                           

//程序入口
void main() 
{
	SeqList myList;                                            //定义结构体变量
	int i, x;
	ListInitiate(&myList);                                  //初始化
	for (i = 0; i < 10; i++) {
		ListInsert(&myList, i, i + 1);                    //插入数据元素
	}
	ListDelete(&myList, 4, &x);                        //删除数据元素
	for (i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &x);                             //取数据元素
		printf("%d    ",x);
	}
	printf("\n");
}