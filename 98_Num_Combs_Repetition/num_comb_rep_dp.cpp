#include <iostream>
#include <vector>

using namespace std;

int num_combinations_with_repetition(int n, int k)
{
    vector<int> dp(k + 1, 1);

    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < k + 1; j++) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[k];
}

int main(void)
{
    int n = 5;
    int k = 3;

    cout << num_combinations_with_repetition(n, k) << endl; 
    return 0;
}
