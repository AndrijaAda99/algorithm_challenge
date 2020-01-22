#include <iostream>
#include <vector>

using namespace std;

bool check_queens(vector<int> perm)
{
    for (int i = 0; i < perm.size(); i++) {
        for (int j = i + 1; j < perm.size(); j++) {
            if (abs(i - j) == abs(perm[i] - perm[j])) {
                return true;
            }
        }
    }

    return false;
}

void permutations(vector<int> perm, int k)
{
    if (k == 1) {
        if (!check_queens(perm)) {
            for (int i = 0; i < perm.size(); i++) {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        swap(perm[i], perm[k - 1]);
        permutations(perm, k - 1);
        swap(perm[i], perm[k - 1]);
    }
}

int main(void)
{

    int n = 4;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    permutations(a, n);
    
    return 0;
}
