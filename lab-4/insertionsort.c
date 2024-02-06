#include<stdio.h>
void main()
{
	int a[10],i,j,t,n,c=0,k,m,n1;
	printf("size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{	t=a[i];m=0;n1=0;
		for(j=i;j>0;j--)
		{c++;
		
			if(t<a[j-1])
			{
				m=j-1;n1=1;
				a[j]=a[j-1];
				
			}
			
		}
		if(n1==1)
		{
			a[m]=t;
		}
		
		printf("pass %d list --->: ",i);
		for(k=0;k<n;k++)
		printf("%d",a[k]);
		puts("");
	}
		printf("\nno of cmprisns=%d\n",c);
	printf("the sorted list is \n");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	
}
