#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    vector<int> a = {1, 2, 2, 2, 7, 7, 7, 7, 12, 13, 17, 20};
    int D = 5;

    int count = 0;

    int i = 0;
    int j = 1;
    while (j < a.size()) {
        if (a[j] - a[i] < D) {
            j++;
        } else if (a[j] - a[i] > D) {
            i++;
        } else { // a[j] - a[i] == D
            int count_i = 1;
            int ii = i + 1; 
            while (a[ii] == a[i]) {
                count_i++;
                ii++;
            }
            i = ii;

            int count_j = 1;
            int jj = j + 1;
            while (a[jj] == a[j]) {
                count_j++;
                jj++;
            }
            j = jj;

            count += count_i * count_j;
        }
    }

    cout << count << endl;

    count = 0;
    map<int, int> m;

    for(auto x : a) {
        m[x]++;
    }

    auto i_el = m.begin();
    auto j_el = m.begin();
    while (j_el != m.end()) {
        if (j_el->first - i_el->first < D) {
            j_el++;
        } else if (j_el->first - i_el->first > D) {
            i_el++;
        } else { // j_el->first - i_el->first == D
            count += j_el->second * i_el->second;
            j_el++;
            i_el++;
        }
    }

    cout << count << endl;

    return 0;
}
