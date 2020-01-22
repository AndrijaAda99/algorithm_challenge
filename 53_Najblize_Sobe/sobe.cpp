#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> najblize(vector<int>& slobodne_sobe)
{
    sort(slobodne_sobe.begin(), slobodne_sobe.end());

    int min = 0;
    for (int i = 0; i < slobodne_sobe.size() - 1; i++) {
        if (slobodne_sobe[i + 1] - slobodne_sobe[i] <= 
            slobodne_sobe[min + 1] - slobodne_sobe[min]) {
            min = i;
        }
    }

    return make_pair(slobodne_sobe[min], slobodne_sobe[min + 1]);
}


int main(void)
{
    vector<int> slobodne_sobe = {105, 107, 124, 256, 258, 300};

    pair<int, int> sobe = najblize(slobodne_sobe);
    cout << sobe.first << " " << sobe.second << endl;

    return 0;
}
