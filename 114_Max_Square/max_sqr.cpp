#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<bool>> Matrix;

int max_square(Matrix& m, int i, int j)
{
    if (i == 0 || j == 0) {
        return m[i][j];
    }

    if (m[i][j] == 0) {
        return 0;
    }

    int d1 = max_square(m, i - 1, j);
    int d2 = max_square(m, i, j - 1);
    int d3 = max_square(m, i - 1, j - 1);

    return 1 + min({d1, d2, d3});
}

int max_square(Matrix& m)
{
    int max = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            int val = max_square(m, i, j);
            if (max < val) {
                max = val;
            }
        }
    }

    return max;
}

int main(void)
{
    Matrix m = {
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0},
        {1, 0, 1, 1, 0, 0, 1, 1}
    };

    cout << max_square(m) << endl;
    
    return 0;
}
