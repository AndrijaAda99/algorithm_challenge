#include <iostream>

using namespace std;

void sort_by_index(int a[], int n)
{
    int i = 0;
    while (n > i) {
        if (a[i] == a[a[i]]) {
            i++;
        } else {
            swap(a[i], a[a[i]]);
        }
    }
}

int main(void)
{
    int a[] = {8, 1, 6, 5, 0, 5, 2, 3, 1};
    int n = sizeof (a) / sizeof (int);

    sort_by_index(a, n);

    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            cout << a[i] << " " << i << " ";
        }
    }
    cout << endl;
   
    return 0;
}
