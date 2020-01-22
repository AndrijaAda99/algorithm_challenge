#include <iostream>
#include <vector>

using namespace std;

void print_board(vector<int> perm)
{
    for (int i = 0; i < perm.size(); i++) {
        for (int j = 0; j < perm.size(); j++) {
            if (perm[i] == j) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool is_safe(vector<int> perm, int k)
{
    for (int i = 0; i < k; i++) {
        if (perm[i] == perm[k]) {
            return false;
        }
        if (abs(i - k) == abs(perm[i] - perm[k])) {
            return false;
        }
    }

    return true;
}

static int count = 0;
void n_queens(vector<int>& perm, int k)
{
    if (k == perm.size()) {
        count++;
        cout << count << ":" << endl;
        print_board(perm);
        return;
    }

    for (int i = 0; i < perm.size(); i++) {
        perm[k] = i;
        if (is_safe(perm, k)) {
            n_queens(perm, k + 1);
        }
    }
}

void n_queens(int n)
{
    vector<int> perm(n);
    n_queens(perm, 0);
}

int main(void)
{
    n_queens(8);
    
    return 0;
}
