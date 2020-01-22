#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int max_sum_subarray(vector<int>& a, int l, int d)
{
    if (l > d) {
        return 0;
    }

    int s = l + (d - l) / 2;
    int max_left_sum = max_sum_subarray(a, l, s - 1);
    int max_right_sum = max_sum_subarray(a, s + 1, d);

    int middle_sum = a[s];
    int max_middle_sum = a[s];
    for (int i = s + 1; i <= d; i++) {
        middle_sum += a[i];
        if (max_middle_sum < middle_sum) {
            max_middle_sum = middle_sum;
        }
    }

    middle_sum = max_middle_sum;
    for (int i = s - 1; i >= l; i--) {
        middle_sum += a[i];
        if (max_middle_sum < middle_sum) {
            max_middle_sum = middle_sum;
        }
    }

    return max({max_left_sum, max_middle_sum, max_right_sum});
}

int main (void) 
{
    vector<int> a = {-1, 5, -3, 2, 7, 1, -6};

    cout << max_sum_subarray(a, 0, a.size() - 1) << endl;

    return 0;
}
