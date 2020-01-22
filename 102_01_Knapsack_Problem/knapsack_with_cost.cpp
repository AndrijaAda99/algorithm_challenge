#include <iostream>
#include <vector>

using namespace std;

int max_value_knapsack(vector<int>& W, int n,
                       vector<int>& V, int w)
{
    if (n == 0) {
        return 0;
    }

    int value_without = max_value_knapsack(W, n - 1, V, w);
    if (W[n - 1] > w) {
        return value_without;
    }
    int value_with = V[n - 1] + max_value_knapsack(W, n - 1, V, w - W[n - 1]);

    return max(value_with, value_without);
}

int main(void)
{
    vector<int> W = {5, 10, 3, 12};
    vector<int> V = {10, 40, 50, 75};

    cout << max_value_knapsack(W, W.size(), V, 20) << endl;

    for (int i = 0; i < W.size() + 1; i++) {
        for (int j = 0; j <= 20; j++) {
            cout << max_value_knapsack(W, i, V, j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
