#include <iostream>
#include <vector>

using namespace std;

void all_subsets(vector<int>& set, vector<int>& subset)
{
    if (set.size() == 0) {
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    int tmp = set.back();
    set.pop_back();
    all_subsets(set, subset);

    subset.push_back(tmp);
    all_subsets(set, subset);

    set.push_back(tmp);
    subset.pop_back();
}

void all_subsets(vector<int>& set, int i,
                 vector<int>& subset, int j)
{
    if (set.size() == i) {
        for (int i = 0; i < j; i++) {
            if (subset[i] != 0) {
                cout << subset[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    all_subsets(set, i + 1, subset, j);
    subset[j] = set[i];
    all_subsets(set, i + 1, subset, j + 1);

}

int main(void)
{
    vector<int> set = {1, 2, 3, 4};
    vector<int> subset(set.size());
    all_subsets(set, 0, subset, 0);

    return 0;
}
