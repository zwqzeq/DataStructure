#include<stdio.h>
#include<stdlib.h>
int cheng( int a);
int main()
{
	int a[20],i,n=1,j,m,k;
	scanf("%d",a);
	if(a[0]%2==0){
	for(i=0;i<20;i++,n++)
	{
	a[i+n] = cheng(a[i+n-1])-1;
	a[i+n+1] = a[i+n-1]-jiecheng(a[i+n]);
	if(a[i+n+1]==0)
	{
		m = i+n+1;
		break;
	}
	}
	
		printf("%d=",a[0]);
		for(j = 1;j<m;j=2*j+1)
	{
	printf("2(%d)+",a[j]);
	}
	}else
	{
		for(i=0;i<20;i++,n++)
	{
	a[i+n] = cheng(a[i+n-1])-1;
	a[i+n+1] = a[i+n-1]-jiecheng(a[i+n]);
	if(a[i+n+1]==1)
	{
		k = i+n+1;
		break;
	}
	}
	for(j = 1;j<k;j=2*j+1)
	{
		printf("%d=",a[0]);
	printf("2(%d)+",a[j]);

	}
	}
	system("pause");
}
int cheng( int a)
{
	int n = 2,m = 1;
	do
	{
		n*=2;
	    m = m +1;
	}while(n<=a);
	
	return m;
}
int jiecheng(int f)
{
	int a = 2 ,i;
	for(i = 1;i < f;i++)
	{
		a = a*2;
	}
	return a;
}