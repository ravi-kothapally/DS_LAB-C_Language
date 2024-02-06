#include<stdio.h>
void main()
{
	int a[10],i,e,n,c=0,c1=0;
	printf("size");
	scanf("%d",&n);
	printf("numbers :");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("search element :");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{c1++;
		if(e==a[i])
		{
		printf("found at index %d",i);
		c=1;
		}
	}
	printf("no of comparisions=%d\n",c1);
	if(c==0)
	printf("not found");
	
}
