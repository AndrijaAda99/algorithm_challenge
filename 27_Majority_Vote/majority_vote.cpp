#include <iostream>

using namespace std;

int majority_element(int votes[], int n)
{
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = votes[i];
            count = 1;
        } else if (candidate == votes[i]) {
            count++;
        } else {
            count--;
        }
    }

    if (count == 0) {
        return -1;
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (votes[i] == candidate) {
            count++;
        }
    }
    if (count * 2 > n) {
        return candidate;
    }

    return -1;
}

int main(void)
{
    int votes[] = {5, 3, 3, 5, 5, 1, 5, 1};

    cout << majority_element(votes, sizeof (votes) / sizeof (int));
    
    return 0;
}
