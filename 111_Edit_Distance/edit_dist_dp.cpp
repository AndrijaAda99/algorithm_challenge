#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int mod_cost = 1;
static int del_cost = 1;
static int ins_cost = 1;

int edit_distance(string& s1, string& s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<int> dp(n2 + 1);

    for (int j = 0; j < n2 + 1; j++) {
        dp[j] = j * ins_cost;
    }

    for (int i = 1; i < n1 + 1; i++) {
        int prethodni = dp[0];
        dp[0] = i * del_cost;
        for (int j = 1; j < n2 + 1; j++) {
            int tekuci = dp[j];
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = prethodni; 
            } else {
                int case1_cost = prethodni + mod_cost;
                int case2_cost = tekuci + del_cost;
                int case3_cost = dp[j - 1] + ins_cost;

                dp[j] = min({case1_cost, case2_cost, case3_cost});
            }
            prethodni = tekuci;
        }
    }

    return dp[n2];
}

int main(void)
{
    string s1 = "zdravo";
    string s2 = "bravo!";
    
    cout << edit_distance(s1, s2) << endl;

    return 0;
}
