#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void najveci_prethodnik(vector<int>& a)
{
    stack<int> s;

    for (int x : a) {
        while (!s.empty() && x > s.top()) {
            s.pop();
        }

        if (s.empty()) {
            cout << "- ";
        } else {
            cout << s.top() << " ";
        }

        s.push(x);
    }
}

int main(void)
{
    vector<int> a = {3, 7, 4, 2, 6, 5};

    najveci_prethodnik(a);
    
    return 0;
}
