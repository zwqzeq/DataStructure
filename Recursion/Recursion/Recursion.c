//�ݹ�
#include<stdio.h>

void up_and_down(int);            //��������
int main()
{
	up_and_down(1);
	return 0;
}

void up_and_down(int n) {
	printf("First level  %d : n location %p\n", n, &n);
	if (n< 4)                                                //n����4ʱִ�д˾�
	up_and_down(n + 1);                                                  //nС��4ʱִ�д˾�                            
	printf("Second level  %d :n  location %p\n", n, &n);              
}

/*
void up_and_down(int n) {
printf("First level  %d : n location %p\n", n, &n);
if (n< 4)return;                                                //n����4ʱִ�д˾�
up_and_down(n + 1);                                                  //nС��4ʱִ�д˾�
printf("Second level  %d :n  location %p\n", n, &n);
}
*/