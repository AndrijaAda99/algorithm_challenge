#include <stdio.h>

void swap(int *a, int *b);
int find_min(int array[], int start, int n);
void print_array(int array[], int n);


/*! \brief Function for sorting arrays
 *
 *  Selection Sort is simple algorithm for sorting arrays of numbers
 *
 * \param array[] array for sorting 
 * \param n size of array
 */
void selection_sort(int array[], int n)
{
    int min_index;

    for (int i = 0; i < n; i++) {
        min_index = find_min(array, i, n);
        swap(&array[i], &array[min_index]);
        print_array(array, n);
    }
}

int main(void)
{

    int array[] = {12, 23, 43, 11, 34, 2, 45};
    int n = sizeof(array) / sizeof(int);

    printf("Sorting...\n");
    selection_sort(array, n);

    printf("Sorted array: \n");
    print_array(array, n);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_min(int array[], int start, int n)
{
    int min_index = start;
    for (int i = start + 1; i < n; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
