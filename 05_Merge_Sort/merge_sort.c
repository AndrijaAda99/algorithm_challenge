#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n);

/*! \brief Brief Function merges 2 arrays
 *
 *  This function is used to merge 2 sorted arrays
 *  into 1 array that will also be sorted
 *
 * \param arr[] - Array for sorting
 * \param left - starting index of subarray Left
 * \param middle - ending index of subarray Left and 
 *               starting index + 1 of subarray Right
 * \param right - ending index of subarray Right
 * \return Return parameter description
 */
void merge(int arr[], int left, int middle, int right)
{
    // Find size of left and right array
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[(middle + 1) + i];
    }

    // Merge left and right into old array[left, right]
    // so you get an sorted subarray
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*! \brief This function implements merge sort
 *
 *  Function takes in array, left and right index of array/subarray,
 *  it splits it in half recursively until there is nothing to split
 *
 * \param arr[] - array to sort
 * \param left - left index of that array
 * \param right - right index of that array
 * \return Return parameter description
 */
void merge_sort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = (right + left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main(void)
{
    int array[] = {23, 321, 21, 5, 64, 83, 25};
    int n = sizeof(array) / sizeof(int);

    merge_sort(array, 0, n - 1);
    print_array(array, n);
    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
