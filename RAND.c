#include <stdio.h>
#include <stdlib.h>

void main () {
   int i, n,r,m,a[3],b[3],cr=0,p=0,j,d,f[3],g,x;
   time_t t;
   n = 5;
   puts("lets paly the game");
   srand((unsigned) time(&t));
   for( i = 0 ; i < n ; i++ ) 
   {
   		r=rand() % 1000;
      	if(r>99&&r<1000)
      	{
		  m=r;
		  break;
		}
   }
   x=m;
   while(m!=0)
   {
   	a[i]=m%10;
   	m/=10;
   	i++;
   }
   for(d=0;d<6;d++){
   for(g=0;g<3;g++)
   f[g]=0;
   printf("\nenter guess\n %d trails are left\n",6-d);
   scanf("%d",&n);
   if(n>99&&n<1000)
   {
   	i=0;
   	cr=0;
   	p=0;
   	 while(n!=0)
   	 {
   	 	b[i]=n%10;
   	 	n/=10;
   	 	i++;
	}
	for(i=0;i<3;i++)
	{
		if(a[i]==b[i])
		{
			cr++;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(b[i]==a[j]&&f[j]==0)
			{
				f[j]=1;
			p++;
			}
		}
	}
	if(cr==3&&p==3)
	{
	puts("congo..u won");
	exit(1);
	}
	printf(" correct positions=%d \n",cr);
	printf(" no of keys correct=%d",p);
	if(d==5)
	printf("\nu lose\n ans is %d",x);
   }
   else
  {d--;
   puts("invalid number");}
   
   
  
}}
