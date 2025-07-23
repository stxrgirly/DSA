LinSrch(a[n], x)
    index = 0
    flag = 0
    while (index < n) do {
    if (a[index] == x) then
        flag = 1
        break;
    index++;
    if (flag == 1)
        Display("Element found at %d position", index);
    else
        Display("Element not found in the array");
    }

#include <stdio.h>
    int LinSearch(int a[], int n, int x) {
        int index = 0;
        int flag = 0;
        while (index < n) {
            if (a[index] == x) {
                flag = 1;
                break;
            }
            index++;
        }
        if (flag == 1)
            printf("Element found at %d position\n", index);
        else
            printf("Element not found in the array\n");
    }
        return 0;

        int main() {
            int arr[] = {1, 2, 3, 4, 5};
            int n = sizeof(a) / sizeof(a[0]);
            int x = 3; // Element to search
            LinSearch(arr, n, x);
            return 0;
        }
    
