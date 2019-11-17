#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_of_rotation_for_max_weighted_sum2(const vector<int>& a) 
{
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
    long long int weighted_sum = 0;
    long long int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        weighted_sum += i * a[i];
        sum += a[i];
    }

    int max_weighted_sum = weighted_sum;
    int max_rotation_num = 0;
    cout << max_rotation_num << " " << weighted_sum << endl;
    for (int i = 1; i < a.size(); i++) {
        weighted_sum = weighted_sum - sum + a.size() * a[i - 1];
        cout << i << " " << weighted_sum << endl;
        if (max_weighted_sum < weighted_sum) {
            max_weighted_sum = weighted_sum;
            max_rotation_num = i;
        }
    }

    return max_rotation_num;
}

int main(void)
{
    vector<int> a = {4, 2, 1, 6};
    cout << num_of_rotation_for_max_weighted_sum2(a) << endl;

    
    
    return 0;
}
