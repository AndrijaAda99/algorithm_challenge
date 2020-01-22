#include <iostream>
#include <vector>

using namespace std;

const int V = 4;
const int K = 5;

vector<vector<int>> moves = {
    {1 ,  2}, {2 ,  1},
    {1 , -2}, {2 , -1},
    {-1,  2}, {-2,  1},
    {-1, -2}, {-2, -1}
};

void print_board(vector<vector<int>>& board)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < K; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tour(vector<vector<int>>& board, int v, int k, int move)
{
    board[v][k] = move;
    if (move == V * K) {
        print_board(board);
    }
    for (vector<int> m : moves) {
        int vn = v + m[0];
        int kn = k + m[1];
        if ((vn >= 0 && vn < V) &&
            (kn >= 0 && kn < K)) {
            if (board[vn][kn] == 0) {
                tour(board, vn, kn, move + 1);
            }
        }
    }
    board[v][k] = 0;
}

int main(void)
{
    vector<vector<int>> B(V);
    for (int i = 0; i < V; i++) {
        B[i].resize(K, 0);
    }

    tour(B, 0, 0, 1);
    
    return 0;
}
