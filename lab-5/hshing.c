#include<stdio.h>
#include<stdlib.h>
int c=0,k;
struct node {
	int data;
	struct node *next;
}*newa,*temp[10],*a[10],*t1,*t2,*t;
struct node *create()
{
	newa=(struct node*)malloc(sizeof(struct node));
	return newa;
}
void insert(int n)
{
	int i;
	i=n%10;
	newa=create();
	newa->data=n;
	newa->next=0;
	if(a[i]->next==0)
	{
		a[i]->next=newa;
		temp[i]=newa;
	}
	else
	{
		temp[i]->next=newa;
		temp[i]=temp[i]->next;
	}
	c++;
}
int search(int n)
{
	int i;
	i=n%10;
	t=a[i]->next;
	while(t!=0)
	{
		if(n==t->data)
		return 1;
		t=t->next;
	}
	
}
void main()
{
	int i,n,e,op;
	for(i=0;i<10;i++)
	{
		a[i]=create();
		a[i]->next=NULL;
	}
	do{
	
					printf("						1.insert                    2.search \n");
					printf("						3.hash table			4.exit\n");
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
										for(i=0;i<c;i++)
										{
											t=a[i]->next;
											while(t!=0)
											{
												printf("%d ",t->data);
												t=t->next;
											}
											printf("\n");
										}
								}
								else
								puts("insert elements first");
								break;
						default: puts("invalid option yaar");		
							
						 		
								
										
								
						}
	}while(op!=4);
}
