#include<stdio.h>
#include<conio.h>

void main() {
    int arr[20] = {10, 20, 30, 40, 50}; // Predefined array elements
    int i, size = 5;  // Array size (based on the number of elements in the array)
    int sech = 30;  // Predefined value to search for
    int found = 0;  // Flag to check if element is found

    printf("\n\t-- Linear Search --\n\n");
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Searching for element: %d\n", sech);

    // Perform Linear Search
    for (i = 0; i < size; i++) {
        if (sech == arr[i]) {
            printf("Element exists in the list at position: %d\n", i + 1);
            found = 1;  // Element found
            break;
        }
    }

    // If element is not found
    if (!found) {
        printf("Element not found in the list.\n");
    }

    getch();
}
