#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n = 8;
    int a[] = {4, 1, 2, 7, 8, 5};

    int s1 = n % 2 == 0 ? (n / 2) * (n + 1) : ((n + 1) / 2) * n;
    int s2 = n % 2 == 0 ? (n / 2) * (n + 1) * (2 * n + 1) / 3 :
                          ((n + 1) / 2) * (2 * n + 1) * n / 3;

    int z1 = 0;
    int z2 = 0;
    for (int i = 0; i < n - 2; i++) {
        z1 += a[i];
        z2 += a[i] * a[i];
    }

    int c1 = s1 - z1;
    int c2 = s2 - z2;

    int d = (int) sqrt(2 * c2 - c1 * c1);
    int x = (c1 + d) / 2;
    int y = (c1 - d) / 2;
    
    cout << x << " " << y << endl;

    return 0;
}
