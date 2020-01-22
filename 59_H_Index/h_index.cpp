#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h_index_optimalno(vector<int>& citati)
{
    sort(citati.begin(), citati.end(), greater<int>());

    int index = 0;
    while (index < citati.size() && index < citati[index]) {
        index++;
    }

    return index;
}

int h_index(vector<int>& citati)
{
    vector<int> count (citati.size() + 1);

    for (int i = 0; i < citati.size(); i++) {
        int index = citati[i] > citati.size() ? citati.size() : i;
        count[index]++;
    }

    int index = citati.size();
    int h = count[index];
    while (index > 0 && h <= index) {
        h += count[--index];
    }

    return h;
}

int main(void)
{
    vector<int> citati = {2, 5, 7, 10, 1, 7, 5};
    cout << h_index_optimalno(citati) << endl;
    cout << h_index(citati) << endl;

    return 0;
}
