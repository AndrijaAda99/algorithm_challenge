#include <iostream>
#include <vector>

using namespace std;

bool next_var(int n, int k, vector<int>& var)
{
    int i = var.size() - 1;
    while (i >= 0 && var[i] == n) {
        var[i--] = 1;
    }

    if (i == -1) {
        return false;
    }

    var[i]++;
    return true;
}

int main(void)
{
    int k = 3;
    int n = 2;
    vector<int> var(k, 1);

    do {
        for (int i = 0; i < k; i++) {
            cout << var[i] << " ";
        }
        cout << endl;
    } while (next_var(n, k, var));

    return 0;
}
