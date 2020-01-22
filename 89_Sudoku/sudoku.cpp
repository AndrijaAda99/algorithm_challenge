#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_board(vector<vector<int>>& board)
{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool conflict(vector<vector<int>>& board, int i, int j)
{
    int n = sqrt(board.size());
    for (int k = 0; k < n * n; k++) {
        if (k != j && board[i][k] == board[i][j]) {
            return true;
        }
    }

    for (int k = 0; k < n * n; k++) {
        if (k != i && board[k][j] == board[i][j]) {
            return true;
        }
    }

    int x = i / n;
    int y = j / n;
    for (int k = x * n; k < (x + 1) * n; k++) {
        for (int l = y * n; l < (y + 1) * n; l++) {
            if (k == i && l == j) {
                continue;
            }
            if (board[k][l] == board[i][j]) {
                return true;
            }
        }
    }

    return false;
}

bool sudoku(vector<vector<int>>& board, int i, int j)
{
    int n = sqrt(board.size());

    if (board[i][j] != 0) {
        if (i == n * n - 1 && j == n * n - 1) {
            return true;
        }

        j++;
        if (j == n * n) {
            j = 0;
            i++;
        }

        return sudoku(board, i, j);
    } else {
        for (int k = 1; k <= n * n; k++) {
            board[i][j] = k;
            if (!conflict(board, i, j)) {
                if (sudoku(board, i, j)) {
                    return true;
                }
            }
        }
        board[i][j] = 0;
        return false;
    }
}

int main(void)
{
    vector<vector<int>> board = {
        {5, 0, 0, 0, 0, 3, 1, 0, 4},
        {8, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 6, 0, 0, 0, 9, 0},
        {2, 1, 0, 7, 0, 9, 8, 0, 6},
        {6, 3, 0, 0, 2, 0, 0, 1, 9},
        {7, 0, 9, 8, 0, 6, 0, 4, 2},
        {0, 7, 0, 0, 0, 2, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 0, 8},
        {1, 0, 5, 9, 0, 0, 0, 0, 3},
    };

    
    print_board(board);
    if (sudoku(board, 0, 0)) {
        print_board(board);
    }

    return 0;
}
