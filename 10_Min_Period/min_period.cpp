#include <iostream>

using namespace std;

// 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4

bool jePeriod(int a[], int n, int p)
{
    for (int i = p; i < n; i++) {
        if (a[i] != a[i % p]) {
            return false;
        }
    }
    return true;
}

// Slozenost O(n log n)
int minPeriod(int a[], int n)
{
    for (int p = 1; p < n; p *= 2) {
        if (jePeriod(a, n, p)) {
            return p;
        }
    }
    return 0;
}

// Moze i bolje: O(n)
int minPerioda2(int a[], int n)
{
    while (n > 1) {
        for (int i = 0; i < n / 2; i++) {
            if (a[i]  != a[n / 2 + i]) {
                return n;
            }
        }
        n /= 2;
    }
    return 1;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

    cout << minPeriod(a, 16) << endl;

    return 0;
}
