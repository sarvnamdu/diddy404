#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct SLL {
    int data;
    struct SLL *next;
} node;

node* create();    // Function to create the list
void display(node*);  // Function to display the list

void main() {
    int choice;
    node *head = NULL;
    
    do {
        clrscr();
        printf("Program to perform various operations on SLL\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = create();  // Create the list
                break;
            case 2:
                display(head);  // Display the list
                break;
            case 3:
                exit(0);  // Exit the program
                break;
            default:
                printf("Invalid choice, try again\n");
                getch();
                break;
        }
    } while (choice != 3);
}

// Function to create the linked list
node* create() {
    node *temp, *New, *head;
    int val;
    char ans = 'Y';

    head = NULL;

    do {
        printf("Enter the item: ");
        scanf("%d", &val);
        
        New = (node *)malloc(sizeof(node));  // Allocate memory for new node
        if (New == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        New->data = val;
        New->next = NULL;

        // If the list is empty, New node becomes head
        if (head == NULL) {
            head = New;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = New;  // Insert New node at the end
        }

        printf("Do you want to enter more elements (y/n)? ");
        ans = getche();
    } while (ans == 'Y' || ans == 'y');

    printf("\nThe List is created.\n");
    getch();
    return head;
}

// Function to display the linked list
void display(node *head) {
    node *temp = head;
    
    if (temp == NULL) {
        printf("The list is empty.\n");
        getch();
        return;
    }
    
    printf("The List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print each node's data
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");
    getch();
}
