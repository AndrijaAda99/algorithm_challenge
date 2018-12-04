#include <stdio.h>

char find_spare_rod(char rod1, char rod2);

/*! \brief This function solves Tower of Hanoi
 *
 *  This is recursive function that solves tower of hanoi problem.
 *  It's split job on smaler subproblems while moving rings
 *
 * \param n Number of rings
 * \param from_rod From which rod it starts
 * \param to_rod To witch rod it ends
 */
void tower_of_hanoi(int n, char from_rod, char to_rod)
{
    if (n == 0) {
        return;
    }

    char spare_rod = find_spare_rod(from_rod, to_rod);
    tower_of_hanoi(n - 1, from_rod, spare_rod);
    printf("%d: %c -> %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, spare_rod, to_rod);
}


int main(void)
{
    tower_of_hanoi(3, 'A', 'B');

    return 0;
}

char find_spare_rod(char rod1, char rod2)
{
    if ('A' != rod1 && 'A' != rod2) {
        return 'A';
    } else if ('B' != rod1 && 'B' != rod2) {
        return 'B';
    } else {
        return 'C';
    }
}

