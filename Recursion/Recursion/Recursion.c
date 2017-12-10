//递归
#include<stdio.h>

void up_and_down(int);            //函数声明
int main()
{
	up_and_down(1);
	return 0;
}

void up_and_down(int n) {
	printf("First level  %d : n location %p\n", n, &n);
	if (n< 4)                                                //n大于4时执行此句
	up_and_down(n + 1);                                                  //n小于4时执行此句                            
	printf("Second level  %d :n  location %p\n", n, &n);              
}

/*
void up_and_down(int n) {
printf("First level  %d : n location %p\n", n, &n);
if (n< 4)return;                                                //n大于4时执行此句
up_and_down(n + 1);                                                  //n小于4时执行此句
printf("Second level  %d :n  location %p\n", n, &n);
}
*/