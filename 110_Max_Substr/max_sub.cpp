#include <iostream>
#include <vector>

using namespace std;

int max_substr(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> dp(m + 1);

    dp[0] = 0;
    int max_substr_size = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = m; j > 0; j--) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = 1 + dp[j - 1];
            } else {
                dp[j] = 0;
            }
            if (max_substr_size < dp[j]) {
                max_substr_size = dp[j];
            }
        }
    }

    return max_substr_size;
}

int main(void)
{
    string a = "xyxy";
    string b = "yxyx";

    cout << max_substr(a, b) << endl;
    
    return 0;
}
