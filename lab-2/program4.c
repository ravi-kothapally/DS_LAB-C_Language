#include<stdio.h>
void toh(int n,int l,int m,int r)
{
	if(n!=0)
	{
		toh(n-1,l,r,m);
		printf("move %d to %d\n",l,r);
		toh(n-1,m,l,r);
	}
}
void main()
{	int n;
	printf("no of disc");
	scanf("%d",&n);
	toh(n,1,2,3);
}
