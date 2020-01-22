#include <iostream>
#include <vector>

using namespace std;

bool pretrazi(vector<int>& a)
{
    int l = 0;
    int d = a.size() - 1;

    while (l <= d) {
        int s = l + (d - l) / 2;
        if (a[s] < s) {
            l = s + 1;
        } else {
            d = s - 1;
        }
    }

    if (l < a.size() && a[l] == l) {
        return true;
    }

    return false;
}


int main(void)
{
    vector<int> a = {-3, -2, 0, 1, 3, 5, 7, 9};

    if (pretrazi(a)) {
        cout << "Nadjen" << endl;
    } else {
        cout << "Nije nadjen" << endl;
    }
    
    return 0;
}
