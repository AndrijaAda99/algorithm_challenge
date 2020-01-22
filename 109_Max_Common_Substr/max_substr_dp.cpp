#include <iostream>
#include <vector>

using namespace std;

int max_substr(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> dp(m + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        int priv = dp[0];
        for (int j = 1; j < m + 1; j++) {
            int tmp = dp[j];
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = priv + 1;
            } else {
                dp[j] = max(dp[j - 1], dp[j]);
            }
            priv = tmp;
        }
        
    }

    return dp[m];
}

int main(void)
{
    string s1 = "ababc";
    string s2 = "babbca";

    cout << max_substr(s1, s2) << endl;
    
    return 0;
}
