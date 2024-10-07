#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int totalTerms;
} Polynomial;

// Function to input a polynomial
Polynomial inputPolynomial() {
    Polynomial p;
    p.totalTerms = 0;

    printf("Enter number of terms: ");
    scanf("%d", &p.totalTerms);

    for (int i = 0; i < p.totalTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p.terms[i].coeff, &p.terms[i].exp);
    }
    return p;
}

// Function to add two polynomials
Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.totalTerms = 0;
    
    int i = 0, j = 0;

    while (i < p1.totalTerms && j < p2.totalTerms) {
        if (p1.terms[i].exp > p2.terms[j].exp) {
            result.terms[result.totalTerms++] = p1.terms[i++];
        } else if (p1.terms[i].exp < p2.terms[j].exp) {
            result.terms[result.totalTerms++] = p2.terms[j++];
        } else {
            result.terms[result.totalTerms].exp = p1.terms[i].exp;
            result.terms[result.totalTerms++].coeff = p1.terms[i].coeff + p2.terms[j].coeff;
            i++;
            j++;
        }
    }

    // Add remaining terms
    while (i < p1.totalTerms) {
        result.terms[result.totalTerms++] = p1.terms[i++];
    }
    while (j < p2.totalTerms) {
        result.terms[result.totalTerms++] = p2.terms[j++];
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Polynomial p) {
    for (int i = 0; i < p.totalTerms; i++) {
        printf("%d x^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i < p.totalTerms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    Polynomial p1, p2, result;

    printf("Input first polynomial:\n");
    p1 = inputPolynomial();

    printf("Input second polynomial:\n");
    p2 = inputPolynomial();

    result = addPolynomials(p1, p2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}