#include<stdio.h>
#include<stdio.h>
#include<limits.h>
#define V 5
int v,i,j,count,*p;
int min_distance (int dist[],int sp[]){
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(sp[v]==0 && dist[v]<=min){
            min = dist[v];
            min_index=v;
        }
    }
    return min_index;

}
void display(int dist[]){
  printf("vertex \t fistance from source ");
  for(i =0;i<V;i++){
    printf("\n %d\t\t%d",i,dist[i]);
  }
}
void dijkstra(int graph[V][V],int source){
    int dist[V];
    int sp[V];
    for(i=0;i<V;i++){
        dist[i]=INT_MAX;
        sp[i]=0;
    }
    dist[source]=0;

    for(count=0;count<V-1;count++){
         int u = min_distance(dist,sp);
         sp[u]=1;
         for(v=0;v<V;v++){
         if(!sp[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v]<dist[v]){
            dist[v]= dist[u]+graph[u][v];
         }
    }
    }

display(dist);
}
void main(){
    int graph[V][V] ={
               {0,3,5,0,0},
               {0,0,2,0,0},
               {0,1,0,4,6},
               {0,2,0,0,2},
               {2,0,0,7,0}};
     struct graph *.
           addedge(graph,i,j,graph[i][j]);
            }
        }
     }          
        dijkstra(graph,0); 
        dijkstra_list(graph,0);    
    }
struct adjlistnode{
    int dest;
    int weight;
    struct adjlistnode *next;
};
struct adjlist {
     struct adjlist *head;
};
struct graph{
    struct adjlist *array;
};
struct adjlistnode* newadjlistnode(int dest,int weight){
       struct adjlist* newnode  = (struct adjlistnode*)malloc (sizeof(struct adjlistnode));
       newnode->dest = dest;
       newnode->weight = weight;
       newnode->next = NULL;
       return newnode ;
}
struct graph* creategraph(int V){
    struct graph *graph = (struct graph*)malloc(sizeof(struct graph));
    graph->array = (struct adjlist*)malloc(V *sizeof(struct adjlist));
    for(int i=0;i<V;i++){
    graph->array[i].head  = NULL;}

    return graph;
}
void addedge(struct graph* graph,int src,int dest,int weight ){

struct adjlistnode* newnode = newadjlistnode(dest,weight);
newnode->next = graph->array[src].head;
 graph->array[src].head = newnode;
}
int min_distance (int dist[],int sp[]){
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(sp[v]==0 && dist[v]<=min){
            min = dist[v];
            min_index=v;
        }
    }
    return min_index;

}

void dijkstra_list(int graph[V][V],int source){
    int dist[V];
    int sp[V];
    for(i=0;i<V;i++){
        dist[i]=INT_MAX;
        sp[i]=0;
    }
    dist[source]=0;

    for(count=0;count<V-1;count++){
         int u = min_distance(dist,sp);
         sp[u]=1;
         struct adjlistnode* p = graph->array[u].head;
         while(*P !=NULL){
            int v =p->dest;

         }
         if(!sp[v] && dist[u]!=INT_MAX && dist[u] + p->weight <dist[v]){
            dist[v]= dist[u]+p->weight;
         }
    }p->p->next;
    

display(dist);
}



