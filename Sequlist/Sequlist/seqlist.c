#include<stdio.h>            //预处理指令
#define MaxLength 100       //宏定义

typedef int Datatype;


//定义一个顺序表
typedef struct
{
	Datatype list[MaxLength];    //长度  
	int size;              //当前个数       
}Seq;

//获取当前数据元素个数
int ListLength(Seq L) {
	return L.size;
}

//初始化
int InitList(Seq *L) {
	L->size = 0;
}

//插入
int ListInsert(Seq *L,int i,Datatype x) {
	int j;
	if (L->size >= MaxLength) {
		printf("顺序表已满无法插入！");
		return 0;
	} 
	else if (i<0 || i>L->size) {//在size个元素之间插入
		printf("插入的位置不合法!");
		return 0; 
	}
	else {
		for (j = L->size; j > i; j--) {
			L->list[j] = L->list[j - 1];
		}
			L->list[i] = x;
			L->size ++;
			return 1;
	}
}


//删除
int ListDelete(Seq*L, int i,Datatype *x) {
	int j;
	if (L->size <= 0) {
		printf("顺序表已空无法删除！");
		return 0;
	} 
	else if (i<0 || i>L->size - 1) {
		printf("删除位置i不合法！");
		return 0;
	}
	else {
		*x = L->list[i];
		for (j = i+1; j < L->size; j++) {
			L->list[j - 1] = L->list[j];
		}
		L->size--;
		return 1;
	}

}

//取数据
int  ListGet(Seq L, int i, Datatype*x) {
	if (L.size <= 0) {
		printf("顺序表为空，无法取数据！");
		return 0;
	}
	else if (i < 0 || i>L.size - 1) {
		printf("参数i不合法！");
	}
	else {
		*x = L.list[i];
		return 1;
	}
}

int main() {
	Seq myseq;
	Datatype x=0;
	int i;
	InitList(&myseq);
	for (i = 0; i < 10; i++) {
		ListInsert(&myseq, i, i + 1);
	}
	ListDelete(&myseq, 5, &x);
	ListDelete(&myseq, 5, &x);
	for (i = 0; i < ListLength(myseq); i++) {
		ListGet(myseq, i, &x);
		printf("%d   ", x);
	}
	printf("\n");
	return 0;
}