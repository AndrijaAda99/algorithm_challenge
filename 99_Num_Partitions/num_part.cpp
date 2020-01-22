#include <iostream>
#include <vector>

using namespace std;

int num_partitions(int n, int s)
{
    if (n == 0) {
        return 1;
    }
    if (s == 0) {
        return 0;
    }

    int num_part = num_partitions(n, s - 1);
    if (n >= s) {
        num_part += num_partitions(n - s, s);
    }

    return num_part;
}

int main(void)
{
    int n = 4;
    cout << num_partitions(n, n) << endl;
    
    return 0;
}
