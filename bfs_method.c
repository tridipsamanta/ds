#include <stdio.h> 
#define MAX 10 
int queue[MAX], front = -1, rear = -1; 
int visited[MAX]; 
 
void enqueue(int v)
{ 
    if (rear == MAX - 1) 
        return; 
    if (front == -1) 
        front = 0; 
    queue[++rear] = v; 
} 
int dequeue()
{ 
    int v = queue[front++]; 
    if (front > rear) 
        front = rear = -1; 
    return v; 
} 
void bfs(int n, int adj[MAX][MAX], int start)
{ 
    int i, v; 
    for (i = 0; i < n; i++) 
        visited[i] = 0; 
 
    enqueue(start); 
    visited[start] = 1;
      printf("BFS Traversal: "); 
 
    while (front != -1) 
    { 
        v = dequeue(); 
        printf("%d ", v); 
 
        for (i = 0; i < n; i++) 
        { 
            if (adj[v][i] == 1 && !visited[i])
            { 
                enqueue(i); 
                visited[i] = 1; 
            } 
        } 
    } 
} 
 
int main() { 
    int n, i, j, start; 
    int adj[MAX][MAX]; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]); 
 
    printf("Enter starting vertex: "); 
    scanf("%d", &start); 
    bfs(n, adj, start); 
    return 0; 
}