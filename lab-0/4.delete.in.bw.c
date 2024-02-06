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
	for(i=0;i<n-1;i++)
	{
		new=(struct node*)malloc(sizeof(struct node));
		puts("elemement");
		scanf("%d",&temp->n);
		temp->next=new;
		temp=temp->next;
		
	}
        printf("element");
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
	printf("position");
	scanf("%d",&p);
	for(i=1;i<p-1;i++)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
	//temp->next->next=NULL;
	//free(temp->next->next);
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
	

		
	
	
