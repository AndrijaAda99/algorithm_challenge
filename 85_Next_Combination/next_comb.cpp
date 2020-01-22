#include <iostream>
#include <vector>

using namespace std;

bool next_comb(vector<int>& comb, int n)
{
    int k = comb.size();
    int i = k - 1;
    while (i >= 0 && comb[i] == n - k + i + 1) {
        i--;
    }
    if (i < 0) {
        return false;
    }

    comb[i++]++;
    while (i < k) {
        comb[i] = comb[i - 1] + 1;
        i++;
    }

    return true;
}

int main(void)
{
    int k = 3;
    int n = 5;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        a[i] = i + 1;
    }
    do {
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } while (next_comb(a, n));
    
    return 0;
}
