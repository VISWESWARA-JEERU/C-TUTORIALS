#include<stdio.h>
#include<limits.h>
#define INF 9999
#define MAX 100
int n;
int visited[MAX];
int bestpath[MAX];
int bestcost=INF;
int cost[MAX][MAX];
int currentpath[MAX];
void tsp(int currentpos,int count,int costsofar)
{
int i,nextcity;
if(count==n&&costsofar+cost[currentpos][0]<bestcost)
{
bestcost=costsofar+cost[currentpos][0];
for(i=0;i<n;i++)
{
bestpath[i]=currentpath[i];
}
bestpath[n]=0;
return;
}
for(nextcity=0;nextcity<n;nextcity++)
{
if(!visited[nextcity]&&cost[currentpos][nextcity]!=INF)
{
visited[nextcity]=1;
currentpath[count]=nextcity;
tsp(nextcity,count+1,costsofar+cost[currentpos][nextcity]);
visited[nextcity]=0;
}
}
}
int main()
{
int i,j;
int tempcost[MAX][MAX];
n=4;
printf("enter cost matrix(4x4):");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&tempcost[i][j]);
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cost[i][j]=tempcost[i][j];
}
visited[i]=0;
}
visited[0]=1;
currentpath[0]=0;
tsp(0,1,0);
printf("minimum cost:%d",bestcost);
printf("\npath:");
for(i=0;i<=n;i++)
{
printf("%d",bestpath[i]);
}
printf("\n");
return 0;
}