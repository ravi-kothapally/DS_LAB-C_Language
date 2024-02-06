#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int n;
	struct node *next;
}
*temp,*root,*new;

struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->pre=NULL;
	new->next=NULL;
	return new;
	
}
struct node* createDCLL(struct node* roo,int n)
{
	int i;
	temp=roo;
	for(i=0;i<n;i++)
	{		
		scanf("%d",&temp->n);
		if(i<n-1)
		{	
			new=create();
			temp->next=new;
			new->pre=temp;
			temp=temp->next;
		}
	}
	temp->next=roo;
	roo->pre=temp;
	return roo;
}
void main()
{	
	int n,n2;
	struct node *root2;
	root=create();
	printf("no of nodes in 1st DCLL");
	scanf("%d",&n);
	root=createDCLL(root,n);
	temp=root;
	root2=create();
	printf("no of nodes in 2nd DCLL");
	scanf("%d",&n);
	root2=createDCLL(root2,n);
	temp=root;
	printf("\n1st DCLL is :");
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==root)
		break;
		temp=temp->next;
	}
	printf("\n2nd DCLL is :");
	temp=root2;
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==root2)
		break;
		temp=temp->next;
	}
	temp=root;
	while(temp->next!=root)
	temp=temp->next;
	temp->next=root2;
	root2->pre=temp;
	temp=root2;
	while(temp->next!=root2)
	temp=temp->next;
	temp->next=root;
	root->pre=temp;
	temp=root;
	printf("\ncombined DCLL is :");
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==root)
		break;
		temp=temp->next;
	}


}
