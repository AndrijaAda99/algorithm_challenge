#include <iostream>
#include <utility>

using namespace std;

void exchange(int a[], int p1, int p2, int k)
{
    for (int i = 0; i < k; i++) {
        swap(a[p1 + i], a[p2 + i]);
    }
}

// O(n) recursive function
void rotate(int a[], int p1, int p2, int d1, int d2)
{
    if (d1 == 0 || d2 == 0) {
        return;
    }

    if (d1 <= d2) {
        // d1 = 4, d2 = 6
        // 1 2 3 4  5 6 7 8 9 10
        // p1       p2
        // 5 6 7 8  1 2 3 4 9 10
        //          p1      p2
        //          d1 = 4, d2 = 2
        exchange(a, p1, p2, d1);
        rotate(a, p1 + d1, p2 + d1, d1, d2 - d1);
    } else {
        // d1 = 4, d2 = 2
        // 5 6 7 8  1 2  3 4 9 10
        //          p1      p2
        //          9 10 3 4 1 2
        //               p1  p2
        //               d1 = 2, d2 = 2;
        exchange(a, p1, p2, d2);
        rotate(a, p1 + d2, p2, d1 - d2, d2);
    }
}

// O(n) rotate function done iteratively
void rotate_iter(int a[], int n, int k)
{
    int p1 = 0, p2 = k;
    int d1 = k, d2 = n - k;
    while (d1 != 0 && d2 != 0) {
        if (d1 <= d2) {
            exchange(a, p1, p2, d1);
            p1 += d1; p2 += d1; d2 -= d1;
        } else {
            exchange(a, p1, p2, d2);
            p1 += d2, d1 -= d2;
        }
    }
}

// 1 2 3 4 5 6 7 8 9 10
// l       k
//         d
// 5 6 7 8 1 2 3 4 9 10
//         l       d
//         k
// 5 6 7 8 1 2 3 4 9 10
//         l       d
//                 k
// 5 6 7 8 9 10 3 4 1 2
//              l   k   d
// 5 6 7 8 9 10 3 4 1 2
//              l   d  
//                  k
// 5 6 7 8 9 10 1 2 3 4
//                  l   d
//                  k
void rotate_iter_elegant(int a[], int n, int k)
{
    int l = 0;
    int d = k;
    while (l != k && d != n) {
        swap(a[l++], a[d++]);
        if (l == k) {
            k = d;
        } 
        if (d == n) {
            d = k;
        }
    }
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof (a) / sizeof (int);

    int k;
    cin >> k;

    rotate(a, 0, k, k, n - k);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    rotate_iter(a, n, k);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    rotate_iter_elegant(a, n, k);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
