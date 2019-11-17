#include <iostream>
#include <vector>
#include <map>

using namespace std;

int broj_segmenata_zbira(vector<int>& a, int k)
{
    map<int, int> m;
    m[0] = 1;

    int prefix_sum = 0;
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        prefix_sum += a[i];
        auto it = m.find(prefix_sum - k);
        if (it != m.end()) {
            count += it->second;
        }
        m[prefix_sum]++;
    }

    return count;
}

int main(void)
{
    int k = 3;

    vector<int> a = {3, 2, 1, 2, 4, 3, 5, 1};

    cout << broj_segmenata_zbira(a, k) << endl;

    return 0;
}
