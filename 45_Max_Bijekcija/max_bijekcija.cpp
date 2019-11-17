#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    vector<int> f = {2, 4, 0, 2, 4, 3};
    vector<int> u(f.size(), 0);
    queue<int> q;

    for (int i = 0; i < f.size(); i++) {
        u[f[i]]++;
    }

    for (int i = 0; i < u.size(); i++) {
        if (u[i] == 0) {
            q.push(i);
        }
    }

    int n = f.size();
    while (!q.empty()) {
        int i = q.front(); q.pop();
        n--;
        u[f[i]]--;
        if (u[f[i]] == 0) {
            q.push(f[i]);
        }
    }

    cout << n << endl;

    
    return 0;
}
