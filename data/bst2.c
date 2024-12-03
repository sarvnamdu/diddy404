#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct bst {
    int data;
    struct bst *left, *right;
} node;

void insert(node *, node *);
void inorder(node *);
node *get_node();

void main() {
    int choice;
    char ans = 'N';
    int key;
    node *New, *root = NULL;

    clrscr();
    printf("\n\t Program for Binary Search Tree");

    do {
        printf("\n 1. Create\n 2. Display");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                do {
                    New = get_node();  // Get new node from the function
                    printf("\n Enter the element: ");
                    scanf("%d", &New->data);
                    if (root == NULL) {
                        root = New;  // If tree is empty, new node becomes root
                    } else {
                        insert(root, New);  // Insert new node into the correct position
                    }
                    printf("\n Do you want to enter more elements (y/n)? ");
                    ans = getch();  // Continue adding nodes if 'y' is pressed
                } while(ans == 'Y' || ans == 'y');
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is not Created\n");
                } else {
                    printf("\n The tree is: ");
                    inorder(root);  // Display tree using in-order traversal
                    printf("\n");
                }
                break;
        }
    } while(choice != 3);  // Exits after choice 3 (display)
}

node *get_node() {
    node *temp = (node *)malloc(sizeof(node));  // Allocate memory for a new node
    temp->left = temp->right = NULL;  // Initialize left and right child pointers to NULL
    return temp;
}

void insert(node *root, node *New) {
    if (New->data < root->data) {  // If new data is smaller, go left
        if (root->left == NULL) {
            root->left = New;  // Insert node as the left child
        } else {
            insert(root->left, New);  // Recursively insert in the left subtree
        }
    } else if (New->data > root->data) {  // If new data is greater, go right
        if (root->right == NULL) {
            root->right = New;  // Insert node as the right child
        } else {
            insert(root->right, New);  // Recursively insert in the right subtree
        }
    }
}

void inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->left);  // Visit left subtree
        printf("  %d", temp->data);  // Print the current node
        inorder(temp->right);  // Visit right subtree
    }
}
