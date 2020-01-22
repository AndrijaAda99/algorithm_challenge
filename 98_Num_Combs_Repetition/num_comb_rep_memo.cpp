#include <iostream>
#include <vector>

using namespace std;

int num_combinations_with_repetition(int n, int k, vector<vector<int>>& memo)
{
    if (memo[n][k] != 0) {
        return memo[n][k];
    }

    if (n == 0) {
        return memo[n][k] = 0;
    }
    if (k == 0) {
        return memo[n][k] = 1;
    }

    return memo[n][k] = num_combinations_with_repetition(n, k - 1, memo) +
                        num_combinations_with_repetition(n - 1, k, memo);
}

int main(void)
{
    int n = 5;
    int k = 3;
    vector<vector<int>> memo(n + 1);
    for (int i = 0; i < n + 1; i++) {
        memo[i].resize(k + 1);
    }

    cout << num_combinations_with_repetition(n, k, memo) << endl; 
    return 0;
}
