#include<stdio.h>
#include<stdlib.h>
int x=0;
void radixsort(int a[],int n)
{
	int b[10][5],d[10],c[10],m;
	int i,j,k,l,num,div,passes,large;
	div=1;num=0;large=a[0];
	for(i=0;i<n;i++)
	{	x++;
		if(a[i]>large)
		{
			large=a[i];
		}
	}
	while(large>0)
	{
		num++;
		large/=10;
	}
	for(passes=0;passes<num;passes++)
	{
		for(k=0;k<10;k++)
		{
			d[k]=0;
		}
		for(i=0;i<n;i++)
		{
			 l=(a[i]/div)%10;
			 b[l][d[l]++]=a[i];
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<d[k];j++)
			{
				a[i++]=b[k][j];
			}
		}
		div*=10;
		printf("pass %d list is--->",passes+1);
			for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	for(m=0;m<n;m++)
	printf("%d ",a[i]);

}
void main()
{
	
	int a[10],n,i;
	printf("size");
	scanf("%d",&n);
	printf("enter numbers\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	radixsort(a,n);
	printf("no of cmp=%d\n",x);
}
