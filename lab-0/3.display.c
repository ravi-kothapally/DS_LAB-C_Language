#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}*root,*temp;


struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	return new;
	
}
void main()
{ 	int n,i,s,c=0;
	struct node *new;
	root=(struct node*)malloc(sizeof(struct node));
	temp=root;
	printf("no of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new=(struct node*)malloc(sizeof(struct node));
		temp->next=new;
		temp=temp->next;
	}
	temp->next=NULL;
	temp=root;
		printf("enter elements ");
	while(temp->next!=NULL)
	{
		scanf("%d",&temp->n);
		temp=temp->next;
	}
	temp=root;
	printf("elements are\n");
	while(temp->next!=NULL)
	{
		printf("%d \t",temp->n);
		temp=temp->next;
	}
	temp=root;
	
}
	

		
	
	
