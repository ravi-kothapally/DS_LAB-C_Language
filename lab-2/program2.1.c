#include<stdio.h>
#include<stdlib.h>
struct node{
	
	char Emp_Id[20];
	char Emp_Name[20];
	char Emp_Address[200];	
	int Employee_Age;
	float Employee_Salary;
	struct node *next;
	}*temp,*new,*top;
int c=0;
struct node * create()
{
	new=(struct node*)malloc(sizeof(struct node));

	new->next=0;
	return new;
}
void push()
{	
	if(top==NULL)
	{
		top=create();
		top->next=0;
		printf("	Id            :");
		scanf("%s",top->Emp_Id);
		printf("	Name          :");
		scanf("%s",top->Emp_Name);
		printf("	Addres        :");
		scanf("%s",top->Emp_Address);
		printf("	age           :");
		scanf("%d",&top->Employee_Age);
		printf("	salary        :");
		scanf("%f",&top->Employee_Salary);
	}
	else
	{
		temp=create();
		temp->next=top;
		
		top=temp;
		printf("	Id            :");
		scanf("%s",top->Emp_Id);
		printf("	Name          :");
		scanf("%s",top->Emp_Name);
		printf("	Addres        :");
		scanf("%s",top->Emp_Address);
		printf("	age           :");
		scanf("%d",&top->Employee_Age);
		printf("	salary        :");
		scanf("%f",&top->Employee_Salary);
		
	}
	c++;
}
struct node* pop()
{
	if(c==0)
	printf("no elments\n");
	else
	{ 	c--;
		printf("deleted data\n");
		printf("id     :%s\n",top->Emp_Id);
		printf("name   :%s\n",top->Emp_Name);
		printf("address:%s\n",top->Emp_Address);
		printf("age    :%d\n",top->Employee_Age);
		printf("salary :%f\n",top->Employee_Salary);
	 	top=top->next;
	}
	
}
void peep(int p)
{	int i;
	temp=top;
	if(p>0&&p<=c)
	{	
		for(i=1;i<p;i++)
		temp=temp->next;
		printf("id     :%s\n",temp->Emp_Id);
		printf("name   :%s\n",temp->Emp_Name);
		printf("address:%s\n",temp->Emp_Address);
		printf("age    :%d\n",temp->Employee_Age);
		printf("salary :%f\n",temp->Employee_Salary);
		
	}
	else
	printf("invalid option\n");
}
void display()
{
	int i;
    temp = top;
 
    if (temp== NULL)
    {
        printf("Stack is empty");
        
    }
 printf("-----------------------------------------\n");
   while(1)
	{
		
		printf("|  %s\t\t",temp->Emp_Id);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=top;
	printf("\n");
	while(1)
	{
		printf("|  %s\t\t",temp->Emp_Name);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=top;
	printf("\n");
	while(1)
	{
		printf("|  %s\t\t",temp->Emp_Address);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}temp=top;
	printf("\n");
	while(1)
	{
	
		printf("|  %d\t\t",temp->Employee_Age);
		
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}
	temp=top;
	printf("\n");
	while(1)
	{
		
		printf("|  %.2f\t\t",temp->Employee_Salary);
		if(temp->next==NULL)
		break;
		temp=temp->next;
		i++;
	}
	printf("\n-----------------------------------------\n");
}
void change(int p)
{
	int i;
	temp=top;
	if(p>0&&p<=c)
	{
		for(i=1;i<p;i++)
		temp=temp->next;
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
	}
	else
	printf("invalid position\n");

}
int getsize()
{
	return c;
}
void gettop()
{
	if(c>0)
	{	printf("id     :%s\n",top->Emp_Id);
		printf("name   :%s\n",top->Emp_Name);
		printf("address:%s\n",top->Emp_Address);
		printf("age    :%d\n",top->Employee_Age);
		printf("salary :%f\n",top->Employee_Salary);}
	else
	puts("no elements");	
}
int isem()
{
	if(c==0)
	return 0;
	else
	return 1;
}
int isfu()
{
	
	return 1;
}
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
void search()
{	if(c>0){
	temp=top;
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
	printf("id not found\n");}
	else
	puts("no elements");
}
void main()
{	struct node *var;
	int i,op,p,v;
	top=NULL;
	do{
	printf("		selct\n");
	printf("		1.push       2.pop             3.display\n");
	printf("		4.change     5.peep            6.getsize\n");
	printf("		7.get top    8.is stack empty  9.is stack full\n		10.search\n");
	printf("		11.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:	push();
			break;
		case 2:	pop();
			break;
		case 3: display();
			break;
		case 4: printf("position");
			scanf("%d",&p);
			change(p);
			break;
		case 5: printf("enter positon");
			scanf("%d",&p);
			peep(p);
			break;
		case 6: printf("%d is size\n",getsize());
			break;
		case 7: gettop();
			break;
		case 8: p=isem();
			if(p==0)
			printf("true\n");
			else
			printf("false\n");
			break;
		case 9:p=isfu();
			if(p==0)
			printf("true\n");
			else
			printf("false\n");
			break;
		case 10:search();
			break;
		default:puts("invalid");
		

	}
	}while(op!=11);
}		

