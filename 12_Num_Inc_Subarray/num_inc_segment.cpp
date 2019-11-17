#include<iostream>

using namespace std;

// O(n^3)
int num_inc_segments(int a[], int n)
{
    int count_inc = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool isInc = true;
            for (int k = i + 1; k <= j; k++) {
                if (a[k - 1] >= a[k]) {
                    isInc = false;
                }
            }
            if (isInc) {
                cout << i << " " << j << endl;
                count_inc++;
            }
        }
    }

    return count_inc;
}

// O(n^2)
int num_inc_segments2(int a[], int n)
{
    int count_inc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && a[j - 1] < a[j]; j++) {
            cout << i << " " << j << endl;
            count_inc++;
        }
    }

    return count_inc;
}


int main(void)
{
    int a[] = {1, -5, -2, 4, -1};

    cout << num_inc_segments(a, 5) << endl;
    
    return 0;
}
