#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}
*temp,*root,*new;

struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	return new;
	
}
struct node* createCLL(struct node* roo,int n)
{
	int i;
	temp=roo;
	for(i=0;i<n;i++)
	{		
		scanf("%d",&temp->n);
		if(i<n-1)
		{	new=create();
			temp->next=new;
			temp=new;
		}
	}
	temp->next=roo;
	return roo;
}
void main()
{	
	int n,n2;
	struct node *root2;
	root=create();
	printf("no of nodes in 1st CLL");
	scanf("%d",&n);
	root=createCLL(root,n);
	temp=root;
	root2=create();
	printf("no of nodes in 1st CLL");
	scanf("%d",&n);
	root2=createCLL(root2,n);
	temp=root;
	printf("\n1st CLL is :");
	while(1)
	{
		printf("%d\t",temp->n);
		if(temp->next==root)
		break;
		temp=temp->next;
	}
	printf("\n2nd CLL is :");
	temp=root2;
	while(1)
	{
		printf("%d\t",temp->n);
		if(temp->next==root2)
		break;
		temp=temp->next;
	}
	temp=root;
	while(temp->next!=root)
	temp=temp->next;
	temp->next=root2;
	temp=root2;
	while(temp->next!=root2)
	temp=temp->next;
	temp->next=root;
	temp=root;
	printf("\ncombined CLL is :");
	while(1)
	{
		printf("%d \t",temp->n);
		if(temp->next==root)
		break;
		temp=temp->next;
	}


}	
	
