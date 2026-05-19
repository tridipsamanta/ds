#include <stdio.h> 
#include <string.h> 
#define MAX 50 
 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
void findLCS(char X[], char Y[]) { 
    int m = strlen(X); 
    int n = strlen(Y); 
    int L[MAX][MAX]; 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
            else 
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
                 } 
    } 
    int index = L[m][n]; 
    char lcs[MAX]; 
    lcs[index] = '\0'; 
    int i = m, j = n; 
    while (i > 0 && j > 0) { 
        if (X[i - 1] == Y[j - 1]) { 
            lcs[index - 1] = X[i - 1]; 
            i--; 
            j--; 
            index--; 
        } else if (L[i - 1][j] > L[i][j - 1]) 
            i--; 
        else 
            j--; 
    } 
 
    printf("Longest Common Subsequence: %s\n", lcs); 
    printf("Length of LCS: %d\n", L[m][n]); 
} 
 
int main() { 
    char X[MAX], Y[MAX]; 
 
    printf("Enter first string: "); 
    scanf("%s", X); 
 
    printf("Enter second string: "); 
    scanf("%s", Y); 
 
    findLCS(X, Y); 
 
    return 0; 
}