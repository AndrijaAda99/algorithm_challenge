#include <iostream>

using namespace std;

// F(n) = F(n-1) + F(n-2), 
// F(1) = 1, F(0) = 0
// F(n) = O((golder_ratio)^n)
int fib_bad(int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib_bad(n - 1) + fib_bad(n - 2);
}

// O(n)
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

    for (int i = 1; i < n; i++) {
        int tmp = fib_curr;
        fib_curr += fib_priv;
        fib_priv = tmp;
    }

    return fib_curr;
}

int main(void)
{
    cout << fib_bad(10) << endl;
    cout << fib(10) << endl;
    
    return 0;
}
