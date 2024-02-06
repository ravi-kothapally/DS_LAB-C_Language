//stacks
#include<stdio.h>
#include<stdlib.h>

char s[20];
int top=-1;

char push (char i)
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
		
		
		return s[top--];
	}
	
}
	
void display()
{	int i;
	if(top!=-1)
	{
		for(i=0;i<=top;i++)
		{
      		 printf("%c",s[top-i]);
		
		}
	}	
	
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
	{	return s[top];
	}
	
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
{	int op,p,i=0,j=0;
	char ch,c,c1,c2,c3,a[30];
	printf("enter infix equation=");
	scanf("%s",a);
	while(1)
	{	
		ch=a[j];
		if(ch=='\0')
		break;
		if(ch=='(')
		push(ch);	
		if(ch>='0'&&ch<='9')
		printf("%c",ch);
		if(ch==')')
		{	
			while(top!=-1)
			{
				c=pop();
				if(c=='(')
				{
					break;
				}
				else
				printf("%c",c);
			}
			
		}
		
		if(ch=='+'||ch=='-'||ch=='*'||ch=='%'||ch=='/')
		{
			c=gettop();
			if(top!=-1)
			{	if(c!='(')
				{	if(ch=='+'||ch=='-')
					{
						if(c=='+'||c=='-'||c=='*'||c=='%'||c=='/')
						{	while(top!=-1)
							{	
								c1=pop();
								if(c1!='(')
								printf("%c",c1);
								else
								break;
							}
							push(ch);
						}
					}
					if(ch=='*'||ch=='%'||ch=='/')
					{
						if(c=='*'||c=='%'||c=='/')
						{
							while(top!=-1)
							{	
								c1=pop();
								if(c1!='('||c!='+'||c!='-')
								printf("%c",c1);
								else		
								break;							
							}
							push(ch);
						}
						if(c=='+'||c=='-')
						{
							push(ch);
						}
					}
				}
				else 
				push(ch);
			}
			else
			push(ch);
				
				
						
		}
		j++;
	}
	display();
	printf("\n");
}


