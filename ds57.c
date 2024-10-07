#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct PolyNode {
    int coeff; // Coefficient
    int exp;   // Exponent
    struct PolyNode* next;
};

// Function to create a new polynomial node
struct PolyNode* createPolyNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct PolyNode** poly, int coeff, int exp) {
    struct PolyNode* newNode = createPolyNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct PolyNode* current = *poly;
        while (current->next != NULL && current->next->exp >= exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff; // Combine like terms
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to display the polynomial
void displayPolynomial(struct PolyNode* poly) {
    struct PolyNode* current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coeff, current->exp);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0;
        int exp = 0;
        
        if (poly1 == NULL) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp > poly2->exp) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coeff + poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        insertTerm(&result, coeff, exp);
    }
    return result;
}

// Main function
int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;

    int n, coeff, exp;

    // Input for first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input for second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    struct PolyNode* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial (Addition): ");
    displayPolynomial(result);

    // Free memory (not shown for simplicity)
    // Add memory cleanup code as needed

    return 0;
}