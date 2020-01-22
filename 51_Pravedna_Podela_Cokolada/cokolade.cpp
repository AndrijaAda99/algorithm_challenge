#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

int razlika(vector<int>& a, int k)
{
    int min_razlika = MAX;
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size() - k + 1; i++) {
        int razlika = a[i + k - 1] - a[i];
        if (min_razlika > razlika) {
            min_razlika = razlika;
        }
    }

    return min_razlika;
}


int main(void)
{
    vector<int> a = {10, 15, 12, 1, 35, 50};

    cout << razlika(a, 3) << endl;
    
    return 0;
}
