#include<stdio.h>
#include<stdlib.h>
int abs(int h)
{
	if(h>0)
	return h;
	else
	return h;
}
char a[3][3];
void print()
{
	int i,j;
			printf("_____________________________\n");
			printf("|        |         |        |\n");
			printf("|   %c    |   %c     |   %c    |\n",a[1][1],a[1][2],a[1][3]);
			printf("|________|_________|________|\n");
			printf("|        |         |   	    |\n");
			printf("|   %c    |   %c     |   %c    |\n",a[2][1],a[2][2],a[2][3]);
			printf("|________|_________|________|\n");
			printf("|        |         |        |\n");
			printf("|    %c   |   %c     |   %c    |\n",a[3][1],a[3][2],a[3][3]);
			printf("|________|_________|________|\n");
}
int win()
{
	int i;
	for(i=1;i<4;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])
		{
			if(a[i][1]=='*')
			return 1;
			else if(a[i][1]=='@')
			return 2;
		}
	}
	for(i=1;i<4;i++)
	{
		if(a[1][i]==a[2][i]&&a[2][i]==a[3][i])
			{
			if(a[1][i]=='*')
			return 1;
			else if(a[1][i]=='@')
			return 2;
		}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])
	{
			if(a[1][1]=='*')
			return 1;
			else if(a[1][1]=='@')
			return 2;
	}
	if(a[3][1]==a[2][2]&&a[2][2]==a[1][3])
	{
			if(a[1][3]=='*')
			return 1;
			else if(a[1][3]=='@')
			return 2;
	}
	return 0;
}
void main()
{

	int i,j,p,c=0,k,l;
	for(i=1;i<=3;i++)
	for(j=1;j<=3;j++)
	a[i][j]=' ';
	print();
	p=1;
	while(c<6)
	{
			puts("enter position");
			printf(" person %d\n",p);
			scanf("%d %d",&i,&j);
			if(i>0&&i<4&&j>0&&j<4&&a[i][j]==' ')
			{
					if(p==1)
					{
						a[i][j]='*';
						p++;
					}
					else
					{
						a[i][j]='@';
						p--;
					}
					c++;
				print();
					k=win();
					if(k)
					{
						puts("game over");
						printf("player %d won\n",k);
						exit(1);
					}
			}
			else
			puts("invalid");
	}
	p=1;
	while(!win())
	{
		printf("player %d\n",p);
		puts("move from");
		scanf("%d %d",&i,&j);
		puts("to");
		scanf("%d %d",&k,&l);
		if(a[k][l]==' '&&((p==1&&a[i][j]=='*')||(p==2&&a[i][j]=='@')))
		{
			if((i==2&&j==2)&&((abs(k-i)==1||abs(k-i)==0)&&abs(l-j)==1||abs(l-j)==0))
			{
				   				a[k][l]=a[i][j];
								a[i][j]=' ';
	   							if(p==2)
								p=1;
								else
								p++;

			}
			else if((k==2&&l==2)&&((abs(k-i)==1||abs(k-i)==0)&&abs(l-j)==1||abs(l-j)==0))
			{
								a[k][l]=a[i][j];
								a[i][j]=' ';
	   							if(p==2)
								p=1;
								else
								p++;
			}
			else if((abs(k-i)==1&&abs(l-j)==0)||(abs(k-i)==0&&abs(l-j)==1))
			{

				   				a[k][l]=a[i][j];
	   							a[i][j]=' ';
	  						 	if(p==2)
								p=1;
								else
								p++;
			}
			else
			puts("invalid");
						print();
		}
	else
	{
				print();
	puts("invalid");
	}
	}
		printf("player %d won\n",win());
						exit(2);
}

