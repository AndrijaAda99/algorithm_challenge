#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

int max_path(Matrix& mat, int v, int k)
{
    if (v == 0 && k == 0) {
        return mat[v][k];
    }

    int max_sum_up = 0;
    int max_sum_left = 0;
    if (v > 0) {
        max_sum_up = max_path(mat, v - 1, k);
    }
    if (k > 0) {
        max_sum_left = max_path(mat, v, k - 1);
    }

    return mat[v][k] + max(max_sum_up, max_sum_left);
}

int main(void)
{
    Matrix m = {
        {4, 3, 1, 1, 1},
        {1, 9, 2, 1, 3},
        {1, 3, 5, 1, 3},
        {1, 3, 1, 2, 0},
        {4, 6, 7, 2, 1}
    };

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << max_path(m, i, j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
