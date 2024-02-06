#include<stdio.h>
#include<stdlib.h>
int mystrcmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]==s2[i])
	{
		if(s1[i]!='\0'&&s2[i]!='\0')
		i++;
		else
		break;
	}
	if(s1[i]=='\0'&&s2[i]=='\0')
	return 0;
	else
	if(s1[i]>s2[i])
	return 1;
	else
	return -1;
}
struct node{
	struct node *pre;
	char Emp_Id[20];
	char Emp_Name[20];
	char Emp_Address[200];	
	int Employee_Age;
	float Employee_Salary;
	struct node* next;
}*root,*temp;
struct node* create()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->pre=NULL;
	new->next=NULL;
	return new;
}

struct node* insert(struct node* root,int n)
{	int p,i,j;
	temp=root;
	struct node *newer=create();
	printf("enter the position");
	scanf("%d",&p);
	if(p<=n+1&&p!=0)
	{	printf("enter data;\n");
		printf("Id            :");
		scanf("%s",newer->Emp_Id);
		printf("Name          :");
		scanf("%s",newer->Emp_Name);
		printf("Addres        :");
		scanf("%s",newer->Emp_Address);
		printf("age           :");
		scanf("%d",&newer->Employee_Age);
		printf("salary        :");
		scanf("%f",&newer->Employee_Salary);
		
		
		if(p==1)
		{
			newer->next=temp;
			temp->pre=newer;
			root=newer;
		
		}
		else if(p<=n&&p>1)
		{
			for(i=1;i<p-1;i++)
			{
				temp=temp->next;
			}
			newer->next=temp->next;
			temp->next=newer;
			newer->pre=temp;
			temp->next->pre=newer;
		
		}
		else if(p==n+1)
		{
			temp=root;
			while(1)
			{	if(temp->next==NULL)
				break;
				temp=temp->next;
			}
			temp->next=newer;
			newer->pre=temp;
			newer->next=NULL;
					
		}
		return root;
	}
	else
	{
		printf("invalid position\n");	
		return root;
	}
}
struct node* delete(struct node* root,int n)
{	temp=root;
	int p,i=1,c=0,j;
	char id[20];
	printf("enter id to be deleted ;  ");
	scanf("%s",id);
	while(1)
	{
		p=mystrcmp(id,temp->Emp_Id);
		if(p==0)	
		{
			c=1;
			break;		
		}
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}

	if(c==1)
	{
		if(i==1)
		{
			temp=root;
			root=temp->next;
			temp->next=NULL;//deleting head
			
			free(temp);
			root->pre=NULL;
		}
		if(i<n&&i>1)
		{	temp=root;
				for(j=1;j<i-1;j++)
			{
				temp=temp->next;
			}
				temp->next=temp->next->next;
				temp->next->pre=temp;
		}
		if(i==n)
		{
			temp=root;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=NULL;
			free(temp->next);
		}
	}
	else
	printf("id not found \n");
	return root;
}
struct node* display(struct node* root)
{	int i=1;
	temp=root;
	while(1)
	{
		
		printf("%s\t\t",temp->Emp_Id);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=root;
	printf("\n");
	while(1)
	{
		printf("%s\t\t",temp->Emp_Name);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=root;
	printf("\n");
	while(1)
	{
		printf("%s\t\t",temp->Emp_Address);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=root;
	printf("\n");
	while(1)
	{
	
		printf("%d\t\t",temp->Employee_Age);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}
	temp=root;
	printf("\n");
	while(1)
	{
		
		printf("%2f\t",temp->Employee_Salary);
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}
	printf("\n");
}
struct node* search(struct node* root)
{
	temp=root;
	int p,i=1,c=0,j;
	char id[20];
	printf("search an id ;  ");
	scanf("%s",id);
	while(1)
	{
		p=mystrcmp(id,temp->Emp_Id);
		if(p==0)
		{	
			printf("id     :%s\n",temp->Emp_Id);
			printf("name   :%s\n",temp->Emp_Name);
			printf("address:%s\n",temp->Emp_Address);
			printf("age    :%d\n",temp->Employee_Age);
			printf("salary :%f\n",temp->Employee_Salary);
			c=1;
			break;		
		}
		if(temp->next==NULL)
		break;
		temp=temp->next;
	
	}
	if(c==0)
	printf("id not found\n");
}
void main()
{
	int i,n,op;
	struct node *new,*root;
	root=create();
	temp=root;
	printf("enter the number of employees");
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		printf("employee %d\n",i+1);
		printf("	Id            :");
		scanf("%s",temp->Emp_Id);
		printf("	Name          :");
		scanf("%s",temp->Emp_Name);
		printf("	Addres        :");
		scanf("%s",temp->Emp_Address);
		printf("	age           :");
		scanf("%d",&temp->Employee_Age);
		printf("	salary        :");
		scanf("%f",&temp->Employee_Salary);
		new=create();
		temp->next=new;
		new->pre=temp;
		temp=temp->next;
	}
		printf("employee %d\n",i+1);
		printf("	Id            :");
		scanf("%s",temp->Emp_Id);
		printf("	Name          :");
		scanf("%s",temp->Emp_Name);
		printf("	Addres        :");
		scanf("%s",temp->Emp_Address);
		printf("	age           :");
		scanf("%d",&temp->Employee_Age);
		printf("	salary        :");
		scanf("%f",&temp->Employee_Salary);
		temp->next=NULL;
	do{
	printf("select option\n1.insert employee\n2.delete employee by id\n3.display\n4.search employee\n5.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:root=insert(root,n);
			break;
		case 2:root=delete(root,n);
			break;
		case 3:display(root);
			break;
		case 4: search(root);
			break;
	
		default: puts("invalid");
		
	}
	}while(op!=5);
}
