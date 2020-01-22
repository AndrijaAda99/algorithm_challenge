#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Memo;

// ana salkjd voskdjali milov21313ana
// ana voli milovana -- najveca podniska gornje niske

int max_poli_substr(string& str)
{
    int n = str.size();
    vector<int> dp_curr(n, 0);
    vector<int> dp_priv(n, 1);

    for (int r = 1; r < n; r++) {
        for (int l = 0; l + r < n; l++) {
            int d = l + r;
            if (str[l] == str[d]) {
                int tmp = dp_curr[l];
                dp_curr[l] = 2 + dp_priv[l + 1];
                dp_priv[l] = tmp;
            } else {
                dp_priv[l] = dp_curr[l];
                dp_curr[l] = max(dp_curr[l + 1], dp_curr[l]);
            }
        }
        dp_priv[n - r] = dp_curr[n - r];
    }

    return dp_curr[0];
}

int main(void)
{
    string s = "algoritmi_i_strukture_podataka";

    cout << max_poli_substr(s) << endl;

    
    return 0;
}
