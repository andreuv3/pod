#include <stdio.h>

void print_array(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertion_sort(int *a, int n) {
    int i, j, p;
    for (i = 1; i <= n - 1; i++) {
        p = a[i];
        for (j = i; j >= 1 && (p < a[j - 1]); j--) {
            a[j] = a[j - 1];
        }
        a[j] = p;
    }
}

int main(void) {
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = 10;

    print_array(a, n);
    insertion_sort(a, n);
    print_array(a, n);

    return 0;
}