#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int min_mat_mul(vector<int>& dim, int l, int d)
{
    int n = d - l + 1;
    if (n <= 2) {
        return 0;
    }

    int min = numeric_limits<int>::max();
    for (int i = l + 1; i < d; i++) {
        int num_mul = min_mat_mul(dim, l, i) + 
                      min_mat_mul(dim, i, d) + 
                      dim[l] * dim[i] * dim[d];
        if (min > num_mul) {
            min = num_mul;
        }
    }

    return min;
}

int main(void)
{
    vector<int> d = {2, 5, 1, 2, 6, 2};

    cout << min_mat_mul(d, 0, d.size() - 1) << endl;
    
    return 0;
}
