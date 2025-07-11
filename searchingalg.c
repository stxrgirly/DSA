#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}

// Function for Binary Search (Iterative)
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index of the found element
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

// Function for Binary Search (Recursive)
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Element not found
    }
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Return the index of the found element
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to sort the array (for binary search)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function to test the search algorithms
int main() {
    srand(time(0)); // Seed for random number generation

    int sizes[] = {1000, 5000, 10000}; // Different input sizes
    int target = 50; // Target value to search for

    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        int* arr = (int*)malloc(size * sizeof(int));

        // Linear Search on Unsorted Array
        generateRandomArray(arr, size);
        clock_t start = clock();
        int linearResult = linearSearch(arr, size, target);
        clock_t end = clock();
        double linearTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Linear Search (Unsorted) - Size: %d, Time: %f seconds, Result: %d\n", size, linearTime, linearResult);

        // Binary Search on Sorted Array
        sortArray(arr, size);
        start = clock();
        int binaryIterativeResult = binarySearchIterative(arr, size, target);
        end = clock();
        double binaryIterativeTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Binary Search (Iterative) - Size: %d, Time: %f seconds, Result: %d\n", size, binaryIterativeTime, binaryIterativeResult);

        start = clock();
        int binaryRecursiveResult = binarySearchRecursive(arr, 0, size - 1, target);
        end = clock();
        double binaryRecursiveTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Binary Search (Recursive) - Size: %d, Time: %f seconds, Result: %d\n", size, binaryRecursiveTime, binaryRecursiveResult);

        free(arr); // Free allocated memory
        printf("\n");
    }

    return 0;
}