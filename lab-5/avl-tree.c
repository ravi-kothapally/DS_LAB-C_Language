#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node{
	struct node *pre;
	int n;
	int h;
	int bal;
	struct node *parent;
	struct node *next;
}*root=NULL,*newa,*temp,*t,*h,*p,*a[10],*x,*y,*z,*t1,*t2,*t3,*t4,*father;
struct node * create()
{	int i;
	newa=(struct node *)malloc(sizeof(struct node));
	newa->pre=NULL;newa->next=NULL;
	printf("enter element\n");
	scanf("%d",&i);
	newa->n=i;
				if(c==0)
				{
				root=newa;
				root->parent=0;
				}
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
								newa->parent=temp;
								break;
							}
							temp=temp->pre;
						}
						else
						{	
							if(temp->next==NULL)
							{
							
							temp->next=newa;
								newa->parent=temp;
							break;
							}
							temp=temp->next;
						}
					}
					
				}
			c++;
			return newa;
}
void preorder(struct node *roo)
{
	if(roo!=NULL){
			printf("%d ",roo->n);
		preorder(roo->pre);
		preorder(roo->next);
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
struct node * delet(int i)
{
	struct node	*pre,*del;
	int pl=0,hl=0;
	pre=root;
	temp=root;
	if(temp->n==i)
	{del=temp;
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
			return del;
	}
	while(temp!=0)
	{	
	
		if(temp->n==i)
		{	del=temp;
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
	return del;
}
int height(struct node *temp)
{
	int h=0;
	while(temp!=0)
	{
		h++;
		if(temp->pre!=0)
		{
		temp=temp->pre;}
		else if (temp->next!=0)
		{
		temp=temp->next;}
		else
		break;
	}
	return h;
}
void fillbal(struct node *temp)
{
	int l=0,r=0,c;
	if(temp!=0)
	{
		if(temp->pre!=0)
		{
		c=height(temp->pre);
		l=c;}
		if(temp->next!=0)
		{
		
		r=height(temp->next);}
	
	temp->bal=l-r;
	if(l>=r)
	temp->h=l;
	else
	temp->h=r;
	fillbal(temp->pre);
	fillbal(temp->next);
	}
}
int isavl(struct node *temp)
{
		if(temp!=0)
	{
		if(temp->bal>1||temp->bal<-1)
		{
		return -1;}
		isavl(temp->pre);
		isavl(temp->next);
	}
	return 0;
}
void ll(struct node *z)
{
	y=z->pre;
	x=y->pre;
	t3=y->next;
	y->pre=x;
	y->next=z;
	z->pre=t3;
	if(z==root)
	{
	root=y;
	root->parent=0;
}
	else
	{
		father=z->parent;
		if(father->pre==z)
		{
		father->pre=y;}
		else
		{
		father->next=y;}
		y->parent=father;
	}
		z->parent=y;
		if(t3!=0)
		t3->parent=z;
		
	
}
void rr(struct node *z)
{
	y=z->next;
	x=y->next;
	t2=y->pre;
	y->pre=z;
	y->next=x;
	z->next=t2;
	if(z==root)
	{
	root=y;
	root->parent=0;
}
	else
	{
		father=z->parent;
		if(father->pre==z)
		{
		father->pre=y;}
		else
		{
		father->next=y;}
		y->parent=father;
	}
		z->parent=y;
		if(t2!=0)
		t2->parent=z;
		
	
}
void lr(struct node *z)
{
	y=z->pre;
	x=y->next;
	t2=x->pre;
	t3=x->next;
	x->pre=y;
	x->next=z;
	y->next=t2;
	z->pre=t3;
	if(z==root)
	{	
	root=x;
	root->parent=0;
}
	else
	{
		father=z->parent;
		if(father->pre==z)
		{
		father->pre=x;}
		else
		{
		father->next=x;}
		x->parent=father;
	}
		y->parent=x;
		z->parent=x;
		if(t3!=0)
		t3->parent=z;
		if(t2!=0)
		t2->parent=y;
		
	
}
void rl(struct node *z)
{
	y=z->next;
	x=y->pre;
	t2=x->pre;
	t3=x->next;
	x->pre=z;
	x->next=y;
	y->pre=t3;
	z->next=t2;
	if(z==root)
	{	
	root=x;
	root->parent=0;
}
	else
	{
		father=z->parent;
		if(father->pre==z)
		{
		father->pre=x;}
		else
		{
		father->next=x;}
		x->parent=father;
	}
		y->parent=x;
		z->parent=x;
		if(t3!=0)
		t3->parent=y;
		if(t2!=0)
		t2->parent=z;
}
void doavl(struct node *temp)
{
int i=-1,n;
	while((temp->bal>=-1&&temp->bal<=1))
	{
					i++;
		a[i]=temp;
		if(temp!=root)
		temp=temp->parent;
		else
		break;
	}
	n=i;
	if(temp->pre==a[n])
	{
			if(a[n]->pre==a[n-1])
			ll(temp);
			else
			lr(temp);
	}
	else if (temp->next==a[n])
	{
			if(a[n]->pre==a[n-1])
			rl(temp);
			else
			rr(temp);
	}
}
void doavldele(struct node *temp)
{
	int l=0,h=0,f,g;
	int n;
	while(abs(temp->bal)<=1)
	{	
		temp=temp->parent;
		if(temp==root)
		{	
		break;}
	}
	int i=0;
	t=temp;
/*	while(i<2){
		h=0;
		l=0;
		f=0;
		g=0;
		puts("4");
		if(temp->pre!=0)
		{f=1;
		l=temp->pre->h;}
		else
		a[i]=temp->next;
		if(temp->next!=0)
		{g=1;
		h=temp->next->h;}
		else
		{puts("rs");
		a[i]=temp->pre;}
		printf("\n>>>>>>>>>>%d %d\n",l,h);
		if(f==1&&g==1)
		{
		puts("F");
	if(l>h)
	a[i]=temp->pre;
	else
	a[i]=temp->next;
}
	printf("%d",a[i]->n);
	temp=a[i];
	i++;
}*/
/*	n=1;
temp=t;
	if(temp->pre==a[0])
	{
			puts("m3");
			if(a[0]->pre==a[1])
			ll(temp);
			else
			lr(temp);
	}
	else if (temp->next==a[0])
	{
		puts("gggg");
			if(a[0]->pre==a[1])
			rl(temp);
			else
			rr(temp);
	}*/
	if(temp->bal>1)
	{
		if(temp->pre->bal>=0)
		ll(temp);
		else
		lr(temp);
	}
	else if(temp->bal<-1)
	{
		if(temp->next->bal<=0)
		rr(temp);
		else
		rl(temp);
	}
	
}
void main()
{
	int c=0,i,op,n,k,v=0;
	struct node *m;
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
				m=create();
				fillbal(root);
				v=isavl(root);
			
				while(v==-1)
				{
					doavl(m);
					fillbal(root);
					v=isavl(root);
				}
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
				m=delet(n);
				fillbal(root);
				v=isavl(root);
				while(v==-1) 
				{
					doavldele(m);
					fillbal(root);
					v=isavl(root);
				}
				break;
		default: printf("invalid option yaar\n");		
	}
	}
	while(op!=7);
}
