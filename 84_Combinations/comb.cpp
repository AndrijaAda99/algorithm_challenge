#include <iostream>
#include <vector>

using namespace std;

void combinations(vector<int>& comb, int i, int n)
{
    int k = comb.size();
    if (i == k) {
        for (int i = 0; i < k; i++) {
            cout << comb[i] << " ";
        }
        cout << endl;
        return;
    }

    int start = i == 0 ? 1 : comb[i - 1] + 1;
    int end = n - k + i + 1;

        
    for (int x = start; x <= end; x++) {
        comb[i] = x; 
        combinations(comb, i + 1, n);
    }
}

void combinations(vector<int>& comb, int i, int n_min, int n_max)
{
    int k = comb.size();
    if (i == k) {
        for (int i = 0; i < k; i++) {
            cout << comb[i] << " ";
        }
        cout << endl;
        return;
    }

    if (n_min - n_max + 1 > k - i) {
        return;
    }

    comb[i] = n_min;
    combinations(comb, i + 1, n_min + 1, n_max);
    combinations(comb, i, n_min + 1, n_max);
}

int main(void)
{
    int n = 5;
    int k = 3;
    vector<int> a(k);

    combinations(a, 0, n);
    combinations(a, 0, 1, 5);
    return 0;
}
