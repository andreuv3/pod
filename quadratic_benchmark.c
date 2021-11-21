#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_result(char *method, double time_in_seconds, int comparisons) {
    printf("\n%s", method);
    printf("\nTempo gasto: %lfms", time_in_seconds * 1000);
    printf("\nNúmero de comparações: %d", comparisons);
    printf("\n");
}

void bubble_sort(int *a, int n) {
    int i, j, comparisons = 0;
    clock_t start, end;

    start = clock();

    for (i = n - 1; i >= 1; i--) {
        int swapped = 0;
        for (j = 0; j <= i - 1; j++) {
            comparisons++;
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

     end = clock();
     double time = ((double) end - start) / CLOCKS_PER_SEC;
     print_result("Bubble sort", time, comparisons);
}

void insertion_sort(int *a, int n) {
    int i, j, p, comparisons = 0;
    clock_t start, end;

    start = clock();

    for (i = 1; i <= n - 1; i++) {
        p = a[i];
        for (j = i; j >= 1 && (p < a[j - 1]); j--) {
            a[j] = a[j - 1];
            comparisons++;
        }
        a[j] = p;
    }

    end = clock();
    double time = ((double) end - start) / CLOCKS_PER_SEC;
    print_result("Insertion sort", time, comparisons);
}

void selection_sort(int *a, int n) {
    int i, j, smaller, comparisons = 0;
    clock_t start, end;

    start = clock();

    for (i = 0; i < n - 2; i++) {
        smaller = i;
        for (j = i + 1; j <= n - 1; j++) {
            comparisons++;
            if (a[smaller] > a[j]) {
                smaller = j;
            }
        }
        int aux = a[i];
        a[i] = a[smaller];
        a[smaller] = aux;
    }

    end = clock();
    double time = ((double) end - start) / CLOCKS_PER_SEC;
    print_result("Selection sort", time, comparisons);
}

int main(void) {
    int array_size;
    do {
        printf("Informe o tamanho do array desejado: ");
        scanf("%d", &array_size);
    } while (array_size <= 0);

    int array_sort_type;
    do {
        printf("1. Crescente");
        printf("\n2. Decrescente");
        printf("\n3. Aleatório");
        printf("\nInforme o tipo de ordenação inicial:");
        scanf("%d", &array_sort_type);
    } while (array_sort_type < 1 || array_sort_type > 3);

    int i;
    int *bubble_sort_array = malloc(array_size * sizeof(int));
    int *insertion_sort_array = malloc(array_size * sizeof(int));
    int *selection_sort_array = malloc(array_size * sizeof(int));
    
    if (array_sort_type == 1) {
        for (i = 0; i < array_size; i++) {
            bubble_sort_array[i] = i + 1;
            insertion_sort_array[i] = i + 1;
            selection_sort_array[i] = i + 1;
        }
    } else if (array_sort_type == 2) {
        for (i = array_size - 1; i >= 0; i--) {
            bubble_sort_array[i] = array_size - i;
            insertion_sort_array[i] = array_size - i;
            selection_sort_array[i] = array_size - i;
        }
    } else {
        for (i = array_size - 1; i >= 0; i--) {
            bubble_sort_array[i] = rand();
            insertion_sort_array[i] = rand();
            selection_sort_array[i] = rand();
        }
    }

    bubble_sort(bubble_sort_array, array_size);
    insertion_sort(insertion_sort_array, array_size);
    selection_sort(selection_sort_array, array_size);
}
