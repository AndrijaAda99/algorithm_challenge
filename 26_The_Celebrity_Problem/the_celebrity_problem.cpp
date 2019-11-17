#include <iostream>
#include <vector>

#define MAX 4

using namespace std;

bool svi_poznaju(vector<vector<bool>>& poznanstva, int i)
{
    for (int j = 0; j < poznanstva.size(); j++) {
        if (i != j && poznanstva[j][i] == false) {
            return false;
        }
    }
    
    return true;
}

bool poznaje_nekoga(vector<vector<bool>>& poznanstva, int i)
{
    for (int j = 0; j < poznanstva.size(); j++) {
        if (poznanstva[i][j] == true) {
            return true;
        }
    }
    return false;
}

// Solution using plain graph definition, brute force O(n^2)
int superstar_graph(vector<vector<bool>>& poznanstva)
{
    for (int i = 0; i < poznanstva.size(); i++) {
        if (!poznaje_nekoga(poznanstva, i) && svi_poznaju(poznanstva, i)) {
            return i;
        }
    }

    return -1;
}


// Solution using recursion, but have the same complexity O(n^2)
int superstar_recursion(vector<vector<bool>>& poznanstva, int n)
{
    if (n == 0) {
        return -1;
    }

    int z = superstar_recursion(poznanstva, n - 1);
    if (z != -1 && !poznanstva[z][n - 1] && poznanstva[n - 1][z]) { 
        return z;
    }

    if (!poznaje_nekoga(poznanstva, n - 1) && 
        svi_poznaju(poznanstva, n - 1)) {
        return n - 1;
    }

    return -1;
}

int superstar_two_pointers(vector<vector<bool>> poznanstva) 
{
    int a = 0;
    int b = poznanstva.size() - 1;

    while (a < b) {
        if (poznanstva[a][b]) {
            a++;
        } else {
            b--;
        }
    }

    if (!poznaje_nekoga(poznanstva, a) && svi_poznaju(poznanstva, a)) {
        return a;
    }

    return -1;
}

int main(void)
{
    vector<vector<bool>> poznanstva = {{0, 0, 1, 0}, 
                                       {0, 0, 1, 0}, 
                                       {0, 0, 0, 0},
                                       {0, 0, 1, 0}};

    cout << superstar_graph(poznanstva) << endl;
    cout << superstar_recursion(poznanstva, poznanstva.size()) << endl;
    cout << superstar_two_pointers(poznanstva) << endl;
    
    return 0;
}
