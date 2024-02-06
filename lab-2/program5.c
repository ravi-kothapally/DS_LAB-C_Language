//stacks
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int gettop()
{	
	if(top>-1)
	{	return s[top];
	}
	
}
int operator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%')
	return 1;
	return 0;
}
int prec(char op)
{
		switch(op)
		{	case '(':return -2;
			case '^':
				return -1;
			case '+':
			case '-':
				return 1;
			case '*':
			case '/':
			case '%':
				return 2;
			
			default : return 0;		
		}
}
int balance(char a[])
{	int i,p=1;
	char ch,c;
	for(i=0;a[i]!='\0';i++)
	{
		ch=a[i];
		if(ch=='('||ch=='{'||ch=='[')
		push(ch);
		else if(ch==')'||ch=='}'||ch==']')
		{
			if(top!=-1)
			{
				c=pop();
				if(c=='('&&ch==')'||c=='{'&&ch=='}'||c=='['&&ch=='}')
				{
					p=1;
				}
				else
				{	
					p=0;
					break;
				}
			}
			else
			{p=0;break;}
		}
	}
	
	if(p==1&&top==-1)
	return 1;
	else
	return 0;
}

void main()
{	int j=0,k,p;
	char ch,c,c3,a[30],b[10];
	printf("enter infix equation=");
	scanf("%s",a);
	if(balance(a))
	{
		while(1)
		{	
			ch=a[j];
			if(ch=='\0')
			break;
			if(ch=='(')
			push(ch);	
			if(ch>='0'&&ch<='9')
			{	k=0;
				/*while(a[j]!=' ')
				{
					b[k]=a[j];
					j++;
					k++;	
				}
				p=atoi(b);*/
				printf("%c",ch);	
			}
			else if(ch==')')
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
			else if(operator(ch))
			{	
				while(top!=-1)
				{
					c=gettop();
					if(prec(ch)<prec(c))
					printf("%c",pop());
					else
					{
						push(ch);	
						break;
					}
				}
				if(top==-1)
				push(ch);

			}
		j++;
		
		}
		display();
	}
	else
	puts("incorrect equn");
}

		


