#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j);
void print_array(int arr[], int n);

/*! \brief Implements partition
 *
 *  This function put everithing smaller then pivot on one side
 *  and everithing greather tne pivot on the other side
 *
 * \param arr[] - partition this array
 * \param left - left bound
 * \param right - right bound
 * \return index of a pivot
 */
int partition(int arr[], int left, int right)
{
    int pivot_value = arr[right];
    int pivot_index = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot_value) {
            swap(arr, pivot_index, j);
            pivot_index++;
        }
    }

    swap(arr, pivot_index, right);
    return pivot_index;
}

/*! \brief Implementation of Quick Sort
 *
 *  Function takes in array, left and right index of array/subarray,
 *  then choses pivot, witch devide array into left and right
 *  subarrays which contains lower and grater element then 
 *  pivot respectivly
 *
 * \param arr[] - array to sort
 * \param left left index of that array
 * \param right right index of that array
 */
void quick_sort(int arr[], int left, int right)
{
    if (left < right) {
        int index = partition(arr, left, right);
        quick_sort(arr, left, index - 1);
        quick_sort(arr, index + 1, right);
    }
}

int main(void)
{
    int array[] = {23, 321, 21, 5, 64, 83, 25};
    int n = sizeof(array) / sizeof(int);

    quick_sort(array, 0, n - 1);
    print_array(array, n);
    return 0;
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
