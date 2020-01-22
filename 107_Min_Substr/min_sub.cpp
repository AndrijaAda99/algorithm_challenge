#include <iostream>
#include <vector>
#include <limits>
#include <map>

using namespace std;

int min_substr_size(string& str, string& S)
{
    map<char, int> m;

    int min_i = 0;
    int min_j = 0;
    int min_size = numeric_limits<int>::max();
    for (int j = 0, i = 0; j < str.size(); j++) {
        if (S.find(str[j]) == string::npos) {
            continue;
        }
        m[str[j]]++;

        if (m.size() == S.size()) {
            // sve dok nije u S ili je u mapi vece od 1
            // // sve dok nije u S ili je u mapi vece od 1
            while (S.find(str[i]) == string::npos || m[str[i]] > 1) {
                if (S.find(str[i]) == string::npos) {
                    i++;
                    continue;
                }
                
                m[str[i]]--;
                i++;

            }
            int size = j - i + 1;
            if (min_size > size) {
                min_size = size;
                min_i = i;
                min_j = j;
            }
        }

    }

    for (int i = min_i; i <= min_j; i++) {
        cout << str[i];
    }
    cout << endl;

    return min_size;
}

int main(void)
{
    string s = "xxCxxxBxxBxxAxxBxxxxxBxxAxAxCxxxBx";
    string S = "ABC";

    cout << min_substr_size(s, S) << endl;
    
    return 0;
}
