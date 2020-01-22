#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> Poly;

Poly karatsuba(Poly p1, Poly p2)
{
    int n = p1.size();

    if (n == 1) {
        return Poly (1, p1[0] * p2[0]);
    }

    Poly a (n / 2);
    Poly b (n / 2);
    Poly c (n / 2);
    Poly d (n / 2);
    for (int i = 0; i < n / 2; i++) {
        a[i] = p1[i];
        b[i] = p1[i + n / 2];
        c[i] = p2[i];
        d[i] = p2[i + n / 2];
    }

    Poly ab = karatsuba(a, c);
    Poly bd = karatsuba(b, d);

    for (int i = 0; i < n / 2; i++) {
        a[i] += b[i];
        c[i] += d[i];
    }

    Poly abcd = karatsuba(a, c);
    for (int i = 0; i < n / 2; i++) {
        abcd[i] -= ab[i] + bd[i];
    }

    Poly result(2 * n);
    for (int i = 0; i < n; i++) {
        result[i] += ab[i];
        result[i + n / 2] += abcd[i];
        result[i + n] += bd[i];
    }
    
    return result;
}

int main(void)
{
    Poly poly1 = {1., 2., 3., 0.};
    Poly poly2 = {2., 2., 2., 0.};

    Poly p  = karatsuba(poly1, poly2);

    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    
    return 0;
}
