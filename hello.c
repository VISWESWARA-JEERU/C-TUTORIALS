#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef enum { false, true } bool;

struct Node {
    int data;
    struct Node *l;
};

typedef struct Node node;


node *createNode(int vertex) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = vertex;
    newNode->l = NULL;
    return newNode;
}

void dfs(node *ptr[], bool visited[], int vertex) {
    node *temp;
    visited[vertex] = true;
    printf("%d ", vertex);
    temp = ptr[vertex];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(ptr, visited, temp->data);
        }
        temp = temp->l;
    }
}

int main() {
    node *ptr[SIZE] = {NULL}; 
    int numVertex, no_of_vertices;
    int vertex;
    bool visited[SIZE] = {false}; 

    printf("Enter no. of Vertices: ");
    scanf("%d", &no_of_vertices);

    for (int i = 0; i < no_of_vertices; i++) {
        printf("Enter the number of vertices connected to vertex %d: ", i);
        scanf("%d", &numVertex);
        for (int j = 0; j < numVertex; j++) {
            printf("Enter vertex %d connected to %d: ", j + 1, i);
            scanf("%d", &vertex);
            node *newNode = createNode(vertex);
            if (ptr[i] == NULL) {
                ptr[i] = newNode;
            } else {
                node *temp = ptr[i];
                while (temp->l != NULL) {
                    temp = temp->l;
                }
                temp->l = newNode;
            }
        }
    }

    printf("DFS traversal starting from vertex 0: ");
    dfs(ptr, visited, 0);
    printf("\n");

    // Free allocated memory (not shown here for brevity, but recommended)

    return 0;
}
