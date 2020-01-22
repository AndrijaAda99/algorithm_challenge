#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

int max_path(Matrix& mat)
{
    int v = mat.size();
    int k = mat[0].size();

    vector<int> dp(k, 0);
    dp[0] = mat[0][0];
    for (int j = 1; j < v; j++) {
        dp[j] = mat[0][j] + dp[j - 1];
    }

    for (int i = 1; i < v; i++) {
        dp[0] += mat[i][0];
        for (int j = 1; j < k; j++) {
            dp[j] = mat[i][j] + max(dp[j], dp[j - 1]);
        }
    }

    return dp[k-1]; 
}

int main(void)
{
    Matrix m = {
        {4, 3, 1, 1, 1},
        {1, 9, 2, 1, 3},
        {1, 3, 5, 1, 3},
        {1, 3, 1, 2, 0},
        {4, 6, 7, 2, 1}
    };

    cout << max_path(m) << endl;

    
    return 0;
}
