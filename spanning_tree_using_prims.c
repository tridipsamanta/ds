#include <stdio.h> 
#include <limits.h> 
#define MAX 10 
int main() { 
    int n, i, j; 
    int cost[MAX][MAX]; 
    int visited[MAX] = {0}; 
    int min, u = 0, v = 0; 
    int totalCost = 0; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter cost adjacency matrix (0 if no edge):\n"); 
    for (i = 0; i < n; i++)
    { 
        for (j = 0; j < n; j++) { 
            scanf("%d", &cost[i][j]); 
            if (cost[i][j] == 0) 
                cost[i][j] = INT_MAX; 
        } 
    } 
 
    visited[0] = 1;   // Start from vertex 0 
    printf("\nEdges in the Minimum Spanning Tree:\n"); 
    for (int edge = 0; edge < n - 1; edge++) { 
        min = INT_MAX;
          for (i = 0; i < n; i++) 
          { 
            if (visited[i])
             { 
                for (j = 0; j < n; j++)
                 { 
                    if (!visited[j] && cost[i][j] < min)
                     { 
                        min = cost[i][j]; 
                        u = i; 
                        v = j; 
                    } 
                } 
            } 
          } 
 
        visited[v] = 1; 
        printf("%d - %d : %d\n", u, v, min); 
        totalCost += min; 
    } 
 
    printf("\nTotal cost of MST = %d\n", totalCost); 
 
    return 0; 
}