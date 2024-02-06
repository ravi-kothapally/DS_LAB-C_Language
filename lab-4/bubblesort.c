#include<stdio.h>
void main()
{
	int a[10],i,j,t,n,c=0,k;
	printf("size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{c++;
			if(a[j]<a[j-1])
			{
				
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
		printf("pass %d list --->: ",i+1);
		for(k=0;k<n;k++)
		printf("%d",a[k]);
		puts("");
		
	}
	printf("\nno of cmprisns=%d\n",c);
	printf("the sorted list is \n");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	
}
