#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node{
	
	char Emp_Id[20];
	char Emp_Name[20];
	char Emp_Address[200];	
	int Employee_Age;
	float Employee_Salary;
	struct node * next;
	}*f=0,*r=0,*ew,*f1;

struct node* create()
{
	ew=(struct node*)malloc(sizeof(struct node));

	ew->next=0;
	return ew;
}
void insert()
{	
	if(f==0)
	{
			ew=create();
				f=r=ew;
				r->next=0;
			printf("	Id            :");
		scanf("%s",r->Emp_Id);
		printf("	Name          :");
		scanf("%s",r->Emp_Name);
		printf("	Addres        :");
		scanf("%s",r->Emp_Address);
		printf("	age           :");
		scanf("%d",&r->Employee_Age);
		printf("	salary        :");
		scanf("%f",&r->Employee_Salary);c++;
		
	}
	else
	{
		ew=create();
			r->next=ew;
				r=ew;
		printf("	Id            :");
		scanf("%s",r->Emp_Id);
		printf("	Name          :");
		scanf("%s",r->Emp_Name);
		printf("	Addres        :");
		scanf("%s",r->Emp_Address);
		printf("	age           :");
		scanf("%d",&r->Employee_Age);
		printf("	salary        :");
		scanf("%f",&r->Employee_Salary);
	
		r->next=f;c++;
	}
	
		
	
}
void elete()
{	
	if(c!=0)
	{
		printf("deleted data\n");
		printf("id     :%s\n",f->Emp_Id);
		printf("name   :%s\n",f->Emp_Name);
		printf("address:%s\n",f->Emp_Address);
		printf("age    :%d\n",f->Employee_Age);
		printf("salary :%f\n",f->Employee_Salary);
		if(f==r)
		f=r=0;
		else{
		
		f=f->next;
		r->next=f;}
		c--;
	}
	else
	puts("no elemments\n");
}
void display()
{
		f1=f;
	if(f==0||c==0)
	printf("no elements");
	else
	{
		while(1)
		{
				printf("id     :%s\n",f1->Emp_Id);
				printf("name   :%s\n",f1->Emp_Name);
				printf("address:%s\n",f1->Emp_Address);
				printf("age    :%d\n",f1->Employee_Age);
				printf("salary :%f\n",f1->Employee_Salary);
				if(f1==r)
				break;
				f1=f1->next;
			
		}
	}
}
int main()
{
	int op,i;
	do{
	
		printf("select");
		printf("1.insert        2.delete\n");
		
		printf("3.display            6.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : 	
					 insert();
					 break;
			case 2 : elete();
					 break;
			case 3 : display();
		}
	}while(op!=6);
}
