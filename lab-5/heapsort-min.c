#include<stdio.h>
swap(int *a,int *b)
{
	
	int t;
	t=*a;
	*a=*b;
	*b=t;
	
}
void heap(int i,int a[],int n)
{
	if(2*i+1<n){
	
	if(a[2*i+1]<a[i])
	swap(&a[i],&a[2*i+1]);}
	if(2*i+2<n)
	if(a[2*i+2]<a[i])
	swap(&a[i],&a[2*i+2]);
	
}
void main()
{
	int i,a[100],n,size;
	printf("size");
	scanf("%d",&n);
	printf("numbers\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(n!=1)
	{
		i=n/2-1;
		
		heap(i,a,n);
		while(i!=0)
		{
			i=i-1;
			heap(i,a,n);
		}
		printf("%d ",a[0]);
		a[0]=a[n-1];
		n--;
	}
	printf("%d",a[1]);
}
