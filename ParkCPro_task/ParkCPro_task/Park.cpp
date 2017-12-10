#include<iostream>
#include"Park.h"

using namespace std;

//初始化队列
int InitQueue(Queue &q,int nSize)
{
	//分配内存空间
	q.base = (Car*)malloc(nSize*sizeof(Car));
	if (!q.base)
	{
		//内存分配失败
		return ERROR;
	}
	//初始化顺序队列
	q.front = q.rear = 0;
	q.size = nSize;
	return OK;
}

//获得队列长度
int QueueLength(Queue q)
{
	return (q.rear - q.front + q.size)%q.size;
}

//插入队尾元素
int EnQueue(Queue &q, Car car)
{
	//队列满
	if ((q.rear + 1) % q.size == q.front)
	{
		return ERROR;
	}
	q.base[q.rear] = car;
	q.rear = (q.rear + 1) % q.size;
	return OK;
}

//删除队首元素
int DeQueue(Queue &q, Car &car)
{
	//队列空
	if (q.front == q.rear)
	{
		return ERROR;
	}
	car = q.base[q.front];
	q.front = (q.front + 1) % q.size;
	return OK;
}

//撤销动态申请空间
int DestoryQueue(Queue &q) 
{
	//释放空间
	if (q.base)
	{
		free(q.base);
		q.base = NULL;
	}
	q.front = q.rear = 0;
	q.size = 0;
	return OK;
}

//遍历队列元素
int QueueTraverse(Queue q)
{
	if (q.front == q.rear)
	{
		return ERROR;
	}
	int i = q.front;
	while (i != q.rear)
	{
		Car car = q.base[i];
		cout << "车牌号码：" << car.lisence_plate << "\t入场时间：" << car.time << endl;
		i = (i + 1) % q.size;
	}
	return OK;
}

//车辆入场
int InPark(Queue &sqPark, Queue &sqAisle)
{
	cout << "----- 进入停车场 -----" << endl;
	Car car;
	cout << "请输入车牌号：";
	cin >> car.lisence_plate;
	cout << "请输入场时间：";
	cin >> car.time;
	if (OK == EnQueue(sqPark, car))
	{
		cout << "进入停车场"<< QueueLength(sqPark) << "号位值。" << endl;
	}
	else if (OK == EnQueue(sqAisle, car))
	{
		cout << "停车场已满，进入临时车道" << QueueLength(sqAisle) << "号位值。" << endl;
	}
	else
	{
		cout << "没有空余车位，离开停车场。" << endl;
	}
	return 0;
}

//车辆离开
int OutPark(Queue &sqPark, Queue &sqAisle)
{
	
	cout << "----- 离开停车场 -----"<<endl;
	Car car;
	if (OK == DeQueue(sqPark, car))
	{
		int time;
		cout << car.lisence_plate << "离开时间：";
		cin >> time;
		int fee = (time - car.time) * 2;
		cout << "收费" << fee << "元" << endl;
		if (OK == DeQueue(sqAisle, car))
		{
			cout << car.lisence_plate << "从过道进入停车场" << endl;
			cout << "请输入入场时间：";
			cin >> car.time;
			EnQueue(sqPark, car);
		}	
	}
	else
		{
			cout << "停车场没有车离开。" << endl;
		}
	return 0;
}

//查看停车场
int ViewPark(Queue &sqPark, Queue &sqAisle)
{
	cout << "----- 查看停车场 -----" << endl;
	//遍历整个停车场队列
	QueueTraverse(sqPark);
	//遍历整个临时车道队列
	QueueTraverse(sqAisle);
	return 0;
}
