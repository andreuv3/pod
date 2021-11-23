#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int beginning, int middle, int end) {
    int *aux = malloc((end - beginning + 1) * sizeof(int));
    int i = beginning;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= end) {
        if (a[i] <= a[j]) {
            aux[k] = a[i];
            i++;
        } else {
            aux[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        aux[k] = a[i];
        k++;
        i++;
    }

    while (j <= end) {
        aux[k] = a[j];
        k++;
        j++;
    }

    for (k = beginning; k <= end; k++) {
        a[k] = aux[k - beginning];
    }
}

void merge_sort(int *a, int beginning, int end) {
    if (beginning < end) {
        int middle = (beginning + end) / 2;
        merge_sort(a, beginning, middle);
        merge_sort(a, middle + 1, end);
        merge(a, beginning, middle, end);
    }
}

int main(void) {
    int array_size = 10;
    int array[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 1, 0 };

    print_array(array, array_size);
    merge_sort(array, 0, array_size);
    print_array(array, array_size);

    return 0;
}
