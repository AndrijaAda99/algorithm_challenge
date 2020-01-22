#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> perm, int k)
{
    if (k == 0) {
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        swap(perm[i], perm[k - 1]);
        permutation(perm, k - 1);
        swap(perm[i], perm[k - 1]);
    }
}

int main(void)
{
    vector<int> set = {1, 2, 3};
    permutation(set, 3);
    return 0;
}
