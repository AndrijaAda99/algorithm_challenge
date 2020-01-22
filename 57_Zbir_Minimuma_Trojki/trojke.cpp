#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int broj_parova(int n)
{
    return n * (n - 1) / 2;
}

int zbir_minimuma_trojki(vector<int>& a)
{
    sort(a.begin(), a.end());

    int zbir = 0;
    for (int i = 0; i < a.size(); i++) {
        zbir += a[i] * broj_parova(a.size() - i - 1);
    }

    return zbir;
}


int main(void)
{
    vector<int> a = {5, 2, 8, 4, 3, 1};

    cout << zbir_minimuma_trojki(a) << endl;

    
    return 0;
}
