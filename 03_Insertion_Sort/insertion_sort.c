#include <stdio.h>

void print_array(int array[], int n);
void insert_number(int array[], int start, int value);

/*! \brief Insrtion sort sorts an array of numbers
 *
 *  Insertion sort in an simple alghoritm for sorting numbers 
 *  It loops through array and for each element it insert it on right place
 *  Complexity of sorting with insertion sort is O(n^2)
 *
 * \param array[] Parameter description
 * \param n Parameter description
 */
void insertion_sort(int array[], int n)
{
    for (int i = 1; i < n; i++) {
        insert_number(array, i, array[i]);
        print_array(array, n);
    }
}

int main(void)
{
    int array[] = {123, 21, 23, 53, 95, 14, 34};
    int n = sizeof(array) / sizeof(int);
    printf("Sorting...\n");
    insertion_sort(array, n);
    printf("Sorted array: \n");
    print_array(array, n);
    
    return 0;
}

/* \brief Inserts number in right place
 *
 * This function chack previous position and if 
 *
 * \param array[] - array of numbers to operate on
 * \param start - starting index
 * \param value - value of element of position start
 */
void insert_number(int array[], int start, int value)
{
    int index = start;

    while (index > 0 && array[index - 1] > value) {
        array[index] = array[index - 1];
        index--;
    }
    array[index] = value;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
