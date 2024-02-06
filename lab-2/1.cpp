#include<stdio.h>
int t=9;
int fun(int t)
{	t=5;
	return t;
}
int main ()
{
	printf("%d",fun(t));
	
}
