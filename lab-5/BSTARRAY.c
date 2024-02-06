#include<stdlib.h>
#include<stdio.h>
int a[100],i,c=-1,jas;

/*void create()
{int k;
	printf("element to be inserted\n");
	scanf("%d",&k);
	c++;
	if(c==7)
	{
		printf("no space\n");
		exit(1);
	}
	if(c==0)
	{
		a[i]=k;
	}
	else
	{
		i=0;
		while(a[i]!=-1)
		{
				if(k<=a[i])
				i=2*i+1;
				else
				i=2*i+2;
		}
		a[i]=k;
	}	
	for(i=0;i<7;i++)
	printf("%d ",a[i]);	
}*/
int insert(int i,int v)
{
	if(i<100)
	{

		if(a[i]==-1)
		{
		a[i]=v;
		return 1;
		}
		else
		{
			if(v<a[i])
			insert(2*i+1,v);
			else
			insert(2*i+2,v);

		}
	}
	else
	puts("max");
}
int findmax(int i)
{
	if(i<100)
	{
		while(a[i*2+2]!=-1)
		i=i*2+2;
	}
	return i;
}
int delet(int i,int v)
{
	if(i<100)
	{
		if(v<a[i])
		delet(2*i+1,v);
		else if(v>a[i])
		delet(2*i+2,v);
		else
		{
			if(a[i*2+1]!=-1&&a[i*2+2]!=-1)
			{
				jas=findmax(2*i+1);
				a[i]=a[jas];
				delet(jas,a[i]);
			}
			else
			{
				if(a[2*i+1]==-1)
				{
				move(i);
				}
				if(a[2*i+2]==-1)
				{
				move(i);
				}
			}
		}
	}
	else
	puts("not found");
}
void preorder(int i)
{
	if(i<7&&a[i]!=-1)
	{
		
		printf("%d ",a[i]);
		preorder(2*i+1);
		preorder(2*i+2);
	}
}
void inorder(int i)
{
	if(i<7&&a[i]!=-1)
	{
		
	
		inorder(2*i+1);
			printf("%d ",a[i]);
		inorder(2*i+2);
	}
}
void postorder(int i)
{
	if(i<7&&a[i]!=-1)
	{
		
	
		postorder(2*i+1);
		
		postorder(2*i+2);
			printf("%d ",a[i]);
	}
}
int search(int k)
{
	i=0;
	while(i<7&&a[i]!=-1)
	{
		if(a[i]==k)
		{
			return 1;
			break;
		}
		if(a[i]<k)
		i=2*i+2;
		else
		i=2*i+1;
	}
	return 0;
	}	
void main()
{
	for(i=0;i<100;i++)
a[i]=-1;
	int c=0,i,op,k,v;
	
	do{
	
												printf("				select\n");
												printf("				_________________________________________________________\n");
												printf("				| 1.create             |      2.preorder traversal       |\n");
												printf("				| 3.in-order traversal |      4.post order traversal     |\n ");
												printf("				| 5.search             |      6.delete an element        |\n");
												printf("				| 7.exit               |                                 |\n");
												printf("				|______________________|_________________________________|\n");
												scanf("%d",&op);
	switch(op)
	{
		case 1:printf("enter number");
				scanf("%d",&v);
				insert(0,v);
					for(i=0;i<100;i++)
					{
	if(a[i]!=-1)
	printf("%d ",a[i]);}
				break;
		case 2: preorder(0);
				break;
		case 3: inorder(0);
				break;
		case 4: postorder(0);
				break;
		case 5: printf("element to be searched=");
				scanf("%d",&i); 
				k=search(i);
				printf("k=%d",k);
				if(k)
				{
					printf("found\n");
				}
				else
				printf("not found\n");	
				break;
		case 6: printf("no to be delted");
				scanf("%d",&v);
				delet(0,v);
					for(i=0;i<100;i++)
					{
	if(a[i]!=-1)
	printf("%d ",a[i]);}
	}
	}
	while(op!=7);
}
