#include<stdio.h>
void main()
{
	int a[100],b[100],i,n,k,mi,ma;
	printf("size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	mi=a[0];
	ma=a[0];
	for(i=0;i<n;i++)
	{
		if(mi>a[i])
		{
			mi=a[i];
		}
		if(ma<a[i])
		{
			ma=a[i];
		}
	}
	for(i=mi;i<=ma;i++)
	{
		b[i]=0;
	}
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
	}
	for(i=mi+1;i<=ma;i++)
	{
		b[i]=b[i]+b[i-1];
	}
	int c[b[ma]];
	for(i=0;i<=b[ma];i++)
	{
		c[b[a[i]]--]=a[i];	
	}
	for(i=0;i<=b[ma];i++)
	printf("%d ",c[i]);
	
}
