#include <iostream>

using namespace std;

void all_strings(string& bin, int i)
{
    if (i == bin.size()) {
        cout << bin << endl;
        return;
    }

    bin[i] = '0';
    all_strings(bin, i + 1); // levo

    if (i == 0 || bin[i - 1] != '1') {
        bin[i] = '1';
        all_strings(bin, i + 1); // desno
    }
}

int main(void)
{
    
    int k = 4;
    string bin(k, '0');
    
    all_strings(bin, 0);

    return 0;
}
