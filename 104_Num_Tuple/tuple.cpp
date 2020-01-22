#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> a = {-7, -3, -1, 0, 1, 2, 5, 7};

    int count = 0;

    for (int k = a.size() - 1; k > 1 && a[k] >= 0; k--) {
        int S = -a[k];

        int i = 0;
        int j = k - 1;
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
    }
    
    cout << count << endl;
    
    return 0;
}
