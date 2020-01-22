#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Links;
typedef vector<int> Colors;

bool color_graph(Links& links, int node, Colors& colors)
{
    if (node == links.size()) {
        return true;
    }

    for (int color = 1; color <= 3; color++) {
        bool color_flag = true;
        for (int adjacent : links[node]) {
            if (colors[adjacent] == color) {
                color_flag = false;
            }
        }
        if (color_flag) {
            colors[node] = color;
            if (color_graph(links, node + 1, colors)) {
                return true;
            }
        }
    }

    return false;
}

int main(void)
{
    Links links = {
        {1, 3, 5},
        {0, 2, 3, 4},
        {1, 4 ,7},
        {0, 1, 5, 6},
        {1, 2, 6, 7},
        {0, 3, 4},
        {3, 4, 5, 7},
        {2, 4, 6},
    };

    Colors colors(links.size());

    int node = 0;
    while (node < links.size() && links[node].size() == 0) {
        colors[node++] = 1;
    }

    colors[node] = 1;
    colors[links[node][0]] = 2;
    color_graph(links, node, colors);
    for (int i = 0; i < colors.size(); i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}
