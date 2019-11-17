#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    vector<int> a = {8, 4, 6, 3, 7, 2, 5};
    stack<int> s;

    int br_segmenata = 0;
    for (int i = 0; i < a.size(); i++) {
        while (!s.empty() && s.top() < a[i]) {
            s.pop();
            br_segmenata++;
        }
        if (!s.empty()) {
            br_segmenata++;
        }
        s.push(a[i]);
    }

    cout << br_segmenata << endl;
    
    return 0;
}
