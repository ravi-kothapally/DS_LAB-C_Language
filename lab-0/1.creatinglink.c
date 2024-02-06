#include<stdio.h>
#include<stdlib.h>
void main()
{	int n,i;
	struct node{
		int n;
		struct node *next;
		   }*root,*temp,*s;
	root=(struct node*)malloc(sizeof(struct node));
	temp=root;
	printf("%d",temp);
	printf("no ofnodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=(struct node*)malloc(sizeof(struct node));
		temp->next=s;
		printf("%d\n",temp);
		temp=temp->next;
		
	}
	temp->next=NULL;
	printf("%d\n",temp);
	printf("%d",temp->next);
	

} 
