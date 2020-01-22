#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& a)
{
    int m = *max_element(a.begin(), a.end());

    vector<int> c (m + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        c[a[i]]++;
    }

    int i = 0;
    for (int j = 0; j < c.size(); j++) {
        while (c[j] > 0) {
            a[i++] = j;
            c[j]--;
        }
    }
}

void counting_sort_v2(vector<int>& a)
{
    vector<int> c (*max_element(a.begin(), a.end()) + 1, 0);
    vector<int> b (a.size());

    for (int i = 0; i < a.size(); i++) {
        c[a[i]]++;
    }

    for (int i = 1; i < c.size(); i++) {
        c[i] += c[i - 1];
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    a = b;
}

int main(void)
{
    vector<int> a = {2, 5, 3, 0, 2, 3, 0, 3};

    counting_sort_v2(a);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
