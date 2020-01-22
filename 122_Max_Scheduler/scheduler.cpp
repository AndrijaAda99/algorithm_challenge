#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Interval;

int main(void)
{
    vector<Interval> intervals = {
        {4, 10},
        {3, 6},
        {0, 1},
        {8, 13},
        {0, 4},
        {2, 5},
        {6, 7},
        {5, 11}
    };

    sort(intervals.begin(), intervals.end(), 
            [] (Interval a, Interval b) { 
                return a.second < b.second;
            });

    int num_intervals = 1;
    Interval curr_interval = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first >= curr_interval.second) {
            curr_interval = intervals[i];
            num_intervals++;
        }
    }

    cout << num_intervals << endl;
    
    return 0;
}
