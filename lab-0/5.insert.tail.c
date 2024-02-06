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
{ 	int n,i,p;
	struct node *new,*newer;
	newer=create();
	temp=(struct node*)malloc(sizeof(struct node));
	root=temp;

	printf("no of nodes");
	scanf("%d",&n);
	puts("elemements\n");
	for(i=0;i<n-1;i++)
	{
		new=(struct node*)malloc(sizeof(struct node));
		
		scanf("%d",&temp->n);
		temp->next=new;
		temp=temp->next;
		
	}
        scanf("%d",&temp->n);
	temp->next=NULL;
	temp=root;
	printf("elements are\n");
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	temp=root;
	while(temp->next!=NULL)
	{	
		temp=temp->next;
	}
	temp->next=newer;
	newer->next=NULL;
	printf("new element at last");
	scanf("%d",&newer->n);
	temp=root;
	printf("elements are\n");
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	
	
}
	

		
	
	
