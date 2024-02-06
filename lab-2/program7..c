#include<stdio.h>
#include<stdlib.h>
int q[100];
int r=-1,f=-1;
void insert(int v)
{
	if(r==100)
	{
	   printf("over flow\n");
		exit(1);
	}
	q[++r]=v;
	if(f==-1)
	f++;

}
int delete()
{	int y;
	if(f==-1||f-1==r)
	{
	  printf("under flow\n");
		exit(2);
	}
	y=q[f];
	f=f+1;
	return y;
}
void display()
{	int i;
	if(f-1!=r)
	{
	
			for(i=f;i<=r;i++)
			printf("|%d  |\n",q[i]);
	}
	else
	puts("no elements\n");
}
void main()
{
	int op,v;
	do{
		printf("select\n");
		printf("				1.insert        2.delete         3.display          4.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("new elemnet\n");
					scanf("%d",&v);
					insert(v);
					break;
			case 2: delete();
					break;
			case 3: display();
					break;
			default: puts("invalid\n"); 
		}
		
	}while(op!=5);
}







