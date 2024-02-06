#include<stdio.h>
#include<stdlib.h>
struct node{
	char n;
	struct node *next;	
	}*root,*temp,*new;

struct node* create()
{
	new=(struct node*)malloc(sizeof(struct node));
	return new;
}

void main()
{
	int i=1,n,c=0;
	char ch;
	struct node *pre=0,*nex,*root2,*temp2;
	root=create();
	temp=root;
	printf("enter a string");
	scanf("%c",&temp->n);
	while(1)
	{
		scanf("%c",&ch);
		if(ch!='\n')
		{	
				new=create();
				temp->next=new;
				temp=new;
				new->n=ch;
				i++;
		}
		else
		break;
	}
	temp->next=NULL;
	n=i/2;
	temp=root;
	for(i=1;i<n;i++)
	{	
		temp=temp->next;
	}
	temp2=temp->next;
	temp->next=0;
	
		pre=NULL;	
	while(temp2!=0)
	{
		nex=temp2->next;
		temp2->next=pre;
		pre=temp2;
		temp2=nex;
	}
	root2=pre;
	temp2=root2;
	temp=root;i=0;
	while(i<n)
	{
		if(temp->n==temp2->n)
		{
			c=1;
		}
		else
		{
			c=0;
			break;
		}
		temp=temp->next;
		temp2=temp2->next;
		i++;	
	}
	temp2=root2;
	pre=0;
	while(temp2!=0)
	{
		nex=temp2->next;
		temp2->next=pre;
		pre=temp2;
		temp2=nex;
	}
	root2=pre;
	temp=root;
	for(i=1;i<n;i++)
	{	
		temp=temp->next;
	}
	temp->next=root2;
	
	temp=root;
	while(temp!=0)
	{
		printf("%c",temp->n);
		temp=temp->next;
	}
	if(c==0)
	printf(" is not a palindrone\n");
	else
	printf("is a palindrone\n");
}

		
		
	
	

