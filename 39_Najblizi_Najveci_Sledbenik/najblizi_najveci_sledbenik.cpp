#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    vector<int> a = {1, 4, 2, 3, 3};
    vector<int> p(a.size());

    stack<int> s;

    for (int i = 0; i < a.size(); i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            p[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        p[s.top()] = a.size();
        s.pop();
    }

    for (int i = 0; i < p.size(); i++) {
        if (p[i] < a.size()) {
            cout << a[p[i]] << " ";
        } else {
            cout << "- ";
        }

    }
    cout << endl;
    
    return 0;
}
