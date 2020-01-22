#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ispisi_najveci_segment_uzastopnih(vector<int>& a)
{
    sort(a.begin(), a.end());

    // Izbacimo duplikate
    int n = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[i - 1]) {
            a[n++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << n << endl;

    int duzina = 0;
    int max_duzina = 0;
    int start = 0;
    int max_start = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            duzina++;
        } else {
            duzina = 0;
            start = i;
        }

        if (max_duzina < duzina + 1) {
            max_duzina = duzina + 1;
            max_start = start;
        }
    }

    cout << max_duzina << " " << max_start << endl;
    for (int i = max_start; i < max_start + max_duzina; i++) {
        cout << a[i] << " ";
    }
}

int main(void)
{
    vector<int> a = {4, 8, 1, -6, 9, 5, -9, 10, -1, 3, 0, 1, 2};

    ispisi_najveci_segment_uzastopnih(a);

    return 0;
}
