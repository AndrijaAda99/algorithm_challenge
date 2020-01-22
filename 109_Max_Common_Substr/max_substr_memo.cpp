#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Memo;

int max_substr(string& s1, int n, string& s2, int m, Memo memo)
{
    if (memo[n][m] != -1) {
        return memo[n][m];
    }

    if (n == 0 || m == 0) {
        return memo[n][m] = 0;
    }

    if (s1[n - 1] == s2[m - 1]) {
        return memo[n][m] =  max_substr(s1, n - 1, s2, m - 1, memo) + 1;
    }

    return memo[n][m] = max(max_substr(s1, n - 1, s2, m, memo),
                            max_substr(s2, n, s2, m - 1, memo));
}

int main(void)
{
    string s1 = "ababc";
    string s2 = "babbca";

    Memo memo(s1.size() + 1);
    for (int i = 0; i < s1.size() + 1; i++) {
        memo[i].resize(s2.size() + 1, -1);
    }

    cout << max_substr(s1, s1.size(), s2, s2.size(), memo) << endl;
    
    return 0;
}
