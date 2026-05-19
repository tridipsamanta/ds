#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10 
 
  //Structure for adjacency list node 
struct node { 
    int vertex; 
    struct node *next; 
}; 
struct node *adjList[MAX]; 
int visited[MAX]; 
 
    //Create a new node 

struct node* createNode(int v) { 
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
} 
void addEdge(int src, int dest) { 
    struct node *newNode = createNode(dest); 
     newNode->next = adjList[src]; 
    adjList[src] = newNode; 
 
    newNode = createNode(src); 
    newNode->next = adjList[dest]; 
    adjList[dest] = newNode; 
} 
 
   //DFS function 
   
void dfs(int v) { 
    struct node *temp; 
    visited[v] = 1; 
    printf("%d ", v); 
 
    temp = adjList[v]; 
    while (temp != NULL) { 
        if (!visited[temp->vertex]) { 
            dfs(temp->vertex); 
        } 
        temp = temp->next; 
    } 
} 
 
int main() { 
    int n, e, i, src, dest, start; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    for (i = 0; i < n; i++) { 
        adjList[i] = NULL; 
        visited[i] = 0; 
    } 
 
    printf("Enter number of edges: "); 
    scanf("%d", &e); 
 
    for (i = 0; i < e; i++) { 
        printf("Enter edge (source destination): "); 
        scanf("%d %d", &src, &dest); 
        addEdge(src, dest); 
         } 
 
    printf("Enter starting vertex: "); 
    scanf("%d", &start); 
 
    printf("DFS Traversal: "); 
    dfs(start); 
 
    return 0; 
}