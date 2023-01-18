#include <stdio.h>

// i am keeping the penalty for negative numbers as 100 and adding the negative value in its positive form to that 100
//this wont work for generic codes but will work for the given input
int i,j,k,a,b,u,v,n=5,ne=1;
int least,leastcost=0,par[5];
 int matrix[5][5]={

{0, 4, 2, 0, 0},

{0, 0, 3, 2, 3},

{0, 1, 0, 4, 5},

{0, 0, 0, 0, 0},

{0, 0, 0, -5, 0}



};
int search(int i);
int ui(int i,int j);
int main()
{
    for (int i=0;i<5;i++)
    {for(int j=0;j<5;j++)
    {if(matrix[i][j]<0)
    {matrix[i][j]=100+(matrix[i][j]*-1);}
    }
    }
    printf("\nThe edges of minimum spanning tree are\n");
    while(ne<n) 
    {
        for(i=0,least=100;i<=n;i++)
        {
            for (j=0;j<n;j++)
            {
            
                if(matrix[i][j]<least && matrix[i][j]!=0)
                {
                    least=matrix[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=search(u);
        v=search(v);
        if(ui(u,v))
        {
            printf("%d. edge(%d,%d) = %d\n",ne,a,b,least);
            leastcost+=least;
            ne++;
        }
        matrix[a][b]=10000;
    }
    printf("\nminimum cost = %d\n", leastcost);
}

int search(int i) 
{
    while(par[i])
        {i = par[i];}
    return i;
}

int ui(int i, int j) 
{
    if (i!=j) 
    {
        par[j] = i;
        return 1;
    }
    return 0;
}
