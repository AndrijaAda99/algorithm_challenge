#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> susedi = { {1, 2}, {3, 4}, {5, 1}, {}, {6, 7}, {8}, {}, {}, {}};

void dfs(int cvor)
{
    stack<int> s;
    s.push(cvor);

    vector<bool> posecen(susedi.size());

    while (!s.empty()) {
        int v = s.top(); s.pop();
        if (!posecen[v]) {
            cout << v << " ";
            posecen[v] = true;
            for (int cvor : susedi[v]) {
                s.push(cvor);
            }
        }
    }
}

int main(void)
{
    dfs(1);
    
    return 0;
}
