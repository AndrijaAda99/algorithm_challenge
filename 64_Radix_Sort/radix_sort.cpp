#include <iostream>
#include <vector>

using namespace std;

void radix_sort(vector<int>& a, int s)
{
    vector<int> count (10);
    for (int i = 0; i < a.size(); i++) {
        count[(a[i] / s) % 10]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    vector<int> novi_a (a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        novi_a[--count[(a[i] / s) % 10]] = a[i];
    }

    a = novi_a;
}

void sortiraj(vector<int>& a)
{
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    for (int i = 1; max / i > 0; i *= 10) {
        radix_sort(a, i);
    }
}

int main(void)
{
    vector<int> a = {37, 140, 7, 10, 99, 102, 17, 25, 1, 48, 14, 3, 18};
    sortiraj(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
