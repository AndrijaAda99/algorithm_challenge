#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int merge(vector<int>&a, int l, int s, int d)
{
    vector<int> tmp (a.size());
    for (int i = 0; i < a.size(); i++) {
        tmp[i] = a[i];
    }

    int count = 0;
    int tmp_l = l;
    int tmp_s = s + 1;
    int k = l;
    while (tmp_l <= s && tmp_s <= d) {
        if (tmp[tmp_l] > tmp[tmp_s]) {
            count += s - tmp_l + 1;
            a[k] = tmp[tmp_s];
            k++;
            tmp_s++;
        } else {
            a[k] = tmp[tmp_l];
            k++;
            tmp_l++;
        }
    }

    while (tmp_l <= s) {
        a[k] = tmp[tmp_l];
        k++;
        tmp_l++;
    }
    while (tmp_s <= d) {
        a[k] = tmp[tmp_s];
        k++;
        tmp_s++;
    }

    return count;
}

int broj_inverzija(vector<int>& a, int l, int d)
{
    if (l >= d) {
        return 0;
    }

    int count = 0;
    int s = l + (d - l) / 2;

    count += broj_inverzija(a, l, s);
    count += broj_inverzija(a, s + 1, d);

    count += merge(a, l, s, d);

    return count;
}

int main(void)
{

    vector<int> a = {5, 4, 3, 1, 2};

    cout << broj_inverzija(a, 0, a.size() - 1) << endl;

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
