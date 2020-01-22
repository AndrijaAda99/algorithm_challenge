#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> a = {7, 2, 3, 5, 1 ,6};
    int S = 8;

    int i = 0;
    int j = 0;

    int sum = a[0];
    while (j < a.size()) {
        if (sum < S) {
            j++;

            if (j >= a.size()) {
                break;
            }

            sum += a[j];
        } else { // sum >= S
            if (sum == S) {
                cout << "(" << i << "," << j << ")" << endl;
            }
            sum -= a[i];
            i++;
        }
    }

    return 0;
}
