#include <iostream>

using namespace std;

int main(void)
{
    int a = 25, b = 100;
    int n = 10;

    int l = a % n == 0 ? a / n - 1 : a / n;
    int d = b / n;

    cout << d - l << endl;

    return 0;
}
