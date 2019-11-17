#include <iostream>

using namespace std;

int main(void)
{
    int a[] = {1, -2, 5, -3, 4, 2, 3, -5};
    int n = sizeof (a) / sizeof (int);

    int prefix_sum = 0;
    int min_prefix_sum = prefix_sum;
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        cout << prefix_sum << " ";
        int sufix_sum = prefix_sum - min_prefix_sum;

        if (max_sum < sufix_sum) {
            max_sum = sufix_sum;
        }

        if (min_prefix_sum > prefix_sum) {
            min_prefix_sum = prefix_sum;
        }
    }

    cout << max_sum << endl;

    return 0;
}
