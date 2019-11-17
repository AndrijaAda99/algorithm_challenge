#include <iostream>

using namespace std;

// O(n)
bool is_prime(int n)
{
    if (n == 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// O(sqrt(n))
bool is_prime_sqrt(int n)
{
    if (n == 1) {
        return false;
    }

    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int n;
    cin >> n;
    is_prime(n) ? cout << "y" << endl : cout << "n" << endl;
    is_prime_sqrt(n) ? cout << "y" << endl : cout << "n" << endl;
    
    return 0;
}
