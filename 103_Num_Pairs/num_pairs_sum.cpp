#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> a = {1, 2, 7, 12, 13, 17, 20};
    int S = 14;

    int i = 0;
    int j = a.size() - 1;

    int count = 0;
    while (i < j) {
        if (a[i] + a[j] == S) {
            count++;
            j--;
            i++;
        } else if (a[i] + a[j] > S) {
            j--;
        } else {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}
