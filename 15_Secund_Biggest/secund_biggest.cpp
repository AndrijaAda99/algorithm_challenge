#include <iostream>

using namespace std;

int secund_max(int a[], int n)
{
    int first_max, secund_max;
    first_max = secund_max = -1;

    for (int i = 0; i < n; i++) {
        if (first_max <= a[i]) {
            secund_max = first_max;
            first_max = a[i];
        } else if (secund_max <= a[i]){
            secund_max = a[i];
        }
    }

    return secund_max;
}

int main(void)
{

    
    return 0;
}
