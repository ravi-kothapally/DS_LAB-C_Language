#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
}*temp[10],*newa,*tem,*t;
struct vertex{
	struct vertex* down;
	int n;
	struct node *next;
}*t1,*tem1,*root,*deal,*newa1;
struct node * createn()
{
	t=(struct node*)malloc(sizeof(struct node));
	t->next=0;
	return t;
}
struct vertex * createv()
{
	t1=(struct vertex*)malloc(sizeof(struct vertex));
	t1->down=0;
	t1->next=0;
	return t1;
}
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
	tem1=root;
	while(tem1!=0)
	{	
		if(tem1->n==s)
		{
			deal=tem1;
			break;
		}
		else
		tem1=tem1->down;
	}
	newa=createn();
	newa->n=e;
	if(deal->next==0)
	deal->next=newa;
	else
	{	
		tem=deal->next;
		while(tem->next!=0)
		tem=tem->next;
		tem->next=newa;
	}
		
	tem1=root;
	while(tem1!=0)
	{	
		if(tem1->n==e)
		{	
			deal=tem1;
			break;
		}
		else
		tem1=tem1->down;
	}
	newa=createn();
	newa->n=s;
	if(deal->next==0)
	deal->next=newa;
	else
	{	
		tem=deal->next;
		while(tem->next!=0)
		tem=tem->next;
		tem->next=newa;
	}
}
int getadjunvisiver(int p)
{
	int k=0;
	tem1=root;
	while(tem1!=0)
	{
		if(tem1->n==p)
		{
			k=1;
			deal=tem1;
			break;
		}
		else
		tem1=tem1->down;
	}
	if(k==1)
	{
			tem=deal->next;
		if(tem!=0)
		{
			while(tem!=0)
			{
				if(booli[tem->n]==0)
				{
					insert(tem->n);
					booli[tem->n]=1;
				}
			tem=tem->next;
			}
		}
		else
		return -1;
	}
	else
	return -1;
}
void bfs(int root)
{
	int uvv,x,i;
	booli[root]=1;
	insert(root);
	while(!isqempty())
	{
			x=delet();
			getadjunvisiver(x);	
			printf("%d ",x);
	}
	for(i=0;i<n;i++)
	booli[i]=0;
		
}
void main()
{
	int i,s,e,j,ch,v;

	int op;
	printf("enter no of vertices in graph<=20\n");
	scanf("%d",&n);
		printf("enter vertices\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&v);
		if(i==0)
		{
			root=createv();
			root->n=v;
			tem1=root;
		}
		else
		{
			newa1=createv();
			newa1->n=v;
			tem1->down=newa1;
			tem1=tem1->down;
		}
	}
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
	int cv;
	do{
	
	printf("\nenter root node\n");
	scanf("%d",&cv);
	printf("\ndepth first search is\n");
	bfs(cv);
	printf("\ncontinue 1/0\n");
	scanf("%d",&ch);
	}
	while(ch==1);
}
	
