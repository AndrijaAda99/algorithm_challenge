#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int fib_priv = 0;
    int fib_curr = 1;

    for (int i = 2; i < n + 1; i++) {
        int tmp = fib_priv;
        fib_priv = fib_curr;
        fib_curr += tmp;
    }

    return fib_curr;
}

int main(void)
{
    int n = 46;
    cout << fib(n) << endl;
    
    return 0;
}
