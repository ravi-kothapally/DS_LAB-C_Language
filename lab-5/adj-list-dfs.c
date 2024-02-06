#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}*temp[10]={0},*t1,*t,*a[10]={0},*t2,*t3;
struct node * create()
{
	t=(struct node*)malloc(sizeof(struct node));
	return t;
}
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

	t1=create();
	t1->n=c2;

	t1->next=0;
	if(a[c1]->next==0)
	{
		
		a[c1]->next=t1;
		temp[c1]=t1;
	
		
	}
	else
	{
		
			
		temp[c1]->next=t1;
		temp[c1]=temp[c1]->next;
		
	}
	t2=create();
	t2->n=c1;
	t2->next=0;
	if(a[c2]->next==0)
	{
		
		temp[c2]=t2;
		a[c2]->next=temp[c2];
				
		
	}
	else
	{
			
		temp[c2]->next=t2;
		temp[c2]=temp[c2]->next;
				
				
	}
}
int getadjunvisiver(int p)
{

	int i,j=0,k;	
	temp[p]=a[p]->next;

	while(temp[p]!=0)
	{	
	
			if(booli[temp[p]->n]==0){
				
			return temp[p]->n;
			
			}
					temp[p]=temp[p]->next;
	

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
		for(i=0;i<n;i++)
	{
		a[i]=create();
		a[i]->next=0;
	}
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
