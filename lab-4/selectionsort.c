#include<stdio.h>
int main()
{
	int a[10],i,j,t,n,min,k,c=0;
	printf("size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min=9999;
		for(j=i;j<n;j++)
		{c++;
			if(a[j]<min)
			{
				min=a[j];
				k=j;
			}
		}
			t=a[k];
				a[k]=a[i];
				a[i]=t;
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
