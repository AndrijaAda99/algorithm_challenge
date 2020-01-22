#include <iostream>
#include <vector>

using namespace std;

int catalan(int n, vector<int>& memo)
{
    if (memo[n] != -1) {
        return memo[n];
    }

    if (n == 0) {
        return memo[n] = 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += catalan(i, memo) * catalan(n - i - 1, memo);
    }

    return memo[n] = sum;
}

int main(void)
{
    int n = 4;
    vector<int> memo(n + 1, -1);
    cout << catalan(n, memo) << endl;

    for (int i = 0; i <= n; i++) {
        cout << memo[i] << " ";
    }
    cout << endl;

    return 0;
}
