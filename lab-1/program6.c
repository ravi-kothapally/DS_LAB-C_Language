#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int n;
	struct node *next;
}*root,*temp,*new;
struct node* create()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->pre=NULL;
	new->next=NULL;
	return new;
}
void main()
{
	int i,n;
	root=create();
	temp=root;
	printf("enter the number of employees");
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{  	
		scanf("%d",&temp->n);
		new=create();
		temp->next=new;
		new->pre=temp;
		temp=temp->next;
	}
	scanf("%d",&temp->n);
	temp->next=root;
	root->pre=temp;
	temp=root;
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==root)
		break;
		temp=temp->next;
	}
	root=temp;
	temp=root;
	printf("\nreverse of double circular linked list is\n");
	while(1)
	{
		printf("%d",temp->n);
		if(temp->pre==root)
		break;
		temp=temp->pre;
	}
	
}
