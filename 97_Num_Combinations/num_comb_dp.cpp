#include <iostream>
#include <vector>

using namespace std;

// 1
// 1 1
// 1 2 1
// 1 3 3 
// 1 4 6 
// 1 5 10
// 1 6 15
int binom(int n, int k)
{
    vector<int> dp (n + 1);
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++) {
        if (i < k + 1)  {
            dp[i] = 1;
        }
        for (int j = min(k + 1, i - 1); j > 0; j--) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[k];
}

int main(void)
{
    int k = 3;
    int n = 5;

    cout << binom(n, k) << endl;

    return 0;
}
