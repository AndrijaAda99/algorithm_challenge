#include <iostream>
#include <vector>

using namespace std;

int split(const vector<int> set, int n,
          int sum_first, int sum_second)
{
    if (n == 0) {
        return abs(sum_first - sum_second);
    }

    return min(split(set, n - 1, sum_first + set[n - 1], sum_second),
               split(set, n - 1, sum_first, sum_second + set[n - 1]));
}

int main(void)
{
    vector<int> set = {100, 300, 221, 521, 221, 321, 198, 238, 321};

    cout << split(set, set.size(), 0, 0) << endl;
    
    return 0;
}
