#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int n;
	struct node *next;
}*root,*temp;
struct node* create()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->pre=NULL;
	new->next=NULL;
	return new;
}
void main()
{
	int i,n,op;
	struct node *new,*root;
	temp=root;
	printf("enter the number of employees");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{  	
	
		new=create();
			scanf("%d",&new->n);
			if(i==0)
			temp=root=new;
			else{
		temp->next=new;
		new->pre=temp;
		temp=temp->next;
		}
	}
	temp=root;
	for(i=1;i<n+1;i++)
	{printf("%d",temp->n);
	temp=temp->next;
	}
	
}
	
