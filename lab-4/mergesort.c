#include<stdio.h>
#include<stdlib.h>
int n;
void merge(int a[],int l,int m,int h)
{

	int n1=m-l+1;
	int n2=h-m,i,j,k;
	int L[n1],r[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	for(j=0;j<n2;j++)
	{
		r[j]=a[m+1+j];
	}
	i=0;j=0;k=l;
	while(i < n1 && j < n2)
    {
        if (L[i] <= r[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
       while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;

	}
}
void partition(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		printf("|p|");
		 m = l+(h-l)/2;
		partition(a,l,m);
		partition(a,m+1,h);
		merge(a,l,m,h);
	}
}

void main()
{
	int a[10],i,j,n;
	printf("size\n");
	scanf("%d",&n);
	printf("enter numbers");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	partition(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
