#include<stdio.h>
#include<stdlib.h>
int q[6];
int r=-1,f=-1;
void insert(int v)
{
	if(r==5&&f==0||r==f-1)
	{
	   printf("over flow\n");
		exit(1);
	}
	if(r==5)
	r=0;
	else
	r=r+1;
	q[r]=v;
	if(f==-1)
	f=0;

}
int delete()
{	int y;
	if(f==-1)
	{
	  printf("under flow\n");
		exit(2);
	}
	y=q[f];
	if(f==r)
	f=r=-1;
	else if(f==5)
	f=0;
	else if(f=f+1)
	return y;
}
void display()
{	int i;
   if(f<=r)
   {
     for(i=f;i<=r;i++)
		printf("%d",q[i]);
	}
	else
	{
		for(i=f;i<5;i++)
			printf("%d",q[i]);
		for(i=0;i<=r;i++)
			printf("%d",q[i]);
	}
}
void main()
{
	int op,v;
	do{
		printf("select\n");
		printf("1.insert        2.delete         4.display          5.exit");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("new elemnet\n");
					scanf("%d",&v);
					insert(v);
					break;
			case 2: delete();
					break;
			case 4: display();
					break;
			default: puts("invalid\n"); 
		}
		
	}while(op!=5);
}







