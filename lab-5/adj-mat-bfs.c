#include<stdio.h>
#include<stdlib.h>
int booli[20]={0};
int adj[20][20]={0};
int vertex[20];
int n;
int q[100];
int rear = -1;
int front = 0;
int queueItemCount = 0;
void insert(int data) {
   q[++rear] = data;
   queueItemCount++;
}

int delet() {
   queueItemCount--;
   return q[front++]; 
}

int isqempty() {
   return queueItemCount == 0;
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

	int i,j=0,k,p=0;	
	
		for(i=0;i<n;i++)
		{
			if(adj[a][i]==1&&booli[i]==0)
			{
				insert(i);
					booli[i]=1;
			}
		}
}
void bfs(int root)
{
	int con,uvv,x,i;


	for(i=0;i<n;i++)
	{

		if(root==vertex[i])
		{
		con=i;
		break;
		}
	}
	
		booli[con]=1;
	insert(con);
  
	
	while(!isqempty())
	{
			x=delet();
		
			getadjunvisiver(x);
			for(i=0;i<n;i++)
			{
				if(x==i)
				{
				printf("%d ",vertex[i]);
				}
			}
		
	}
	
	for(i=0;i<n;i++)
	booli[i]=0;
		
}
void main()
{
	int i,s,e,root,j,ch;
	int op;
	printf("enter no of vertices in graph\n");
	scanf("%d",&n);
	printf("enter vertices\n");
	for(i=0;i<n;i++)
	scanf("%d",&vertex[i]);
	for(i=0;i<n;i++)
	printf("%d ",vertex[i]);
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
	for(i=0;i<n;i++){
	
	for(j=0;j<n;j++)
	
	printf("%d",adj[i][j]);
	printf("\n");}
	
	do{
	
	printf("\nenter root node\n");
	scanf("%d",&root);
	printf("\nbreadth first search is\n");
	bfs(root);
	printf("\ncontinue 1/0\n");
	scanf("%d",&ch);}
	while(ch==1);

}
