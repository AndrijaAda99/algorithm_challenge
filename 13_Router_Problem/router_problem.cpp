#include <iostream>

using namespace std;

long int router(int a[], int n)
{
    long int pre = 0;
    long int posle = 0;
    for (int i = 0; i < n; i++) {
        posle += a[i];
    }

    long long int duzina = 0;
    for (int i = 0; i < n; i++) {
        duzina += i * a[i];
    }

    long long int min_duzina = duzina;

    for (int i = 1; i < n; i++) {
        pre += a[i - 1];
        posle -= a[i - 1];
        duzina += pre - posle;
        if (min_duzina > duzina) {
            min_duzina = duzina;
        }
    }

    return min_duzina;
}

int main(void)
{
    int a[] = {3, 5, 1, 6, 2, 4};

    cout << router(a, 6) << endl;

    return 0;
}
