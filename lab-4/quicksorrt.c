#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int partition(int a[],int l,int h)
{	int p=a[h];
	int j,i=l-1,y;
	for(j=l;j<h;j++)
	{
		if(a[j]<=p)
		{
		
			i++;
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			
		}
		
	}
			y=a[i+1];
			a[i+1]=a[h];
			a[h]=y;
			return (i+1);
		
	
}
void quicksort(int a[],int l,int h)
{
	if(l<h){
	
	int pi;
	pi=partition(a,l,h);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,h);
	
	}
}
void main()
{
		int a[10],i,j,n;
	printf("size\n");
	scanf("%d",&n);
	printf("enter numbers");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

