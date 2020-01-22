#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> poeni = {50, 35, 34, 60, 80, 90, 100, 23, 65, 32, 76, 43};

    sort(poeni.begin(), poeni.end());

    int m = 5;
    for (int i = 0; i < m; i++) {
        int prag;
        cin >> prag;

        auto iter = lower_bound(poeni.begin(), poeni.end(), prag);
        cout << distance(iter, poeni.end()) << endl;
    }

    return 0;
}
