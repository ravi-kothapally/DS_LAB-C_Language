#include<stdio.h>
#include<stdlib.h>
int stack[20];
int top=-1;
int booli[20]={0};
int adj[20][20]={0};
int vertex[20];
int rear = -1;
int front = 0;
int queueItemCount = 0;
int n;
void push(int item) { 
   stack[++top] = item;
   
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}

int isstackempty() {

   if (top == -1)
   return 1;
   else
   return 0;
}

void addedge(int s,int e)
{
	int i,j,c1,c2;
	for(i=0;i<n;i++)
	{
	if(s==vertex[i])
	c1=i;
	if(e==vertex[i])
	c2=i;
	}
	adj[c1][c2]=1;
	adj[c2][c1]=1;	
}
int getadjunvisiver(int a)
{

	int i,j;	
	
		for(i=0;i<n;i++)
		{
			if(adj[a][i]==1&&booli[i]==0)
			return i;
		}
		return -1;
	
}
void dfs(int root)
{
	int uvv,i,con;

	printf("%d ",root);
	for(i=0;i<n;i++)
	{
		if(root==vertex[i])
		{
		
		con=i;
		break;
		}
	}

		booli[con]=1;
	push(con);
	
	while(!isstackempty())
	{
	
		uvv=getadjunvisiver(peek());
		if(uvv==-1)
		pop();
		else
		{
			booli[uvv]=1;
			printf("%d ",vertex[uvv]);
			push(uvv);
		}
	}
	for(i=0;i<n;i++)
	booli[i]=0;
}
void main()
{
	int i,s,e,root,j,ch;

	int op;
	printf("enter no of vertices in graph<=20\n");
	scanf("%d",&n);
	printf("enter vertices\n");
	for(i=0;i<n;i++)
	scanf("%d",&vertex[i]);
	printf("add edges\n");
	printf("continue  1/0");
	scanf("%d",&op);
	while(op==1)
	{
		
		printf("\nenter edges\n");
		scanf("%d%d",&s,&e);
		addedge(s,e);
			printf("continue  1/0");
			scanf("%d",&op);
		
	}
	do{
	
	printf("\nenter root node\n");
	scanf("%d",&root);
	printf("\ndepth first search is\n");
	dfs(root);
	printf("\ncontinue 1/0\n");
	scanf("%d",&ch);}
	while(ch==1);

}
	
	
	

