#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

bool find(Matrix& m, int val)
{
    int i = 0;
    int j = m[0].size() - 1;

    while (j >= 0 && i < m.size()) {
        if (m[i][j] > val) {
            j--;
        } else if (m[i][j] < val) {
            i++;
        } else {
            return true;
        }
    }

    return false;
}


int main(void)
{

    Matrix m = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {4, 6, 8, 10}
    };

    for (int i = -5; i < 15; i++) {
        if (find(m, i)) {
            cout << i << ": da" << endl;
        } else {
            cout << i << ": ne" << endl;
        }    
    }
    
    return 0;
}
