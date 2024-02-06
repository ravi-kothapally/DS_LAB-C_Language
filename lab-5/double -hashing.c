#include<stdio.h>
#include<stdlib.h>
int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},c=0;
void insert(int v)
{
	int i=0,k;
	while(i<9)
	{
		k=((v%10)+i*(v%8))%10;
		if(a[k]==-1)
		{
			a[k]=v;c++;
			break;
		}
		else
		i++;
	}
}
int search(int v)
{
	int i=0,k;
	while(i<9)
	{
		k=((v%10)+i*(v%8))%10;
		if(a[k]==v)
		{
			return 1;
		}
		else
		i++;
	}
	return 0;
}

int main()
{
	int i,n,op,k,e;
	do{
	
	printf("                  1.insert (max 10)           2.search\n");
	printf("                  3.array             4.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: 	if(c<10)
		{
		
			printf("enter element\n");
				scanf("%d",&n);
				insert(n);
				
			
		}
		else
			puts("max elements\n");
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
