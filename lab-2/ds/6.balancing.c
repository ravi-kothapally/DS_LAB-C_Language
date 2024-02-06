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
void main()
{	
	int i,p=0;
	char a[20],ch,c;
	printf("enter infix equn");
	scanf("%s",a);
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
		}
	}
	
	if(p==1&&top==-1)
	puts("correct\n");
	else
	puts("incorrect\n");
}

