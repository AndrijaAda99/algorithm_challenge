#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int broj_razlicitih_segmenata(vector<int>& a)
{
    unordered_map<int, int> um;

    int count = 0;
    int p = 0;
    for (int k = 0; k < a.size(); k++) {
        if (um.find(a[k]) != um.end()) {
            int p_tmp = um[a[k]] + 1;
            for (int i = p; i < p_tmp; i++) {
                um.erase(a[i]);
            }
            p = p_tmp;
        }
            
        um[a[k]] = k;
        count += k - p;
    }

    return count;
}

int main(void)
{
    vector<int> a = {3, 2, 1, 2, 4, 3, 5, 1};

    cout << broj_razlicitih_segmenata(a) << endl;

    
    return 0;
}
