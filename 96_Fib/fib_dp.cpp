#include <iostream>
#include <vector>

using namespace std;

int fib_dp(int n)
{
    vector<int> dp (n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(void)
{
    int n = 46;
    cout << fib_dp(n) << endl;
    
    return 0;
}
