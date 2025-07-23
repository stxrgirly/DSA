binSrch(numbers[n], n, x) {
    low = 1, high = n
    while (low <= high) {
        mid = (low + high) / 2
        if (numbers[mid] > x) {
           high = mid - 1  // Search in the left half
        } else
            if (numbers[mid] == x) {
              low = mid + 1  // Search in the right half
            else {
                return mid  // Element found
            }
        }
}

#include <stdio.h>
int main() {
    int numbers[25], n, element, i, flag = 0, low, high, mid;
    printf("Enter the number of elements in the array");
    scanf("%d", &n);
    printf("Key in the elements in the array in ascending order\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        printf("Key in the elements to search for in the array\n",);
        scanf("%d", &element);

    low = 0, high = n - 1
    while (low <= high) {
        mid = (low + high) / 2
            if (numbers[mid] == element) {
                flag = 1
                break;
            } else
            if (numbers[mid] > element) {
                high = mid - 1  // Search in the left half
            } else
                low = mid + 1  // Search in the right half
        }
    }
}
