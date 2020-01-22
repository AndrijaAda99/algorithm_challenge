#include <iostream>
#include <vector>

using namespace std;

// ana salkjd voskdjali milov21313ana
// ana voli milovana -- najveca podniska gornje niske

int max_poli_substr(string& str, int l, int d)
{
    if (l > d) {
        return 0;
    }
    if (l == d) {
        return 1;
    }

    if (str[l] == str[d]) {
        return 1 + max_poli_substr(str, l + 1, d - 1);
    }

    return max(max_poli_substr(str, l + 1, d),
               max_poli_substr(str, l, d - 1));
}

int main(void)
{
    string s = "algoritmi_i_strukture_podataka";
    cout << max_poli_substr(s, 0, s.size() - 1) << endl;
    
    return 0;
}
