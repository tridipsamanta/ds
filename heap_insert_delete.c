#include <stdio.h> 
#define MAX 50 
int heap[MAX]; 
int size = 0; 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void heapifyUp(int index) { 
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) { 
        swap(&heap[index], &heap[(index - 1) / 2]); 
        index = (index - 1) / 2; 
    } 
} 
void heapifyDown(int index) { 
    int largest = index; 
    int left = 2 * index + 1; 
    int right = 2 * index + 2; 
     if (left < size && heap[left] > heap[largest]) 
        largest = left; 
    if (right < size && heap[right] > heap[largest]) 
        largest = right; 
    if (largest != index) { 
        swap(&heap[index], &heap[largest]); 
        heapifyDown(largest); 
    } 
} 
void insert(int value) { 
    if (size == MAX) { 
        printf("Heap Overflow\n"); 
        return; 
    } 
    heap[size] = value; 
    heapifyUp(size); 
    size++; 
    printf("Inserted %d into heap\n", value); 
} 
void deleteMax() { 
    if (size == 0) { 
        printf("Heap Underflow\n"); 
        return; 
    } 
    printf("Deleted element: %d\n", heap[0]); 
    heap[0] = heap[size - 1]; 
    size--; 
    heapifyDown(0); 
} 
void display() { 
    if (size == 0) { 
        printf("Heap is empty\n"); 
        return; 
    } 
    printf("Heap elements: "); 
    for (int i = 0; i < size; i++) 
        printf("%d ", heap[i]); 
    printf("\n");
    } 
int main() { 
    int choice, value; 
 
    do { 
        printf("\n--- MAX HEAP MENU ---\n"); 
        printf("1. Insert\n"); 
        printf("2. Delete Max\n"); 
        printf("3. Display\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insert(value); 
                break; 
            case 2: 
                deleteMax(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                printf("Exiting program\n"); 
                break; 
            default: 
                printf("Invalid choice\n"); 
        } 
    } while (choice != 4); 
    return 0; 
}