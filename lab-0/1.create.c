#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
};
struct node* create()
{	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	return new;
	
}
void main()
{
	struct node *new;
	new=create();
}
	
