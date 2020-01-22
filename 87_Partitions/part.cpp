#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& part, int i, int n, int s_max)
{
    if (n == 0) {
        for (int j = 0; j < i; j++) {
            cout << part[j] << " ";
        }
        cout << endl;
        return;
    }

    for (int s = 1; s <= min(s_max, n); s++) {
        part[i] = s;
        partition(part, i + 1, n - s, s);
    }
}

void partition2(vector<int>& part, int i, int n, int s_max)
{
    if (n == 0) {
        for (int j = 0; j < i; j++) {
            cout << part[j] << " ";
        }
        cout << endl;
        return;
    }

    if (s_max == 0) {
        return;
    }

    partition2(part, i, n, s_max - 1);
    if (n >= s_max) {
        part[i] = s_max;
        partition2(part, i + 1, n - s_max, s_max); 
    }
}

int main(void)
{
    int n = 4;
    vector<int> a(n);
    partition2(a, 0, n, n);
    
    return 0;
}
