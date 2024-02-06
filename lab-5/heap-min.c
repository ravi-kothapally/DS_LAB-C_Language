#include<stdio.h>
swap(int *a,int *b)
{
	
	int t;
	t=*a;
	*a=*b;
	*b=t;
	
}
void heapify(int i,int size,int a[])
{
	
	if((2*i)<=size)
	{

	heapify(2*i,size,a);
	heapify(2*i+1,size,a);
	if(a[i]>a[2*i])
	swap(&a[i],&a[2*i]);
	if(a[i]>a[2*i+1])
	swap(&a[i],&a[2*i+1]);
	
	}
	if((2*i+1)==size)
	{

	heapify(2*i,size,a);
	heapify(2*i+1,size,a);
	if(a[i]>a[2*i])
	swap(&a[i],&a[2*i]);
	if(a[i]>a[2*i+1])
	swap(&a[i],&a[2*i+1]);
	
	}


}
void main()
{
	int i,a[100],n,size;
	printf("size");
	scanf("%d",&n);
	printf("numbers\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		}	
	for(i=1;i<=n;i++)
	{	
		heapify(1,n+1-i,a);
			printf("%d ",a[1]);
	
		size=n+1-i;
		a[1]=a[size];
	
	}
}
