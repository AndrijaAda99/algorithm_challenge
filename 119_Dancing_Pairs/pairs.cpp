#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> m;
    vector<int> d;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    sort(m.begin(), m.end(), greater<int>());
    sort(d.begin(), d.end(), greater<int>());

    int i = 0;
    int j = 0;

    int count = 0;
    while (j < n) {
        if (m[i] < d[j]) {
            j++;
        } else {
            count++;
            i++;
            j++;
        }
    }
    
    cout << count << endl;

    return 0;
}
