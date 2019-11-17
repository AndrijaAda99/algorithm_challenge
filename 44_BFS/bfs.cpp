#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> a = {{1, 2} , {3, 4}, {5}, {}, {6, 7}, {8}, {}, {}, {}};

void dfs(int cvor)
{
    queue<int> q;
    vector<bool> posecen(a.size());

    q.push(cvor);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        posecen[v] = true;
        for (int sused : a[v]) {
            if (!posecen[sused]) {
                q.push(sused);
            }
        }
    }
    cout << endl;
}

int main(void)
{

    dfs(0);
    return 0;
}
