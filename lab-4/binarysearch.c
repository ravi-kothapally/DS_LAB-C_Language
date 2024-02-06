#include<stdio.h>
void main()
{
	int a[10],i,e,n,c1=0,j,t,start,end,mid,c=0;
	printf("size");
	scanf("%d",&n);
	printf("numbers :");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("search element :");
	scanf("%d",&e);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	start=0;
	end=n;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(e==a[mid])
		{	c++;
				printf(" found");
				c1=1;
				break;
		}
		else if(e>a[mid])
	{
			start=mid+1;
			c++;
		}
		else if(e<a[mid])
		{
		end=mid-1;
		c++;
	}
	}
	if(c1==0)
	puts("not found");
	printf("no of comparisions=%d",c);
}
	
