#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Memo;

// ana salkjd voskdjali milov21313ana
// ana voli milovana -- najveca podniska gornje niske

int max_poli_substr(string& str, int l, int d, Memo& memo)
{
    if (memo[l][d] != -1) {
        return memo[l][d];
    }

    if (l > d) {
        return memo[l][d] = 0;
    }
    if (l == d) {
        return memo[l][d] =1;
    }

    if (str[l] == str[d]) {
        return memo[l][d] = 1 + max_poli_substr(str, l + 1, d - 1, memo);
    }

    return memo[l][d] = max(max_poli_substr(str, l + 1, d, memo),
                            max_poli_substr(str, l, d - 1, memo));
}

int main(void)
{
    string s = "algoritmi_i_strukture_podataka";
    Memo m(s.size() + 1);
    for (int i = 0; i < s.size() + 1; i++) {
        m[i].resize(s.size() + 1, -1);
    }

    cout << max_poli_substr(s, 0, s.size() - 1, m) << endl;
    
    return 0;
}
