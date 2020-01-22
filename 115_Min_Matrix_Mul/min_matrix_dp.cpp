#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<vector<int>> Memo;

int min_mat_mul(vector<int>& dim)
{
    int n = dim.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n, 0);
    }

    for (int k = 3; k < n + 1; k++) {
        for (int l = 0, d = l + k - 1; d < n; l++, d++) {
            dp[l][d] = numeric_limits<int>::max();
            for (int i = l + 1; i < d; i++) {
                int num_mul = dp[l][i] + dp[i][d] + 
                               dim[l] * dim[i] * dim[d];
                if (dp[l][d] > num_mul) {
                    dp[l][d] = num_mul;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == numeric_limits<int>::max()) {
                cout << ". ";
                continue;
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}

int main(void)
{
    vector<int> d = {4, 3, 5, 1, 2};

    cout << min_mat_mul(d) << endl;
    
    return 0;
}
