#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interval(vector<int>& t, int x)
{
    return distance(t.begin(), upper_bound(t.begin(), t.end(), x));
}

void sortiraj(vector<int>& t, vector<int>& x)
{
    vector<int> count (t.size() + 1, 0);

    for (int i = 0; i < x.size(); i++) {
        count[interval(t, x[i])]++;
    }

    vector<int> position (t.size() + 1);
    position[0] = 0;
    for (int i = 0; i < t.size(); i++) {
        position[i] = position[i - 1] + count[i - 1];
    }

    vector<int> novi_x (x.size());
    for (int i = 0; i < x.size(); i++) {
        int index = interval(t, x[i]);
        novi_x[position[index]] = x[i];
        position[index]++;
    }

    x = novi_x;
}

int main(void)
{
    vector<int> t = {0, 5, 7, 11, 15};
    vector<int> x = {6, 9, 8, -1, 12};

    sortiraj(t, x);

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
