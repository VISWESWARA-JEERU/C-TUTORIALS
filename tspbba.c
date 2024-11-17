#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 10
#define INF INT_MAX
int cost[MAX][MAX];
int n,i,j,nextcity;
int visited[MAX];
int bestcost = INF;
int bestpath[MAX];
int currentpath[MAX];
void tsp(int currentpos,int count,int costsofar){
    if(count==n && costsofar + cost[currentpos][0] < bestcost)
    {
        bestcost= costsofar + cost[currentpos][0];

    
    for( i=0;i<n;i++)
    {
        bestpath[i]= currentpath[i];

    }
    bestpath[n]=0;
    return;
    }
for(nextcity=0;nextcity<n;nextcity++){
    if(!visited[nextcity] && cost[currentpos][nextcity]!=INF){
        visited[nextcity]=1;
        currentpath[count]= nextcity;
        tsp(nextcity,count+1,costsofar+cost[currentpos][nextcity]);
        visited[nextcity] =0;
    }
}
}
int main(){
    
    int tempcost[MAX][MAX] ={
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    n=4;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cost[i][j] = tempcost[i][j];
        }
        visited[i] =0;
         }
         
     visited[0]=1;
     currentpath[0]=0;
     tsp(0,1,0);
     printf("minimum cost %d\n " ,bestcost);
     printf("path");
     for(i=0;i<=n;i++){
        printf(" %d-",bestpath[i]);
     }    
     printf("\n");
     return 0;
}
