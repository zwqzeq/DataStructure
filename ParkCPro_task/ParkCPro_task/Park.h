#define ERROR -1
#define OK 0                    //宏定义
#include<stdio.h>
#include<malloc.h>        //预处理指令

//汽车结点
struct Car 
{
	//车牌
	char lisence_plate[10];
	//进入停车场的时间
	int time;
};

//循环队列
typedef struct SqQueue
{
	//数组
	Car*base;
	//队头指针
	int front;
	//队尾指针
	int rear;
	//队列长度
	int size;
}Queue;


//函数声明部分
//初始化队列SqQueue
int InitQueue(Queue&q, int nSize);
//销毁队列
int DestoryQueue(Queue &q);
//插入队尾元素
int EnQueue(Queue &q, Car car);
//获得队列长度
int QueueLength(Queue q);
//删除队首元素
int DeQueue(Queue &q, Car &car);
//遍历队列元素
int QueueTraverse(Queue q);
//车辆入场
int InPark(Queue &sqPark, Queue &sqAisle);
//车辆离开
int OutPark(Queue &sqPark, Queue &sqAisle);
//查看停车场
int ViewPark(Queue &sqPark, Queue &sqAisle);
