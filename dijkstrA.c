#include <stdio.h>
int tbl[1000][2];
int q[100];
int m=7,n=5,c=3;
int i,rent[100][100]={{5,7,6,2,9,4,1},{2,2,3,6,9,8,4},{5,4,3,4,5,1,3},{4,9,3,3,2,1,7},{2,4,6,2,9,2,4}};
int empty()
{ int k;
	for(k=0;k<m*n;k++)
	if(q[k]!=999)
	return 1;
	return 0;
}
int deletemin()
{
	int min=999,index,i;
	for(i=0;i<m*n;i++)
	{
		if(min>q[i])
	    {
				min=q[i];
				index=i;
		}
	}

	return index;
}
void dijkstra()
{
	int i,day=1;
	for(i=0;i<m*n;i++)
	{
		q[i]=999;
		tbl[i][0]=-1;
	}
	int v,w;
	for(i=0;i<n;i++)
	{
		q[i]=tbl[i][0]=rent[i][0];
		tbl[i][1]=-1;
	}
	while(empty())
	{
		v=deletemin();
		day=v/n;
		day++;
		int in;
		for(i=0;i<n;i++)
		{
			in=day*5+i;
			if(tbl[in][0]==-1)
			{
				if(v%n!=i)
				{
					q[in]=  tbl[in][0]=rent[i][day]+q[v]+3;
		     	    	tbl[in][1]=v;
				}
				else
				{
					q[in]=  tbl[in][0]=rent[i][day]+q[v];
			 		tbl[in][1]=v;
				}
			}
			else
			{
				if(v%5!=i)
		    {
		    	if(tbl[in][0]>rent[i][day]+q[v]+3)
			 {
				q[day*5+i]=  tbl[in][0]=rent[i][day]+q[v]+3;
				tbl[in][1]=v;
		     }
		    }
		    else
		    {
		    	if(tbl[in][0]>rent[i][day]+q[v])
			 {
			 	q[in]= tbl[in][0]=rent[i][day]+q[v];
			    tbl[in][1]=v;
			 }
			}
			}
	 	}
	 		q[v]=999;
	}

}
void main()
{
	dijkstra();
	int order[m],j,k=m*n-n;
	int min_cost=tbl[k][0];
	for(i=k;i<m*n;i++)
	{
		if(min_cost>tbl[i][0])
		{
				min_cost=tbl[i][0];
				k=i;
		}
	}
	printf("minimal cost of the hotels=%d\n",min_cost+3);
	for(j=0;j<m;j++)
	{
		order[m-1-j]=k;
		k=tbl[k][1];
	}
   for(j=0;j<m;j++)
   printf("hotel %d-->",order[j]%5);
   printf("end");
	
}
