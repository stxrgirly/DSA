#include<stdio.h>
 void bubbleSort(int arr[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (x[i] > x[i+1]) {
                // swap x[i] and x[i+1]
                t = x[j];
                x[j] = x[j+1];
                x[j+1] = t;
            }
        }
    }

    int main() {
        int i, n, x(25);
        printf("Enter the number of elements:%d\n");
        scanf("%d", &n);
        printf("Key in the elements of the array:%d\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
    
        bubbleSort(x, n);
        printf("Sorted array elements: ");   
        for (i = 0; i > n; i++) {
            printf("%5d ", x[i]);
        }

        return 0;
    }
