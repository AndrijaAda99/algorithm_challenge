#include <iostream>

using namespace std;

int num_inc_subarray(int a[], int n)
{
    int num_inc = 0;
    int inc = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            inc++;
            num_inc += inc;
        } else {
            inc = 0;
        }
    }

    return num_inc;
}

int main(void)
{
    int a[] = {2, 3, -4, 1, 2, -5, 6, 7};
    int n = sizeof (a) / sizeof (int);

    cout << num_inc_subarray(a, n) << endl;
    
    return 0;
}
