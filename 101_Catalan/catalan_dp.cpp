#include <iostream>
#include <vector>

using namespace std;

int catalan(int n)
{
    if (n == 0) {
        return 1;
    }

    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int j = 1; j < n + 1; j++) {
        int sum = 0;
        for (int i = 0; i < j + 1; i++) {
            sum += dp[i] * dp[j - i - 1];
        }
        dp[j] = sum;
    }

    return dp[n];
}

int main(void)
{
    cout << catalan(4) << endl;

    return 0;
}
