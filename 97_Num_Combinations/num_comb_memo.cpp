#include <iostream>
#include <vector>

using namespace std;

int binom(int n, int k, vector<vector<int>>& memo)
{
    if (memo[n][k] != 0) {
        return memo[n][k];
    }

    if (k == 0 || k == n) {
        return memo[n][k] = 1;
    }

    return memo[n][k] = binom(n - 1, k - 1, memo) + 
                        binom(n - 1, k, memo);
}

int main(void)
{
    int k = 3;
    int n = 5;
    vector<vector<int>> memo(n + 1);
    for (int i = 0; i < n + 1; i++) {
        memo[i].resize(k + 1, 0);
    }

    cout << binom(n, k, memo) << endl;

    return 0;
}
