#include <iostream>

using namespace std;

// O(n^3): Racunamo sumu za sve moguce segmente
int max_segment_sum(int a[], int n)
{
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += a[k];
            }
            if (max_sum < sum) {
                max_sum = sum;
            }
        }
    }

    return max_sum;
}

// O(n^2): Efikasnije racunanje sume, ali idalje se uporedjuju svi segmenti
int max_segment_sum2(int a[], int n)
{
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (max_sum < sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

// O(n^2)
int max_segment_sum3(int a[], int n)
{
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i] > a[i] ? sum + a[i] : a[i];
        if (max_sum < sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int main(void)
{
    int a[] = {2, -3, 4, -1, 3};

    cout << max_segment_sum(a, 5) << endl;
    cout << max_segment_sum2(a, 5) << endl;
    cout << max_segment_sum3(a, 5) << endl;
    
    return 0;
}
