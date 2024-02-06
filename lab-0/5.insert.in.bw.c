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
	temp=create();
	root=temp;

	printf("no of nodes");
	scanf("%d",&n);
	puts("elemements\n");
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
	printf("elements are\n");
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	temp=root;
	printf("\nnew element position\n");
	scanf("%d",&n);
	for(i=1;i<n-1;i++)
	{
		temp=temp->next;
	}
	newer->next=temp->next;
	temp->next=newer;
	printf("new element\n");
	scanf("%d",&newer->n);
	printf("elements are\n");
	temp=root;
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	
	
}
	

		
	
	
