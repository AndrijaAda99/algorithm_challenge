#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int quick_select(vector<int>& a, int l, int d, int k)
{
    while (1) {
        swap(a[l], a[l + rand() % (d - l + 1)]);

        int i = l + 1;
        int j = d;
        while (i <= j) {
            if (a[i] < a[l]) {
                i++;
            } else if (a[j] >= a[l]) {
                j--;
            } else {
                swap(a[i], a[j]);
                i++; j--;
            }
        }
        swap(a[l], a[j]);

        if (j == k) {
            return a[k];
        }

        if (j < k) {
            l = j + 1;
        } else if (j > k) {
            d = j - 1;
        }
    }
}

int main (void)
{
    vector<int> a = {4, 10, 2, 5, 1, 7, 8};

    cout << quick_select(a, 0, a.size() - 1, 5) << endl;

    return 0;
}
