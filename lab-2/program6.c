#include<stdio.h>
#include<stdlib.h>
int s[20];
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
      		 printf("%d",s[top-i]);
		
		}
	}	
	
}

int gettop()
{	
	if(top>-1)
	{	return s[top];
	}
	
}
int convert(char ch)
{
	return ch-48;
}
int pw(int f,int s)
{	int i,r=1;
	for(i=1;i<=s;i++)
	r=r*f;
	return r;
}
void main()
{	int k,i,se,fi,r;
	char a[20],ch;
	printf("enter postfix eqn");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{	
		ch=a[i];
		if(ch>47&&ch<57)
		{	
			k=convert(ch);
			push(k);
		}
		else
		{
			se=pop();
			fi=pop();
				if(ch=='+')
				{
					r=fi+se;
				}
				if(ch=='-')
				r=fi-se;
				if(ch=='%')
				r=fi%se;
				if(ch=='*')
				r=fi*se;
				if(ch=='/')
				r=fi/se;
				if(ch=='^')
				r=pw(fi,se);
				push(r);
		}z
	}
	display();
}
