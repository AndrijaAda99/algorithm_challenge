#include <iostream>

using namespace std;

int main(void)
{
    int n = 8;
    int a[] = {1, 2, 4, 6, 3, 7, 8};

    int total_sum = n % 2 == 0 ? (n / 2) * (n + 1) : ((n + 1) / 2) * n;

    cout << total_sum << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
        total_sum -= a[i];
    }

    cout << total_sum << endl;

    return 0;
}
