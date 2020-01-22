#include <iostream>
#include <vector>

using namespace std;

bool next_subset(vector<int>& subset, int n)
{
    if (subset.empty()) {
        subset.push_back(1);
        return true;
    }

    if (subset[subset.size() - 1] < n) {
        subset.push_back(subset[subset.size() - 1] + 1);
        return true;
    }

    subset.pop_back();

    if (subset.empty()) {
        return false;
    }

    subset[subset.size() - 1]++;
}

int main(void)
{
    vector<int> subset;
    do {
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
    } while(next_subset(subset, 4));

    return 0;
}
