#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selection_sort(int *a, int n) {
    int i, j, menor;
    for (i = 0; i < n - 2; i++) {
        menor = i;
        for (j = i + 1; j <= n - 1; j++) {
            if (a[menor] > a[j]) {
                menor = j;
            }
        }
        int aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
    }
}

int main(void) {
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = 10;

    print_array(a, n);
    selection_sort(a, n);
    print_array(a, n);

    return 0;
}