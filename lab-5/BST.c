#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node{
	struct node *pre;
	int n;
	struct node *next;
}*root=NULL,*newa,*temp,*t,*h,*p;
void create()
{	int i;
	newa=(struct node *)malloc(sizeof(struct node));
	newa->pre=NULL;newa->next=NULL;
	printf("enter element\n");
	scanf("%d",&i);
	newa->n=i;
				if(c==0)
				root=newa;
				else
				{
					temp=root;
					while(1)
					{
						if(i<=temp->n)
						{
					
							if(temp->pre==NULL)
							{
								temp->pre=newa;
								break;
							}
							temp=temp->pre;
						}
						else
						{	
							if(temp->next==NULL)
							{
							
							temp->next=newa;
							break;
							}
							temp=temp->next;
						}
					}
					
				}
			c++;
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d  ",root->n);
		preorder(root->pre);
		preorder(root->next);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
	
		inorder(root->pre);
		printf("%d  ",root->n);
		inorder(root->next);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{

 		postorder(root->pre);
		postorder(root->next);
		printf("%d  ",root->n);
	}
}
int search(int i)
{
	temp=root;
	while(temp!=NULL)
	{
		if(i==temp->n)
		{
			return 1;
			break;
		}
		if(i<temp->n)
		temp=temp->pre;
		if(i>temp->n)
		temp=temp->next;
	}
	return 0;
}
int delet(int i)
{
	struct node	*pre;
	int pl=0,hl=0;
	pre=root;
	temp=root;
	if(temp->n==i)
	{
			if(temp->next==0&&temp->pre==0)
			{
				c=0;
				root=0;
			}
			else if((temp->next!=0&&temp->pre==0)||(temp->next==0&&temp->pre!=0))
			{	
				if(temp->next!=0)
				root=root->next;
				else
				root=root->pre;
			}
			else if(temp->next!=0&&temp->pre!=0)
			{	
				h=root->pre;
				hl=0;
				while(h->next!=0)
				{
					hl=1;
						p=h;
						h=h->next;
				}
				
				root->n=h->n;
				if(hl==0)
				{
					root->pre=0;
				}
				else
				p->next=0;
			}
			return 1;
	}
	while(temp!=0)
	{	
	
		if(temp->n==i)
		{	
			pl=1;
			if(temp->next==0&&temp->pre==0)
			{	
				if(pre->next==temp)
				pre->next=0;
				else
				pre->pre=0;
				
			}
			else if((temp->next!=0&&temp->pre==0)||(temp->next==0&&temp->pre!=0))
			{
				if(temp->next!=0)
				{
					
					if(pre->next==temp)
					pre->next=temp->next;
					else
					pre->pre=temp->next;
					
				}
				else
				{
					
					if(pre->next==temp)
					pre->next=temp->pre;
					else
					pre->pre=temp->pre;
					
				}
			}
				else if(temp->next!=0&&temp->pre!=0)
			{
				h=temp->pre;
				hl=0;
				while(h->next!=0)
				{
					hl=1;
						p=h;
						h=h->next;
				}
				
				temp->n=h->n;
				if(hl==0)
				{
					temp->pre=0;
				}
				else
				p->next=0;
			}
			
			break;
		}
		
		pre=temp;
		if(i<temp->n)
		temp=temp->pre;
		if(i>temp->n)
		temp=temp->next;
	}
	
}
void main()
{
	int c=0,i,op,n,k;
	
	do{
	
												printf("				select\n");
												printf("				_________________________________________________________\n");
												printf("				| 1.create             |      2.preorder traversal       |\n");
												printf("				| 3.in-order traversal |      4.post order traversal     |\n ");
												printf("				| 5.search             |      6.delete an element        |\n");
												printf("				| 7.exit               |                                 |\n");
												printf("				|______________________|_________________________________|\n");
												scanf("%d",&op);
	switch(op)
	{
		case 1:
				create();
				break;
		case 2: preorder(root);
				break;
		case 3: inorder(root);
				break;
		case 4: postorder(root);
				break;
		case 5: printf("element to be searched=");
				scanf("%d",&i); 
				k=search(i);
				printf("k=%d",k);
				if(k)
				{
					printf("found\n");
				}
				else
				printf("not found\n");	
				break;
		case 6: printf("enter element to be deleted\n");
				scanf("%d",&n);
				delet(n);
				break;
		default: printf("invalid option yaar\n");		
					
						
	}
	}
	while(op!=7);
}
