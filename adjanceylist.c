#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
typedef struct node{
     int vertex;
     struct node *next;
     
}node;
node *adjList[MAX];
int  visited[MAX];
node *createnode(int vertex){
    node *newnode = (node*)malloc((sizeof(node)));
    newnode->vertex = vertex;
    newnode->next = NULL;
    return newnode;
}
void addedge(int u,int v){
    node *newnode = createnode(v);
    newnode->next = adjList[u];
    adjList[u]=newnode;
    newnode= createnode(u);
    newnode->next = adjList[v];
    adjList[v]= newnode;
}
void dfs(int vertex){
    printf("\n visited %d",vertex);
    visited[vertex]=1;
    node *temp = adjList[vertex];
      while(temp!=NULL){
        int connectedvertex = temp->vertex;
        if(!visited[connectedvertex]){
            dfs(connectedvertex);
        }
        temp = temp->next;
      }
}
void bfs(int start)
{
    int queue[MAX];
    int front =0,rear =0,vertex;
    printf("Visited %d \n ",start);
    visited[start]=1;
    queue[rear++] =start;
    while(front<rear){
        vertex = queue[front++];
        node *temp = adjList[vertex];
        while(temp!=NULL){
            int connectedvertex= temp->vertex;
            if(!visited[connectedvertex]){
                printf("\n Visited %d\n ",connectedvertex);
                visited[connectedvertex]=1;
                queue[rear++]=connectedvertex;

            }
            temp= temp->next;
        }
    }
}
int main(){
    int n,edges,u,v,start;
    for(int i=0;i<MAX;i++){
         adjList[i]=NULL;
         visited[i]=0;
    }
    printf("enter the no of vertices ");
    scanf("%d",&n);
    printf("\n ener the no of edges ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        printf("enter the edges(u,v): ");
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    printf("ente the stating vertex for dfs :");
    scanf("%d",&start);
    printf("\n dfs traversal starting form vertex %d",start);
    dfs(start);
    for(int i=0;i<MAX;i++){
       visited[i]=0;
    }
    printf("entet he starting vertex bfs : ");
    scanf("%d",&start);
    printf("bfs traversal starting from vertes %d",start);
    bfs(start);
    return 0;
}
