#include <iostream>
#include <vector>

using namespace std;

bool is_substr(string& str1, string& str2)
{
    int n = str1.size();
    int m = str2.size();

    int i = 0;
    int j = 0;

    while (i < n && j < m) {

        if (str1[i] == str2[j]) {
            j++;
        }

        i++;
    }

    return j == m;
}

int main(void)
{

    string s1 = "abcbbcaabbbcd";
    string s2 = "abbcabc";

    if (is_substr(s1, s2)) {
        cout << "da" << endl;
    } else {
        cout << "ne" << endl;
    }

    return 0;
}
