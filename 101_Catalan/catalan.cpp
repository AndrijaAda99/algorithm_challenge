#include <iostream>
#include <vector>

using namespace std;

int catalan(int n)
{
    if (n == 0) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += catalan(i) * catalan(n - i - 1);
    }

    return sum;
}

int main(void)
{
    cout << catalan(4) << endl;

    return 0;
}
