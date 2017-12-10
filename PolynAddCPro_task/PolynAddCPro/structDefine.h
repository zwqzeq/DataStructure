#pragma once
//定义结构体
typedef struct PLNODE {
	double dbCoef;                              //系数域
	int nExpn;                                       //指数域
	struct PLNODE*next;                     //指针域,指向下一个节点
} PLNODE;                                           //  定义PLNODE类型代替struct PLNODE
typedef PLNODE *  PLinkList;            //定义PLinkList代替PLNODE *类型
