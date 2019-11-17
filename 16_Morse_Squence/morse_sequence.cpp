#include <iostream>

using namespace std;

int max_pow(int i)
{
    int max = 1;
    while ((max << 1) < i) {
        max <<= 1;
    }
    return max;
}

int morse(int n)
{
    int m = 0;
    while (n != 0) {
        n -= max_pow(n);
        m = !m;
    }

    return m;

    // Free recursion
    /*if (i == 0) {*/
        //return 0;
    //}

    /*return !morse(i - max_pow(i));*/
}

int morse2(int n)
{
    if (n == 0) {
        return 1;
    }
    cout << "[ "<< n << ": ";
    int count_ones = 0;
    while (n > 0) {
        if (n & 1) {
            count_ones++;
        }
        n >>= 1;
    }

    cout << count_ones << " ] ";
    

    if (count_ones % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    for (int n = 0; n < 100; n++) {
        cout << n << ": ";
        cout << morse(n) << " ";
        cout << morse2(n) << endl;
    }
    
    return 0;
}
