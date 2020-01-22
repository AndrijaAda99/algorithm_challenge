#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<vector<int>> Memo;

const int INF = numeric_limits<int>::max();

int min_coins(vector<int>& coins, int n, int val, int left, Memo& memo)
{
    if (memo[n][val] != -1) {
        return memo[n][val];
    }
    if (val == 0) {
        return memo[n][val] = 0;
    }
    if (n == 0) {
        return memo[n][val] = INF;
    }

    if (left < val) {
        return memo[n][val] = INF;
    }

    int res = min_coins(coins, n - 1, val, left - coins[n - 1], memo);

    if (coins[n - 1] <= val) {
        int res_with = 1 + min_coins(coins, n - 1, 
                                     val - coins[n - 1], 
                                     left - coins[n - 1],
                                     memo);
        res = min(res, res_with);
    }

    return memo[n][val] = res;
}

int main(void)
{
    vector<int> c = {1, 1, 3, 5, 10};
    int val = 20;

    int sum = 0;
    for (int i = 0; i < c.size(); i++) {
        sum += c[i];
    }
    Memo memo(c.size() + 1);
    for (int i = 0; i < c.size() + 1; i++) {
        memo[i].resize(val + 1, -1);
    }

    int num_coins =  min_coins(c, c.size(), val, sum, memo);

    cout << (num_coins == INF ? -1 : num_coins) << endl;
    
    
    return 0;
}
