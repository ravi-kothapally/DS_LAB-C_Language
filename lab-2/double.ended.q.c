#include<stdio.h>
 int q[6],f=-1,r=-1;
 void insertf()
 {
 	int i;
	if(r==6&&f==0||r+1==f)
	printf("q is over flowed");
	else{
		printf("element");
		scanf("%d",&i);
		if(f==-1)
			f=0;r=0;
		if(f==0)
		{
		
			f=6;
			q[f]=i;
		}
		else
		{
					
			f--;
			q[f]=i;
		}
			
				printf(" r=%d\n",r);
					printf("f=%d\n",f);
	}
 }
 void insertl()
 {
 		int i;
 		if(r==6&&f==0||r+1==f)
	printf("q is over flowed\n");
	else{
		printf("element");
		scanf("%d",&i);
		if(r==6)
		{
			r=0;
		}
		else
		{
			r=r+1;
		}
		q[r]=i;
		if(f==-1)
		f=0;
			printf(" r=%d\n",r);
					printf("f=%d\n",f);
	}
 }
 void deletef()
 {
 	int y;
 	if(f==-1)
 	printf("q is underflowed\n");
 	else{
	 
	 	y=q[f];
	 	if(f==r)
	 	f=r=-1;
	 	else if(f==6)
	 	f=0;
	 	else
	 	f=f+1;
	 	printf("%d is deleted\n",y);
	 		printf(" r=%d\n",r);
					printf("f=%d\n",f);
 	}
 }
  void deletel()
 {
 	int y;
 	if(f==-1)
 	printf("q is underflowed\n");
 	else{
	 
 	y=q[r];
 	if(f==r)
 	f=r=-1;
 	else if(r==0)
 	r=6;
 	else
 	r=r-1;
 	printf("%d is deleted\n",y);
 		printf(" r=%d\n",r);
					printf("f=%d\n",f);
 }
 }
 void display()
 {
 	int i;
 	if(f!=-1)
 	{
 		if(f<=r)
 		{ 
 			for(i=f;i<=r;i++)
 			printf("%d",q[i]);
 			
		 }
		 else
		 {
		 	for(i=f;i<=6;i++)
		 	printf("%d",q[i]);
		 	for(i=0;i<=r;i++)
		 	printf("%d",q[i]);
		 }
		  printf("\n");
	 }
	
	 else
	 printf("no elements yarr\n");
 	
 }
 void main()
 {
 	int op;
 	do{
	 
 	printf("select\n");
 	printf("              			 1.insert first      2.insert last\n");
 	printf("               			 3.delete first      4.delete last\n");
 	printf("              			 5.display           6.exit\n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1: insertf();
 				break;
 		case 2: insertl();
		 	   	break;
		case 3: deletef();
				 break;	
		case 4: deletel();
				break;
		case 5: display();
				break;		
		default : puts("invalid option\n"); 			 		
 		
	}
	}while(op!=6);
 }
