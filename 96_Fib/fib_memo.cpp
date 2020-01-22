#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int>& memo)
{
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n == 0) {
        return memo[0] = 0;
    }
    if (n == 1) {
        return memo[1] = 1;
    }
    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}

int main(void)
{

    int n = 45;
    vector<int> memo(n + 1, -1);
    cout << fib(n, memo) << endl;
    
    return 0;
}
