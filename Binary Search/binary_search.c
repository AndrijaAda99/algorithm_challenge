#include <stdio.h>
#include <math.h>
        
/*! \brief Binary Search finds position of a item
 *
 *  Binary Search is an efficient algorithm for finding
 *  item in a sorted array of items
 *
 * \param target Item for finding position
 * \param array[] Sorted array to find position of target
 * \param size Size of array
 * \return position of a target
 */
int binary_search(int target, int array[], int size)
{
    int min = 0;        
    int max = size - 1; 

    int guess;
    while (min <= max) {
        guess = (min + max) / 2;
        if (array[guess] == target) {
            return guess;
        } else if (array[guess] < target) {
            min = guess + 1;
        } else {
            max = guess - 1;
        }
    }

    return -1;
}

int main(void)
{
    int target = 18;
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
                   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int n = sizeof(array) / sizeof(n);           

    printf("Za dati niz: \n");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);    
    printf("\nTrazeni broj %d je na poziciji %d\n", target, binary_search(target, array, n));
    return 0;
}

