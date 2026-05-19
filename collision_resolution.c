#include <stdio.h> 
#define SIZE 10 
int hashTable[SIZE]; 
void init() { 
    for (int i = 0; i < SIZE; i++) 
        hashTable[i] = -1; 
} 
int hashFunction(int key) { 
    return key % SIZE; 
} 
void insert(int key) { 
    int index = hashFunction(key); 
    if (hashTable[index] == -1) { 
        hashTable[index] = key; 
    } else { 
        printf("Collision occurred at index %d for key %d\n", index, key); 
        int i = (index + 1) % SIZE; 
        while (i != index) { 
            if (hashTable[i] == -1) { 
                hashTable[i] = key; 
                return; 
              } 
 
            i = (i + 1) % SIZE; 
        } 
        printf("Hash table is full\n"); 
    } 
} 
void display() { 
    printf("\nHash Table:\n"); 
    for (int i = 0; i < SIZE; i++) { 
        if (hashTable[i] != -1) 
            printf("Index %d : %d\n", i, hashTable[i]); 
        else 
            printf("Index %d : EMPTY\n", i); 
    } 
} 
 
int main() { 
    int keys[] = {23, 43, 13, 27, 56}; 
    int n = sizeof(keys) / sizeof(keys[0]); 
 
    init(); 
 
    for (int i = 0; i < n; i++) { 
        insert(keys[i]); 
    } 
 
    display(); 
    return 0; 
} 