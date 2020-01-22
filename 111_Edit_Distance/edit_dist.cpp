#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(string& s1, int n1, string& s2, int n2)
{
    if (n1 == 0) {
        return n2 * 1;
    }
    if (n2 == 0) {
        return n1 * 1;
    }

    if (s1[n1 - 1] == s2[n2 - 1]) {
        return edit_distance(s1, n1 - 1, s2, n2 - 1);
    }

    int case1_cost = edit_distance(s1, n1 - 1, s2, n2 - 1) + 1;
    int case2_cost = edit_distance(s1, n1 - 1, s2, n2) + 1;
    int case3_cost = edit_distance(s1, n1, s2, n2 - 1) + 1;

    return min({case1_cost, case2_cost, case3_cost});
}

int main(void)
{
    string s1 = "sunday";
    string s2 = "saturday";
    
    cout << edit_distance(s1, s1.size(), s2, s2.size()) << endl;

    return 0;
}
