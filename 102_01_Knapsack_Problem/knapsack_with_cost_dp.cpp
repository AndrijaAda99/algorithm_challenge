#include <iostream>
#include <vector>

using namespace std;

int max_value_knapsack(vector<int>& W,
                       vector<int>& V, int w)
{
    int n = W.size();
    vector<int> dp(w + 1);

    for (int i = 1; i < n + 1; i++) {
        for (int j = w; j > 0; j--) {
            if (W[i - 1] <= j) {
                dp[j] = max(dp[j], V[i - 1] + dp[j - W[i - 1]]);
            }
        }
    }
    
    return dp[w];
}

int main(void)
{
    vector<int> W = {5, 10, 3, 12};
    vector<int> V = {10, 40, 50, 75};

    cout << max_value_knapsack(W, V, 20) << endl;

    return 0;
}
