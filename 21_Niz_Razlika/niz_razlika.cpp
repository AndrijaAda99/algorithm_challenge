#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> p(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int l, d, k;
        cin >> l;
        cin >> d;
        cin >> k;

        p[l] += k;
        p[d + 1] -= k;
    }

    a[0] = p[0];
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + p[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
