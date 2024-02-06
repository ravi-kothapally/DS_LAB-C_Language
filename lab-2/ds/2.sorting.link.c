#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}*temp;
struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	return new;
	
}
void main()
{
	int n,i,op,k,t;
	struct node *new,*root,*temp2,*pre;
	root=create();
	temp=root;
	new=create();
	
	printf("no of nodes");
	scanf("%d",&n);
	puts("elemements");
	for(i=0;i<n-1;i++)
	{
		new=create();
		scanf("%d",&temp->n);
		temp->next=new;
		temp=new;
		
	}
	scanf("%d",&temp->n);
	temp->next=NULL;
	temp=root;
	
	while(temp!=0)
	{	
		temp2=temp->next;
		while(temp2!=0)
		{	
			if(temp->n>temp2->n)
			{
				t=temp->n;
				temp->n=temp2->n;
				temp2->n=t;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}temp=root;
	while(temp!=0)
	{
		printf("[ %d ]-->",temp->n);
		temp=temp->next;
	}
	printf("0\n");
}
	
		
	
