#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}
*temp;

struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	return new;
	
}
void main()
{	
	int n,i,op,k;
	struct node *new,*root,*temp,*s,*o;
	root=create();
	temp=root;
	printf("no of nodes");
	scanf("%d",&n);
	puts("elemements");
	for(i=0;i<n-1;i++)
	{
		new=create();
		
		scanf("%d",&temp->n);
		temp->next=new;
		temp=temp->next;
		
	}
	scanf("%d",&temp->n);
	temp->next=NULL;
	temp=root;
	
	o=temp->next;
	while(temp->next->next!=NULL)
	{
		s=temp->next;
		temp->next=temp->next->next;
		temp=s;
	
	}
	temp->next=NULL;
	temp=root;
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}
	printf("\n");
	temp=o;
	while(1)
	{
		printf("%d",temp->n);
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}

}

	
               






















