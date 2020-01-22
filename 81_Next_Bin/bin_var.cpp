#include <iostream>

using namespace std;

bool next_bin(string& bin)
{
    int i = bin.size() - 1;
    while ((i >= 0 && bin[i] == '1') || 
            (i >= 1 && bin[i - 1] == '1')) {
        bin[i--] = '0';
    }
    if (i < 0) {
        return false;
    }

    bin[i] = '1';
    return true;
}

int main(void)
{
    int k = 4;
    string bin(k, '0');

    do {
        cout << bin << endl;
    } while (next_bin(bin));
    return 0;
}
