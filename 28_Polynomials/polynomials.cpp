#include <iostream>

using namespace std;

int power(int x, int n)
{
    if (n == 0) {
        return 1;
    }
    return x * power(x, n - 1);
}

// Recursive method: O(n^2)
int polynomial_recursive_bad(int a[], int x, int n)
{
    if (n == 1) {
        return a[0];
    }
    return a[n - 1] * power(x, n - 1) + polynomial_recursive_bad(a, x, n - 1);
}

// Incremental method: O(n^2)
int polynomial_incremental_bad(int a[], int x, int n)
{
    int poly = 0;
    for (int i = 0; i < n; i++) {
        int x_n = 1;
        for (int j = 0; j < i; j++) {
            x_n *= x;
        }
        poly += a[i] * x_n;

    }

    return poly;
}

// Horner's method: O(n)
int polynomial_horner(int a[], int x, int n)
{
    int poly = x;
    for (int i = n - 1; i > 0; i--) {
        poly = a[i] * poly + a[i - 1];
    }

    return poly;
}
int main(void)
{
    int a[] = {1, 2, 2, 1};
    int n = sizeof (a) / sizeof (int);

    cout << "Recursive: ";
    cout << polynomial_recursive_bad(a, 2, n) << endl;
    cout << "Incremental: ";
    cout << polynomial_incremental_bad(a, 2, n) << endl;
    cout << "Horner's: ";
    cout << polynomial_horner(a, 2, n) << endl;

    return 0;
}
