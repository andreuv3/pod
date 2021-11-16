#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(int *a, int n) {
    int i, j;
    for (i = n - 1; i >= 1; i--) {
        int swapped = 0;
        for (j = 0; j <= i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main(void) {
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = 10;

    print_array(a, n);
    bubble_sort(a, n);
    print_array(a, n);

    return 0;
}