#include <iostream>
#include <vector>

using namespace std;

int num_decodings(string& s, int i, vector<int>& memo)
{
    if (memo[i] != -1) {
        return memo[i];
    }

    if (s.size() == i) {
        return memo[i] = 1;
    }

    if (s[i] == '0') {
        return memo[i] = 0;
    }

    int res = num_decodings(s, i + 1, memo);
    if ((s.size() > i + 1) && (10 * (s[i] - '0') + (s[i + 1] - '0') <= 26)) {
        res += num_decodings(s, i + 2, memo);
    }

    return memo[i] = res;
}

int main(void)
{
    string s = "21214";
    vector<int> memo(s.size() + 1, -1);
    cout << num_decodings(s, 0, memo) << endl;
    for (int i = 0; i < memo.size(); i++) {
        cout << memo[i] << " ";
    }
    cout << endl;

    return 0;
}
