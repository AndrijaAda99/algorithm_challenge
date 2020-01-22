#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int min_coins(vector<int>& coins, int n, int val, int left)
{
    if (val == 0) {
        return 0;
    }
    if (n == 0) {
        return INF;
    }

    if (left < val) {
        return INF;
    }

    int res = min_coins(coins, n - 1, val, left - coins[n - 1]);

    if (coins[n - 1] <= val) {
        int res_with = 1 + min_coins(coins, n - 1, 
                                     val - coins[n - 1], 
                                     left - coins[n - 1]);
        res = min(res, res_with);
    }

    return res;
}

int main(void)
{
    vector<int> c = {1, 1, 3, 5, 10};
    int val = 20;

    int sum = 0;
    for (int i = 0; i < c.size(); i++) {
        sum += c[i];
    }
    int num_coins =  min_coins(c, c.size(), val, sum);

    cout << (num_coins == INF ? -1 : num_coins) << endl;
    
    
    return 0;
}
