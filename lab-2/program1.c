//stacks
#include<stdio.h>
#include<stdlib.h>

int s[20];
int top=-1;

void push (int i)
{
	if(top>=20)
	printf("over flow\n");
	else
	{
		top++;
		s[top]=i;
	}
	
}

int pop()
{	
	if(top==-1)
	{ 
		printf("under flow\n");
	
	}
	else
	{
		
		
		printf("%d is deleted\n",s[top--]);
	}
	
}
	
void display()
{	int i;
	if(top!=-1)
	{
		for(i=0;i<=top;i++)
		{printf("               |             |\n");
      		 printf("               |     %d       |\n",s[top-i]);
		 printf("               |_____________|\n");
		}
	}	
	else	
	printf("no elements to display");
	printf("\n");
}
void change(int p,int v)
{
	if(top!=-1){	
	if(p>0&&p<=top+1)
	{s[top+1-p]=v;
	printf("%d",top);}
	else
	printf("invalid position\n");}
	else
	printf("no elements");
}
int peep(int p)
{	if(top!=-1)
	{if(p>0&&p<=top+1)
	printf("%d",s[top+1-p]);
	else
	printf("INVALID POSITION\n");}
	else
	printf("no elements\n");
}
int getsize()
{	if(top>-1)
	printf("%d is size \n",top);
	else
	printf("no elemnets in stack\n");
}
int gettop()
{	
	if(top>-1)
	{	printf("%d is top\n",s[top]);
	}
	else
	printf("no elements\n");
}
int isem()
{
	if(top==-1)
	return 0;
	else
	return 1;
}
int isfu()
{
	if(top==19)
	return 0;
	else
	return 1;
}
void main()
{	int op,p,i;
	do{
	printf("select\n");
	printf("		1.push         2.pop        3.display     4.change\n");
	printf("		5.peep         6.getsize    7.gettop      8.is stack empty \n");
	printf("		9.stack full  10.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: printf("enter element");
			scanf("%d",&i);
			push(i);
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: printf("position and value please");
			scanf("%d %d",&p,&i);
			change(p,i);
			break;
		case 5: printf("position");
			scanf("%d",&p);
			peep(p);
			break;
		case 6: getsize();
			break;
		case 7: gettop();
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
