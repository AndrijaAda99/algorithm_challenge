#include <iostream>
#include <vector>

using namespace std;

bool knapsack(vector<int>& masa, int M)
{
    int N = masa.size();

    vector<vector<bool>> dp(N + 1);
    for (int i = 0; i < N + 1; i++) {
        dp[i].resize(M + 1);
    }

    dp[0][0] == true;
    for (int m = 1; m <= M; m++) {
        dp[0][m] = false;
    }

    for (int n = 1; n < N + 1; n++) {
        dp[n][0] = true;
        for (int m = 1; m < M + 1; m++) {
            dp[n][m] = dp[n - 1][m] ||
                       masa[n - 1] <= m && dp[n - 1][m - masa[n - 1]];
        }
    }

    return dp[N][M];
}

int main(void)
{
    int M = 100;
    vector<int> m = {10, 15, 20, 30, 40};
    if (knapsack(m, M)) {
        cout << "da" << endl;
    } else {
        cout << "ne" << endl;
    }
    
    return 0;
}
