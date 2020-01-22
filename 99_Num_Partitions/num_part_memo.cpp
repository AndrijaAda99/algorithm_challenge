#include <iostream>
#include <vector>

using namespace std;

int num_partitions(int n, int s, vector<vector<int>>& memo)
{
    if (memo[n][s] != -1) {
        return memo[n][s];
    }
    
    if (n == 0) {
        return memo[n][s] = 1;
    }
    if (s == 0) {
        return memo[n][s] = 0;
    }

    int num_part = num_partitions(n, s - 1, memo);
    if (n >= s) {
        num_part += num_partitions(n - s, s, memo);
    }

    return memo[n][s] = num_part;
}

void num_partitions(int n)
{
    vector<vector<int>> memo(n + 1);
    for (int i = 0; i < n + 1; i++) {
        memo[i].resize(n + 1, -1);
    }
    

    num_partitions(n, n, memo);

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << num_partitions(i, j, memo) << " ";
        }
        cout << endl;
    }

}

int main(void)
{
    
    num_partitions(6);

    
    return 0;
}
