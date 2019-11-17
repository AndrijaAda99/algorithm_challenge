#include <iostream>

using namespace std;


string gray(int n, int k)
{
    if (n == 0) {
        return " ";
    }
    if (k < (1 << (n - 1))) {
        return "0" + gray(n - 1, k);
    } else {
        return "1" + gray(n - 1, (1 << n) - (k + 1));
    }
}

int main(void)
{
    int n;
    cin >> n;

    string s = "";
    for (int i = 0; i < (1 << n); i++) {
        s += gray(n, i);
    }
    cout << s << endl;
    
    return 0;
}
