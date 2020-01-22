#include <iostream>
#include <vector>

using namespace std;

int num_jumps(vector<int>& stones, int d)
{
    int n = stones.size();

    int jumps = 0;
    int stone = 0;

    while (stone < n - 1) {
        int new_stone = stone;
        while (new_stone + 1 < n && 
               stones[new_stone + 1] - stones[stone] <= d) {
            new_stone++;
        }

        if (new_stone == stone) {
            return n;
        }

        jumps++;
        stone = new_stone;
    }

    return jumps;
}

int main(void)
{

    vector<int> stones = {3, 5, 9, 11, 15, 20, 21};
    
    cout << num_jumps(stones, 5) << endl;
    
    return 0;
}
