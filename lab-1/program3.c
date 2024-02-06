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
	int n,i,op,k;
	struct node *new,*root,*temp;
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
	       struct node *nex,*pre;
		
		pre=NULL;
		while(temp!=NULL)
		{
			nex=temp->next;
			temp->next=pre;
			pre=temp;
			temp=nex;
		}
		root=pre;
	temp=root;
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	printf("\n");	
}
