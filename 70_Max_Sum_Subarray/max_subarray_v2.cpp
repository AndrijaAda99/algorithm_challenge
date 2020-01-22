#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void max_sum_subarray(vector<int>& a, int l, int d, 
                      int& sum, int& max_sum,
                      int& max_pref, int& max_suf)
{
    if (l == d) {
        sum = a[l];
        max_sum = a[l];
        max_pref = a[l];
        max_suf = a[l];
        return;
    }

    int s = l + (d - l) / 2;

    int sum_l, max_sum_l, max_pref_l, max_suf_l;
    max_sum_subarray(a, l, s, sum_l, max_sum_l, max_pref_l, max_suf_l);

    int sum_d, max_sum_d, max_pref_d, max_suf_d;
    max_sum_subarray(a, s + 1, d, sum_d, max_sum_d, max_pref_d, max_suf_d);

    sum = sum_l + sum_d;
    max_sum = max({max_sum_l, max_sum_d, max_suf_l + max_pref_d});
    max_pref = max({max_pref_l, sum_l + max_pref_d});
    max_suf = max({max_suf_d, sum_d + max_suf_l});
}

int main (void)
{
    vector<int> a = {-1, 5, -3, 2, 7, 1, -6};
    int sum, max_sum, max_pref, max_suf;

    max_sum_subarray(a, 0, a.size() - 1, sum, max_sum, max_pref, max_suf);

    cout << max_sum << endl;
    return 0;
}
