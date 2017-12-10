#include<iostream>                 
#include"Park.h"     

using namespace std;              //标准命名空间

//程序入口函数
int main()
{
	
	Queue sqPark;//停车场
	Queue sqAisle;//临时车道
	InitQueue(sqPark, 100);	//初始化停车场
	InitQueue(sqAisle, 10);	//初始化临时车道
	bool running = true;
	char key[10] = {0};         
	while (running) 
	{
		//输出菜单
		cout << "=====停车场管理=====" << endl;
		cout << "1、车辆入场" << endl;
		cout << "2、车辆离开" << endl;
		cout << "3、查看停车场" << endl;
		cout << "4、退出" << endl;
		cout << "请输入操作编号（1-4）:" << endl;

		cin >> key; //接收用户输入

		//处理用户输入
		switch (key[0]){		
		case'1'://车辆入场
			InPark(sqPark, sqAisle);
		    break;
		case'2':	//车辆离开
			OutPark(sqPark, sqAisle);
			break;	
		case'3':	//查看停车场
			ViewPark(sqPark, sqAisle);
			break;
		case'4':	//退出
			running = false;
			cout << "再见！" << endl;
			break;
		default :
			cout<<"输入错误！"<<endl;
			break;
		}
	}
	//销毁队列
	DestoryQueue(sqPark);
	DestoryQueue(sqAisle);
	return 0;
}