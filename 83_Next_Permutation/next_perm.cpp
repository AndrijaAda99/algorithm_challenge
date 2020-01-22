#include <iostream>
#include <vector>

using namespace std;

int next_perm(vector<int>& perm)
{
    int i = perm.size() - 2;
    while (i >= 0 && perm[i] > perm[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    int j = perm.size() - 1;
    while (perm[i] > perm[j]) {
        j--;
    }

    swap(perm[i], perm[j]);

    j = perm.size() - 1;
    while (i < j) {
        swap(perm[++i], perm[j--]);
    }

    return true;
}

int main(void)
{
    int n = 3;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
    } while (next_perm(perm));
    
    return 0;
}
