#include <stdio.h> 
#include <stdlib.h> 
struct node { 
    int coeff; 
    int exp; 
    struct node *next; 
}; 
struct node* createNode(int coeff, int exp) { 
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->coeff = coeff; 
    newNode->exp = exp; 
    newNode->next = NULL; 
    return newNode; 
} 
void insertTerm(struct node **poly, int coeff, int exp) { 
    struct node* newNode = createNode(coeff, exp); 
    struct node* temp = *poly; 
 
    if (*poly == NULL) { 
        *poly = newNode; 
        return; 
    } 
 
    while (temp->next != NULL) 
        temp = temp->next; 
 
    temp->next = newNode; 
}
void display(struct node* poly) { 
    if (poly == NULL) { 
        printf("0"); 
        return; 
    } 
    while (poly != NULL) { 
        printf("%dx^%d", poly->coeff, poly->exp); 
        if (poly->next != NULL) 
            printf(" + "); 
        poly = poly->next; 
    } 
    printf("\n"); 
} 
struct node* addPoly(struct node* p1, struct node* p2) { 
    struct node* result = NULL; 
 
    while (p1 != NULL && p2 != NULL) { 
        if (p1->exp == p2->exp) { 
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp); 
            p1 = p1->next; 
            p2 = p2->next; 
        } else if (p1->exp > p2->exp) { 
            insertTerm(&result, p1->coeff, p1->exp); 
            p1 = p1->next; 
        } else { 
            insertTerm(&result, p2->coeff, p2->exp); 
            p2 = p2->next; 
        } 
    } 
 
    while (p1 != NULL) { 
        insertTerm(&result, p1->coeff, p1->exp); 
        p1 = p1->next; 
    } 
 
    while (p2 != NULL) { 
        insertTerm(&result, p2->coeff, p2->exp); 
        p2 = p2->next; 
    } 
 
    return result;
    } 
struct node* subPoly(struct node* p1, struct node* p2) { 
    struct node* result = NULL; 
 
    while (p1 != NULL && p2 != NULL) { 
        if (p1->exp == p2->exp) { 
            insertTerm(&result, p1->coeff - p2->coeff, p1->exp); 
            p1 = p1->next; 
            p2 = p2->next; 
        } else if (p1->exp > p2->exp) { 
            insertTerm(&result, p1->coeff, p1->exp); 
            p1 = p1->next; 
        } else { 
            insertTerm(&result, -p2->coeff, p2->exp); 
            p2 = p2->next; 
        } 
    } 
 
    while (p1 != NULL) { 
        insertTerm(&result, p1->coeff, p1->exp); 
        p1 = p1->next; 
    } 
 
    while (p2 != NULL) { 
        insertTerm(&result, -p2->coeff, p2->exp); 
        p2 = p2->next; 
    } 
 
    return result; 
} 
int main() { 
    struct node *poly1 = NULL, *poly2 = NULL; 
    struct node *sum = NULL, *diff = NULL; 
 
    // Polynomial 1: 5x^3 + 4x^2 + 2x^0 
    insertTerm(&poly1, 5, 3); 
    insertTerm(&poly1, 4, 2); 
    insertTerm(&poly1, 2, 0); 
 
    // Polynomial 2: 3x^3 + 1x^1 + 4x^0  
    insertTerm(&poly2, 3, 3);
     insertTerm(&poly2, 1, 1); 
    insertTerm(&poly2, 4, 0); 
 
    printf("Polynomial 1: "); 
    display(poly1); 
 
    printf("Polynomial 2: "); 
    display(poly2); 
 
    sum = addPoly(poly1, poly2); 
    printf("Addition Result: "); 
    display(sum); 
 
    diff = subPoly(poly1, poly2); 
    printf("Subtraction Result (P1 - P2): "); 
    display(diff); 
 
    return 0; 
}