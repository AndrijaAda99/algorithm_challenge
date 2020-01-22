#include <iostream>
#include <vector>

using namespace std;

bool knapsack(vector<int>& m, int n, int M)
{
    if (M == 0) {
        return true;
    }

    if (n == 0) {
        return false;
    }

    if (knapsack(m, n - 1, M)) {
        return true;
    }

    if (m[n - 1] <= M && knapsack(m, n - 1, M - m[n - 1])) {
        return true;
    }

    return false;
}

int main(void)
{
    int M = 100;
    vector<int> m = {10, 15, 20, 30};
    if (knapsack(m, m.size(), M)) {
        cout << "da" << endl;
    } else {
        cout << "ne" << endl;
    }
    
    return 0;
}
