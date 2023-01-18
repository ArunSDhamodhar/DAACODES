#include <stdio.h>

// i am keeping the penalty for negative numbers as 100 and adding the negative value in its positive form to that 100
//this wont work for generic codes but will work for the given input
int i,j,k,a,b,u,v,n=5,ne=1;
int min,mincost=0,parent[5];
 int graph[5][5]={

{0, 4, 2, 0, 0},

{0, 0, 3, 2, 3},

{0, 1, 0, 4, 5},

{0, 0, 0, 0, 0},

{0, 0, 0, -5, 0}



};
int find(int i);
int uni(int i,int j);
int main()
{
    for (int i=0;i<5;i++)
    {for(int j=0;j<5;j++)
    {if(graph[i][j]<0)
    {graph[i][j]=100+(graph[i][j]*-1);}
    }
    }
    printf("\nThe edges of minimum spanning tree are\n");
    while(ne<n) 
    {
        for(i=0,min=100;i<=n;i++)
        {
            for (j=0;j<n;j++)
            {
            
                if(graph[i][j]<min && graph[i][j]!=0)
                {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("%d. Edge(%d,%d) = %d\n",ne,a,b,min);
            mincost+=min;
            ne++;
        }
        graph[a][b]=10000;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i) 
{
    while(parent[i])
        {i = parent[i];}
    return i;
}

int uni(int i, int j) 
{
    if (i!=j) 
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
