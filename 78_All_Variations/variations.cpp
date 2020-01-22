#include <iostream>
#include <vector>

using namespace std;

void all_variations(int n, int k, vector<int>& variation)
{
    if (k == 0) {
        for (int i = 0; i < variation.size(); i++) {
            cout << variation[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        variation[variation.size() - k] = i;
        all_variations(n, k - 1, variation);
    }
}

int main(void)
{
    int n = 2;
    int k = 3;
    vector<int> variation(k, 0);

    all_variations(n, k, variation);
    
    return 0;
}
