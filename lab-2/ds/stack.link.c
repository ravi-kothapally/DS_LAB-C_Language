#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
	}*temp,*new,*top;
int c=0;
struct node * create()
{
	new=(struct node*)malloc(sizeof(struct node));
	return new;
}
void push(int i)
{
	if(top==NULL)
	{
		top=create();
		top->next=0;
		top->n=i;
	}
	else
	{
		temp=create();
		temp->next=top;
		temp->n=i;
		top=temp;
	}
	c++;
}
struct node* pop()
{
	if(c==0)
	printf("no elments\n");
	else
	{ 	c--;
		printf("%d is deleted\n",top->n);
	 	top=top->next;
	}
	
}
void peep(int p)
{	int i;
	temp=top;
	if(p>0&&p<=c)
	{	
		for(i=1;i<p;i++)
		temp=temp->next;
		printf("%d",temp->n);
		
	}
	else
	printf("invalid option\n");
}
void display()
{
	
    temp = top;
 
    if (temp== NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (temp!= NULL)
    {	printf("               |             |\n");
        printf("               |     %d       |\n",temp->n);
	printf("               |_____________|\n");
        temp = temp->next;
    }
 printf("\n");
}
void change(int p,int v)
{
	int i;
	temp=top;
	if(p>0&&p<=c)
	{
		for(i=1;i<p;i++)
		temp=temp->next;
		temp->n=v;
	}
	else
	printf("invalid position\n");

}
int getsize()
{
	return c;
}
struct node* gettop()
{
	if(c>0)
	return top;
	else
	puts("no elements");	
}
int isem()
{
	if(c==0)
	return 0;
	else
	return 1;
}
int isfu()
{
	
	return 1;
}
void main()
{
	int i,op,p,v;
	top=NULL;
	do{
	printf("		selct\n");
	printf("		1.push       2.pop             3.display\n");
	printf("		4.change     5.peep            6.getsize\n");
	printf("		7.get top    8.is stack empty  9.is stack full\n		10.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: printf("element to be pushed");
			scanf("%d",&i);
			push(i);
			break;
		case 2:	pop();
			break;
		case 3: display();
			break;
		case 4: printf("position");
			scanf("%d",&p);
			printf("value");
			scanf("%d",&i);
			change(p,i);
			break;
		case 5: printf("enter positon");
			scanf("%d",&p);
			peep(p);
			break;
		case 6: printf("%d is size\n",getsize());
			break;
		case 7: new=gettop();
			printf("top is %d\n",new->n);
			break;
		case 8: p=isem();
			if(p==0)
			printf("true\n");
			else
			printf("false\n");
			break;
		case 9:p=isfu();
			if(p==0)
			printf("true\n");
			else
			printf("false\n");
			break;
		

	}
	}while(op!=10);
}		

