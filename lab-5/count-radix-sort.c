#include<stdio.h>
#include<stdlib.h>
void radixsort(int a[],int n)
{
	int b[10]={0},d[20],m,l,p;
	int i,num,div,passes,large;
	div=1;
	num=0;
	large=a[0];
	for(i=0;i<n;i++)
	{
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
	int cj;
	for(passes=0;passes<num;passes++)
	{ 
	cj=1;
		for(i=0;i<n;i++)
		{
			 l=(a[i]/div)%10;
			 b[l]++;
		}
		for(i=0;i<10;i++)
		printf("%d ",b[i]);
		puts("");
		for(i=0;i<10;i++)
		{
			if(b[i]!=0)
			{
				p=b[i];
				b[i]=cj;
				cj=cj+p;
			}
		}
		for(i=0;i<10;i++)
		printf("%d ",b[i]);
		puts("");
		m=n;
		for(i=0;i<n;i++)
		{
			l=((a[i]/div)%10);
			
			 d[b[l]]=a[i];
			 
			 printf("\n<<<<< %d %d>>>>>\n",d[b[l]],b[l]);
			 b[l]++;
		}
		for(i=1;i<=n;i++)
		{puts("ggg");
			a[i-1]=d[i];
		}
		div*=10;
		for(i=0;i<10;i++)
		b[i]=0;
		for(i=0;i<n;i++)
		printf(": %d ",a[i]);
		puts("");
	}
}
void main()
{
	int a[20],i,n;
	printf("size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	radixsort(a,n);
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
}

