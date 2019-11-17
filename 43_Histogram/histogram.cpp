#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    vector<int> a = {3, 5, 5, 8, 6, 4, 9, 2, 4};

    stack<int> s;
    int max_P = 0;

    for (int i = 0; i < a.size(); i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            int h = a[s.top()]; s.pop();
            while (!s.empty() && a[s.top()] == h) {
                s.pop();
            }
            int l = s.empty() ? -1 : s.top();
            int d = i - l - 1;
            cout << h << ":" << d << ": ";
            int P = d * h;
            cout << P << endl;
            if (max_P < P) {
                max_P = P;
            }
        }
        s.push(i);
    }

    cout << max_P << endl;

    return 0;
}
