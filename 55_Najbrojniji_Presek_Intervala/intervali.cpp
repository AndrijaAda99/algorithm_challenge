#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int broj_intervala(vector<pair<int, int>>& intervali)
{
    vector<pair<int, bool>> tacke;
    for (int i = 0; i < intervali.size(); i++) {
        tacke.push_back(make_pair(intervali[i].first, true));
        tacke.push_back(make_pair(intervali[i].second, false));
    }

    sort(tacke.begin(), tacke.end());

    int br_intervala = 0;
    int max_br_intervala = 0;

    for (int i = 0; i < tacke.size(); i++) {
        if (tacke[i].second == true) {
            br_intervala++;
        } else {
            br_intervala--;
        }

        if (max_br_intervala < br_intervala) {
            max_br_intervala = br_intervala;
        }
    }

    return max_br_intervala;
}

int main(void)
{
    vector<pair<int, int>> intervali = {
        {2, 6}, {0, 4}, {8, 11}, {10, 12}, {3, 7}, {12, 15}
    };

    cout << broj_intervala(intervali) << endl;

    return 0;
}
