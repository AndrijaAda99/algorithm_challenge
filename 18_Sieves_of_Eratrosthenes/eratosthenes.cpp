#include <iostream>

using namespace std;

void erotesthenes(bool prime[], int n)
{
    for (int i = 0; i < n; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    bool prime[n];
    erotesthenes(prime, n);

    for (int i = 0; i < n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
