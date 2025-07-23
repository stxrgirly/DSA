#include<stdio.h>
    int selection(int low, int high);
    int a[25];
    int main() {
        int num = 0, i;
        printf("Key in the number of elements\n");
        scanf("%d\n", &num);
        printf("Key in the elements of the array\n");
        for(i = 0; i < num; i++) {
            scanf("%d\n", &a[i]);
        }
        selection(0, num - 1);
        printf("Sorted elements:\n");
        for(i = 0; i < num; i++) {
            printf("%5d ", a[i]);
        }
        return 0;
    }

    void selection(int low, int high) {
        int i = 0, j = 0, minindex, temp = 0;
        for(i = low; i < high; i++) {
            minindex = i;
            for(j = i + 1; j <= high; j++) {
                if(a[j] < a[minindex]) {
                    minindex = j;
                }
            }
            if(min != i) {
                temp = a[i];
                a[i] = a[minindex];
                a[minindex] = temp;
            }
        }
    }
