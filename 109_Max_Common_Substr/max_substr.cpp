#include <iostream>
#include <vector>

using namespace std;

int max_substr(string& s1, int n, string& s2, int m)
{
    if (n == 0 || m == 0) {
        return 0;
    }

    if (s1[n - 1] == s2[m - 1]) {
        return max_substr(s1, n - 1, s2, m - 1) + 1;
    }

    return max(max_substr(s1, n - 1, s2, m),
               max_substr(s2, n, s2, m - 1));
}

int main(void)
{
    string s1 = "ababc";
    string s2 = "babbca";

    cout << max_substr(s1, s1.size(), s2, s2.size()) << endl;
    
    return 0;
}
