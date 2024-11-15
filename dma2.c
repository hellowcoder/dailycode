#include <stdio.h>
#include <stdlib.h>

// Function to insert an element at a specified position
void insert(int **arr, int *size, int element, int position) {
    // Check if the position is valid
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }

    // Reallocate memory to hold one more element
    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    // Shift elements to the right from the position to the end
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert the new element
    (*arr)[position] = element;
    (*size)++;
}

// Function to delete an element at a specified position
void delete(int **arr, int *size, int position) {
    // Check if the position is valid
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the left from the position+1 to the end
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Reallocate memory to shrink the array by one element
    *arr = realloc(*arr, (*size - 1) * sizeof(int));
    if (*arr == NULL && *size - 1 > 0) { // Check if memory allocation fails but only if size > 0
        printf("Memory reallocation failed\n");
        exit(1);
    }

    (*size)--;
}

// Function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter initial size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize array elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the initial array
    printf("Initial array: ");
    printArray(arr, size);

    // Perform an insertion
    int element, position;
    printf("Enter element to insert and position (0-based index): ");
    scanf("%d %d", &element, &position);
    insert(&arr, &size, element, position);

    // Print the array after insertion
    printf("Array after insertion: ");
    printArray(arr, size);

    // Perform a deletion
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &position);
    delete(&arr, &size, position);

    // Print the array after deletion
    printf("Array after deletion: ");
    printArray(arr, size);

    // Free the allocated memory
    free(arr);

    return 0;
}
