#include<stdio.h>
typedef int DataType;          //定义DataType代替int类型
#define MaxSize 100            //定义全局常量
typedef struct 
{
	DataType list[MaxSize];      //定义存放数据元素的数组
	int size;                                //定义当前数据元素个数
}SeqList;                                   //定义SeqList结构体类型，可以用SeqList去定义变量

//初始化
void ListInitiate(SeqList *L) {
	L ->size = 0;                       //定义顺序表中初始的数据元素的个数为0
}

//求当前数据元素的个数
int ListLength(SeqList L) {                 
	return L.size;                      //返回顺序表当前数据元素的个数
}

//插入数据元素
int ListInsert(SeqList *L, int i, DataType x) {
	int j;
	if (L->size >= MaxSize) {  //判断顺序表是否已满
		printf("顺序表已满无法插入！\n");
		return 0;                         //插入失败返回0
	}
	else if (i < 0 || i > L-> size)  //判断插入的位置是否合法
	{
		printf("参数i不合法！\n");
		return 0;                           //插入失败返回0
	}
	else                                     //顺序表未满且插入的位置合法
	{
		//从右向前依次右移，为插入做准备
		for (j = L->size-1; j >= i; j--) //因为要从最后一个数据元素（即最右边）开始移动，所以与顺序表中的数据个数size有关，所以让j的初值等于顺序表中最后一个元素的下标（下标是从0开始的）
		{
			L->list[j+1] = L->list[j];  //依次将左边的元素赋值给右边的元素
		}
		L->list[i] = x;                 //插入元素x
		L->size++;                   //当前元素的个数加一
		return 1;                       //插入成功返回1
	}
}

//删除数据元素
int ListDelete(SeqList *L, int i, DataType* x) {
	int j;
	if (L->size <= 0) {             //判断是否为空表
		printf("数据表已空无数据可删除！\n");
		return 0;                         //删除失败返回0
	}
	else if (i<0 || i > L->size - 1) //判断删除的位置是否合法
	{
		printf("参数i不合法！\n");
		return 0;                       //删除失败返回0
	}
	else                        //顺序表不为空且删除的位置合法
	{
		*x = L->list[i];                        //将要删除的元素存放在x中
		//从左向右依次左移
		for (j = i; j < L->size - 1; j++) { //因为要从删除的元素的下一个元素开始向左移动，所以与删除的位置i有关，所以让j的初值等于i
			L->list[j] = L->list[j+1];
		}
		L->size--;               //数据元素个数减一
		return 1;                 //删除成功返回1
	}
}

//取数据元素
int ListGet(SeqList L, int i, DataType *x) {
	if (i<0 || i>L.size - 1) {                                   //判断取数据的位置是否合法
		printf("参数i不合法！\n");
		return 0;                                                   //取数据失败
	}
	else                    //取数据的位置合法
	{
		*x = L.list[i];                //将取出的数据存放在x中
		return 1;                     //取数据成功
	}
}