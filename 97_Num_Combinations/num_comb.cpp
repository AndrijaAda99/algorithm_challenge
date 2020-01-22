#include <iostream>
#include <vector>

using namespace std;

int binom(int n, int k)
{
    if (k == 0) {
        return 1;
    }

    if (k == n) {
        return 1;
    }

    return binom(n - 1, k - 1) + binom(n - 1, k);
}

int main(void)
{
    int k = 3;
    int n = 5;
    cout << binom(n, k) << endl;

    return 0;
}
