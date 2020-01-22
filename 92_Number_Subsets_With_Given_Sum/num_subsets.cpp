#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_subset_with_given_sum(vector<int>& set, int k, 
                              int curr_sum, int target_sum)
{
    if (target_sum == 0) {
        return 1;
    }

    if (set[k] > target_sum) {
        return 0;
    }

    if (curr_sum < target_sum) {
        return 0;
    }

    return num_subset_with_given_sum(set, k + 1, 
                curr_sum - set[k], target_sum - set[k]) +

           num_subset_with_given_sum(set, k + 1, 
                curr_sum - set[k], target_sum);
}

int main(void)
{
    vector<int> set = {1, 2, 3, 4, 5, 6};

    int sum = 0;
    for (int i = 0; i < set.size(); i++) {
        sum += set[i];
    }

    sort(begin(set), end(set));
    cout << endl << num_subset_with_given_sum(set, 0, sum, 9) << endl;
    
    return 0;
}
