#include<stdio.h>
#include<stdlib.h>
	int a[10]={0},c=0;
void insert(int n)
{
	int i;
	i=n%10;
	while(a[i]!=0){
	if(i==9)
	i=0;
	else
	i++;}
	a[i]=n;
	c++;
}
int search(int n)
{
	int i,c=0;
	i=n%10;

		while(c<10)
		{
			if(a[i]==n)
			return 1;
			else
			if(i==9)
			i=0;
			else
			i++;
			c++;
		}
	
}
int main()
{
	int i,n,op,k,e;
	do{
		if(c==10)
		{
			puts("max elements\n");
			
		}
	printf("                  1.insert (max 10)           2.search\n");
	printf("                  3.array             4.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: printf("enter element\n");
				scanf("%d",&n);
				insert(n);
				break;
		case 2: if(c>0)
				{
					printf("enter search element\n");
					scanf("%d",&n);
					e=search(n);
					if(e==1)
					puts("found");
					else
					puts("not found");
				}
				else
				puts("insert elements first");
				break;
		case 3: if(c>0)
				{
				for(i=0;i<10;i++)
				{
					printf("%d  ",a[i]);
				}
				}
				else
				puts("insert elements first");
				break;
		default: puts("invalid option yaar");	
	}
	}while(op!=4);
}
