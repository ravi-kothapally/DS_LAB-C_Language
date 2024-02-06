#include<stdio.h>
#include<stdlib.h>
	int a[10]={0,0},c=0;

void insert(int n)
{
	int i=0,j;
	
	while(1){
		j=(n+i*i)%10;

		if(a[j]==0)
		{
		a[j]=n;
		break;
	}
		else
		i++;
			c++;
	}

}
int search(int n)
{
	int i=0,j=0,k,t;
	int booli[10]={0};
	printf("%d is n\n",n);
		while(1)
		{
			t=0;
			for(k=0;k<10;k++)
			{
				if(booli[k]==0)
				{
					t=1;
				}
			}
			if(t!=1)
			{
				return 0;
			}
			
			j=(n+i*i)%10;
			booli[j]=1;
			if(a[j]==n)
			return 1;
			else
			i++;
			
			
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
