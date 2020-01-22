#include <iostream>
#include <vector>

using namespace std;

vector<int> banknotes = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(void)
{
    int value;
    cin >> value;

    while (value > 0) {
        for (int banknote : banknotes) {
            if (banknote <= value) {
                cout << banknote << " ";
                value -= banknote;
                break;
            }
        }
    }

    return 0;
}
