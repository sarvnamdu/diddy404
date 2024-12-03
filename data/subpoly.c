#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct link {
    int coeff;
    int pow;
    struct link *next;
};

struct link *poly1 = NULL, *poly2 = NULL, *poly = NULL;

void create(struct link *node) {
    char ch;
    do {
        printf("\nEnter the coefficient: ");
        scanf("%d", &node->coeff);
        printf("\nEnter the power: ");
        scanf("%d", &node->pow);
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;
        node->next = NULL;
        printf("\nContinue??? (Y/N): ");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

void display(struct link *node) {
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->next != NULL) 
            printf(" + ");
    }
}

void polysub(struct link *poly1, struct link *poly2, struct link *poly) {
    while (poly1->next && poly2->next) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = -poly2->coeff;  // Subtract by negating the second polynomial's coefficient
            poly2 = poly2->next;
        } else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff - poly2->coeff;  // Subtract the coefficients
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;
    }

    // If any terms remain in poly1
    while (poly1->next) {
        poly->pow = poly1->pow;
        poly->coeff = poly1->coeff;
        poly1 = poly1->next;
        poly->next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;
    }

    // If any terms remain in poly2
    while (poly2->next) {
        poly->pow = poly2->pow;
        poly->coeff = -poly2->coeff;  // Negate poly2's coefficients for subtraction
        poly2 = poly2->next;
        poly->next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;
    }
}

void main() {
    poly1 = (struct link *)malloc(sizeof(struct link));
    poly2 = (struct link *)malloc(sizeof(struct link));
    poly = (struct link *)malloc(sizeof(struct link));
    clrscr();
    printf("\nEnter the first polynomial::");
    create(poly1);
    printf("\nFirst polynomial is :: \n");
    display(poly1);
    
    printf("\nEnter the second polynomial::");
    create(poly2);
    printf("\nSecond polynomial is :: \n");
    display(poly2);
    
    polysub(poly1, poly2, poly);
    printf("\nSubtraction of the two polynomials::");
    display(poly);
    getch();
}
