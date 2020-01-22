#include <iostream>
#include <vector>

using namespace std;

int num_partitions(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int j = 1; j < n + 1; j++) {
        for (int i = 1; i < n + 1; i++) {
            if (i >= j) {
                dp[i] += dp[i - j];
            }
        }
    }
    
    return dp[n];
}

int main(void)
{
    
    cout << num_partitions(6) << endl;

    
    return 0;
}
