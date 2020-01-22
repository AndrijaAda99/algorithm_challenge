#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<bool>> Matrix;

int max_square(Matrix& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(m, 0);
    }

    for (int i = 0; i < n; i++) {
        dp[i][0] = mat[i][0];
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = mat[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], 
                                    dp[i - 1][j - 1], 
                                    dp[i][j - 1]});
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < dp[i][j]) {
                max = dp[i][j];
            }
        }
    }

    return max;
}

int main(void)
{
    Matrix m = {
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0},
        {1, 0, 1, 1, 0, 0, 1, 1}
    };

    cout << max_square(m) << endl;
    
    return 0;
}
