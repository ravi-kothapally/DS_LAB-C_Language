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
struct node* inserthead(struct node* root)
{	struct node *newer;
	newer=create();
	newer->next=root;
	root=newer;
	printf("add head");
	scanf("%d",&root->n);
	return root;
}
struct node* inserttail(struct node* root)
{
	struct node *newer;
	newer=create();
	temp=root;
	while(temp->next!=NULL)
	{	
		temp=temp->next;
	}
	temp->next=newer;
	newer->next=NULL;
	printf("new element at last");
	scanf("%d",&newer->n);
	return root;
}
struct node* insertbw(struct node* root)
{	int n,i;
	struct node *newer;
	newer=create();
	temp=root;
	printf("new element position\n");
	scanf("%d",&n);
	for(i=1;i<n-1;i++)
	{
		temp=temp->next;
	}
	newer->next=temp->next;
	temp->next=newer;
	printf("new element\n");
	scanf("%d",&newer->n);
	return root;
		
}
struct node* delhead(struct node* root)	
{
	temp=root;
	root=temp->next;
	temp->next=NULL;//deleting head
	free(temp);
	return root;
}
struct node* deltail(struct node* root)
{	temp=root;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		free(temp->next);
	return root;
}
struct node* delbw(struct node* root)
{	int p,i;
	temp=root;
	printf("position");
	scanf("%d",&p);
	for(i=1;i<p-1;i++)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
	return root;
}
int search(struct node*root)
{
	int se ,c=0;
	printf("enter search element");
	scanf("%d",&se);
	temp=root;
	while(1)
	{
		
		if(temp->n==se)
		{
		
			c=1;
			break;
		}
		if(temp->next==NULL)
		break;
		temp=temp->next;
		
		
	}
	return c;
}
void main()
{	
	int n,i,op,k;
	struct node *new,*root,*temp;
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
	do{
		printf("1.insert head\n2.insert tail\n3.insert between\n4.delete head\n5.delete tail\n6.delete between\n7.search\n8.exit");
		scanf("%d",&op);
		switch(op)
		{
			case 1: root=inserthead(root);
				break;
			case 2: root=inserttail(root);
				break;
			case 3: root=insertbw(root);
				break;
			case 4: root=delhead(root);
				break;
			case 5: root=deltail(root);
				break;
			case 6: root=delbw(root);
				break;
			case 7: k=search(root);
				if(k==0)
				{puts("not found");
				}
				else
				puts("found");
				break;
		
		}
		printf("elements are\n");
	temp=root;
	while(1)
	{
		printf("%d \t",temp->n);
                if(temp->next==NULL)
                break;
		temp=temp->next;
	}
	printf("\n");
	}while(op!=8);
	
	
	
}
