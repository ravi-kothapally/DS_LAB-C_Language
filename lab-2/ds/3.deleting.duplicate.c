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
	struct node *new,*root,*temp2,*pre;
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
	
	//main deletion code
	while(temp!=0)
	{	
		temp2=temp->next;//important
		pre=temp;//important
		while(temp2!=0)
		{	
			if(temp2->n==temp->n)
			{
				pre->next=temp2->next;
				
			}
			else{
			
				pre=temp2;//important
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
	//end
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
