//stacks
#include<stdio.h>
#include<stdlib.h>

char s[20];
int top=-1;

void push (char i)
{
	if(top>=20)
	printf("over flow\n");
	else
	{
		top++;
		s[top]=i;
	}
	
}
int getsize()
{	if(top>-1)
	return top+1;
	
}
void main()
{	int op=0,p,i,n;
	char a[10],ch;
	printf("enter string");
	while(1)
	{	
		scanf("%c",&ch);
		if(ch=='\n'||ch==' ')
		break;
		else
		push(ch);
		
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
