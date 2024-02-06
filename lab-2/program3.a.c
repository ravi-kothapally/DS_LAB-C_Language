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
	return top+1;
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
{	int op=0,p,i,n;
	printf("enter number");
	scanf("%d",&n);
	while(n!=0)
	{
		i=n%10;
		n=n/10;
		push(i);
	}
	p=getsize();
	for(i=0;i<p/2;i++)
	{
		if(s[i]==s[top-i])
		op=1;
		else
		{
			op=0;
			break;
		}
	}
	if(op==0)
	printf("not palindrome");
	else
	printf("palindrome");
}
