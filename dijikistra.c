#include <stdio.h>
//i have penalised all negative values to 100 and added the negative values as their positive counterparts
int main()
{
	int matrix[5][5]={{0,4,2,0,0},
	{0,0,3,2,3},
	{0,1,0,4,5},
	{0,0,0,0,0},
	{0,0,0,-5,0}
	};
	
	int d[5];
	int v[5]={0};
	int minimum,node;
	for(int i=0;i<5;i++)
	{for(int j=0;j<5;j++)
		{if(matrix[i][j]<0)
			{matrix[i][j]=100+matrix[i][j]*-1;}
		 if(matrix[i][j]==0)
		 {matrix[i][j]=10000;}
		}}
	for(int i=0;i<5;i++)		
	{
		d[i]=matrix[0][i];
	}
	for(int c=0;c<5;c++)
	{
    	minimum=100;
		for(int i=0;i<5;i++)
		  	if(d[i]<minimum && !v[i]) 
		  	{
		    	minimum=d[i];
		    	node=i;
		  	}
		v[node] = 1;
		for(int i=0;i<5;i++)
		{
		  	if(!v[i])
		  	{
		    	if(minimum+matrix[node][i]<d[i] )
		    	{
		      		d[i]=minimum+matrix[node][i];
		    	}
		    }
  		}
  	}
  	for(int i=1;i<5;i++)
      	printf("d from 1 to %d is %d\n",i+1,d[i]);
      	
}
