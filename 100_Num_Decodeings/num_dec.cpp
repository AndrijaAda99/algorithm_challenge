#include <iostream>
#include <vector>

using namespace std;

int num_decodings(string& s, int i)
{
    if (s.size() == i) {
        return 1;
    }
    if (s[i] == '0') {
        return 0;
    }

    int res = num_decodings(s, i + 1);
    if (s.size() > i + 1 && 10 * (s[i] - '0') + s[i + 1] - '0' <= 26) {
        res += num_decodings(s, i + 2);
    }

    return res;
}

int main(void)
{
    string s = "21214";
    cout << num_decodings(s, 0) << endl;

    return 0;
}
