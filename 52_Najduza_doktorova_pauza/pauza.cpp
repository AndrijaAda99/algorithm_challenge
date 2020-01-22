#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int najduza_pauza(vector<pair<int, int>>& termini)
{
    int max_pauza = 0;

    sort(termini.begin(), termini.end(), 
            [] (pair<int, int> a, pair<int, int> b){
                return a.first < b.first;
            });

    for (int i = 0; i < termini.size() - 1; i++) {
        int pauza = termini[i + 1].first - 
            (termini[i].first + termini[i].second);
        if (max_pauza < pauza) {
            max_pauza = pauza;
        }
    }

    return max_pauza;
}

int main(void)
{
    vector<pair<int, int>> termini = {{10, 2}, {0, 2}, {5, 4}, {14, 1}};

    cout << najduza_pauza(termini) << endl;
    return 0;
}
