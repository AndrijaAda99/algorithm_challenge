#include <iostream>
#include <vector>

using namespace std;

int max_sum(vector<int>& a)
{
    int sum_with_last = a[0];
    int sum_without_last = 0;

    for (int i = 1; i < a.size(); i++) {
        int old_max_sum = max(sum_with_last, sum_without_last);
        sum_with_last = sum_without_last + a[i];
        sum_without_last = old_max_sum;
    }

    return max(sum_with_last, sum_without_last);
}

int main(void)
{
    vector<int> a = {7, 3, 2, 4, 1, 5};

    cout << max_sum(a) << endl;
    
    return 0;
}
