
#include<stdio.h>
// i am keeping the penalty for negative numbers as 100 and adding the negative value in its positive form to that 100
//this code will work for the given problem but will not work under generic condtions
int mincost(int edgevalue[],int vis[],int n)

{

int k;

int edhukku=100000;

for(int i=1;i<n;i++)

{

if(vis[i]==0)

{

if(edhukku>edgevalue[i])

{

edhukku=edgevalue[i];

k=i;

}

}

}

return k+1;

}

int main()

{

int n=5,s;

int edgevalue[n],vis[n],munnadi[n];

for(int i=0;i<n;i++)

{

vis[i]=0;

edgevalue[i]=1000;

munnadi[i]=0;

}

int matrix[5][5] = {

{0, 4, 2, 0, 0},

{0, 0, 3, 2, 3},

{0, 1, 0, 4, 5},

{0, 0, 0, 0, 0},

{0, 0, 0, -5, 0}



};

s=1;

edgevalue[s-1]=0; munnadi[s-1]=0; vis[s-1]=1;

summa:

for(int i=0;i<n;i++)

{
if(matrix[s-1][i]<0)
{matrix[s-1][i]==100-(matrix[s-1][i]);}

if(matrix[s-1][i]>0 && matrix[s-1][i]<edgevalue[i] && vis[i]==0)

{
edgevalue[i]=matrix[s-1][i];
munnadi[i]=s;
}

}

s=mincost(edgevalue,vis,n);

vis[s-1]=1;

for(int i=0;i<n;i++)

{

if(vis[i]==0) goto summa;

}

printf("vertex\t\tbefore vertex\t\t edgecost");

for(int i=0;i<5;i++)

{printf("\n%d\t\t %d\t\t\t %d",i+1,munnadi[i],edgevalue[i]);}

}
