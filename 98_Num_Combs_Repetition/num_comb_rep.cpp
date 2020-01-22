#include <iostream>
#include <vector>

using namespace std;

int num_combinations_with_repetition(int n, int k)
{
    if (k == 0) {
        return 1;
    }

    if (n == 0) {
        return 0;
    }
    return num_combinations_with_repetition(n - 1, k) +
           num_combinations_with_repetition(n, k - 1);
}

int main(void)
{
    cout << num_combinations_with_repetition(5, 3) << endl;
    int n = 6;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << '\t' << num_combinations_with_repetition(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
