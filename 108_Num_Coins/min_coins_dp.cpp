#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<vector<int>> Memo;

const int INF = numeric_limits<int>::max();

int min_coins(vector<int>& coins, int M)
{
    int N = coins.size();
    vector<vector<int>> dp(N + 1);
    for (int n = 0; n < N + 1; n++) {
        dp[n].resize(M + 1, -1);
    }

    for (int n = 0; n < N + 1; n++) {
        dp[n][0] = 0;
    }
    for (int val = 1; val < M + 1; val++) {
        dp[0][val] = INF;
    }

    for (int n = 1; n < N + 1; n++) {
       for (int val = 1; val < M + 1; val++) {
           dp[n][val] = dp[n - 1][val];
           if (coins[n - 1] <= val && dp[n - 1][val - coins[n - 1]] != INF) {
               dp[n][val] = min(dp[n - 1][val], 
                                dp[n - 1][val - coins[n - 1]] + 1);
           }
       }
    }

    for (int n = 0; n < N + 1; n++) {
        for (int val = 0; val < M + 1; val++) {
            if (dp[n][val] == INF) {
                cout << ". ";
            } else {
                cout << dp[n][val] << " ";
            }
        }
        cout << endl;
    }

    return dp[N][M];
}

int main(void)
{
    vector<int> c = {3, 7, 2, 4, 6};
    int val = 15;

    int num_coins =  min_coins(c, val);
    if (num_coins == INF) {
        cout << "ne";
    } else {
        cout << num_coins << " ";
    }

    
    return 0;
}
