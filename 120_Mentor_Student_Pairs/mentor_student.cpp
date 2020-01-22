#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> scores = {20, 30, 15, 10, 12, 5, 28, 30, 30, 2};
    int n = scores.size();

    vector<bool> is_mentor(n, false);

    sort(scores.begin(), scores.end());

    int student = 0;
    int mentor = 1;

    int count = 0;
    while (mentor < n) {
        while (mentor < n && 
              (scores[mentor] < 2 * scores[student] ||
               is_mentor[mentor])) {
            mentor++;
        }

        if (mentor < n) {
            is_mentor[mentor] = true;
            count++;
            mentor++;
        }

        student++;
    }

    cout << count << endl;
    
    return 0;
}
