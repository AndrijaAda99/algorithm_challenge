#include <iostream>
#include <vector>

using namespace std;

int num_decodings(string& s)
{
    int i = s.size() - 1;

    int dp_priv = 1;
    int dp_curr = s[i--] != '0';
    while (i >= 0) {
        if (s[i] == '0') {
            dp_priv = dp_curr;
            dp_curr = 0;
        } else {
            int str = 10 * (s[i] - '0') + (s[i + 1] - '0');
            if (str <= 26) {
                int tmp = dp_curr;
                dp_curr += dp_priv;
                dp_priv = tmp;
            } else {
                dp_curr = dp_priv;
            }
        }
        i--;
    }

    return dp_curr;
}

int main(void)
{
    string s = "21214";
    cout << num_decodings(s) << endl;

    return 0;
}
