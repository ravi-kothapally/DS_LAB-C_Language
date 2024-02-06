#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int n;
	struct node * next;
	}*f=0,*r=0,*ew,*f1;

struct node* create()
{
	ew=(struct node*)malloc(sizeof(struct node));
	ew->next=0;
	ew->pre=0;
	return ew;
}
void insertf(int i)
{
	ew=create();
	ew->n=i;
	ew->next=f;
	r->next=ew;
	f->pre=ew;
	ew->pre=r;
	f=ew;
}
void insertr(int i)
{
	if(f==0)
	{
			ew=create();
			ew->n=i;
			f=r=ew;
	}
	else
	{
		ew=create();
		ew->n=i;
		r->next=ew;
		ew->pre=r;
		r=ew;
		r->next=f;
		f->pre=r;
	}
	
}

void eletef()
{
	printf("%d is deleted ",f->n);
	f=f->next;
}
void eleter()
{
	printf("%d is deleted \n",r->n);
	r=r->pre;
}
void display()
{
		f1=f;
	if(f==0)
	printf("no elements");
	else
	{
		while(1)
		{
			printf("%d",f1->n);
			if(f1==r)
			break;
			f1=f1->next;
			
		}
	}
}
int main()
{
	int op,i;
	do{
	
		printf("select");
		printf("1.insert last       2.delete front\n");
		printf("3.insert front        4.delete last \n");
		printf("5.display            6.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 3 : printf("enter element");
					 scanf("%d",&i);	
					 insertf(i);
					 break;
			case 2 : eletef();
					 break;
			case 1 : printf("enter element");
					 scanf("%d",&i);
					 insertr(i);
					 break;
			case 4 : eleter();
			case 5 : display();
		}
	}while(op!=6);
}
