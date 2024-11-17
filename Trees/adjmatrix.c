#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
void dfs(int graph[MAX][MAX],int visited[MAX],int vertex,int numvertices){
    visited[vertex] = true;
    printf("%d",vertex);
    for(int i=0;i<numvertices;i++){
         if(graph[vertex][i]==1 && !visited[i]){  
            
         dfs(graph,visited,i,numvertices);
    }
}
}
void bfs(int graph[MAX][MAX],int visited[MAX],int startvertex,int numvertices){
    int queue[MAX],front=0,rear=-1;
    visited[startvertex]= true;
    queue[++rear]= startvertex;
    while(front<=rear){
         int currentvertex = queue[front++];
         printf("%d",currentvertex);
         for(int i=0;i<numvertices;i++){
             if(graph[currentvertex][i]==1 && !visited[i]){
                 visited[i]= true;
                 queue[++rear]= i;
             }
         }
    }
}
int main(){
     int numvertices,i,j;
     int graph[MAX][MAX];
     int visited[MAX];
     printf("enter the no of vertices");
     scanf("%d",&numvertices);

    //  for(i=0;i<numvertices;i++){
    //      visited[i]= false;
    //      for(j=0;i<numvertices;j++){
    //          graph[i][j] =0;
    //                   } }

     printf("\n enter the adjancency matrix");
     for(i=0;i<numvertices;i++){ 
        for(j=0;j<numvertices;j++){
             scanf("%d",&graph[i][j]);

        }
     }
     printf("dfs traversal starting from vertex 0  is :\n");
     for(i=0;i<numvertices;i++){
         visited[i]= false;
         }   
     dfs(graph,visited,0,numvertices);
     printf("\n");
     printf(" bfs traversal staring from vertes 0 is :");
     for(i=0;i<numvertices;i++){
         visited[i]= false;
     }     
     bfs(graph,visited,0,numvertices);
     printf("\n");

     return 0;

}
