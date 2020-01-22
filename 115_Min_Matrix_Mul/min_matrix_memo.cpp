#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<vector<int>> Memo;

int min_mat_mul(vector<int>& dim, int l, int d, Memo& memo)
{
    if (memo[l][d] != -1) {
        return memo[l][d];
    }

    int n = d - l + 1;
    if (n <= 2) {
        return memo[l][d] = 0;
    }

    int min = numeric_limits<int>::max();
    for (int i = l + 1; i < d; i++) {
        int num_mul = min_mat_mul(dim, l, i, memo) + 
                      min_mat_mul(dim, i, d, memo) + 
                      dim[l] * dim[i] * dim[d];
        if (min > num_mul) {
            min = num_mul;
        }
    }

    return memo[l][d] = min;
}

int main(void)
{
    vector<int> d = {4, 3, 5, 1, 2};

    Memo memo(d.size() + 1);
    for (int i = 0; i < d.size() + 1; i++) {
        memo[i].resize(d.size() + 1, -1);
    }
    cout << min_mat_mul(d, 0, d.size() - 1, memo) << endl;
    
    return 0;
}
