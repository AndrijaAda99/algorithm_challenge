#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> Maze;
typedef pair<int, int> Point;
typedef vector<Point> Moves;

const Moves moves = 
{
    {1 , 0}, {0,  1},
    {-1, 0}, {0, -1}
};

void print_maze(Maze& walls, Maze& path, Point start)
{
    usleep(200000);
    for (int i = 0; i < walls.size(); i++) {
        for (int j = 0; j < walls[i].size(); j++) {
            if (start.first == i && start.second == j) {
                cout << "+ ";
            } else if (walls[i][j]) {
                cout << "x ";
            } else if (path[i][j]) {
                cout << ". ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << endl;
    }
}

bool valid(Maze& walls, Maze& path, Point move)
{
    if (walls[move.first][move.second] || path[move.first][move.second]) {
        return false;
    }
    return true;
}

bool find_path(Maze& walls, Maze& path, Point start, Point end)
{
    if (start.first == end.first && start.second == end.second) {
        return true;
    }

    for (Point move : moves) {
        Point new_move = make_pair(start.first + move.first, 
                                   start.second + move.second);
        if (valid(walls, path, new_move)) {
            path[new_move.first][new_move.second] = true;
            print_maze(walls, path, new_move);
            if(find_path(walls, path, new_move, end)) {
                return true;
            }
            path[new_move.first][new_move.second] = false;
            print_maze(walls, path, new_move);
        }
    }
    return false;
}

void find_path(Maze& walls)
{
    int n = walls.size();
    int m = walls[0].size();

    Maze path(n);
    for (int i = 0; i < n; i++) {
        path[i].resize(m, 0);
    }

    Point start = make_pair(1, 1);
    Point end = make_pair(n - 2, m - 2);

    path[start.first][start.second] = true;

    print_maze(walls, path, start);
    if(find_path(walls, path, start, end)) {
        print_maze(walls, path, end);
    }
}

int main(void)
{

    Maze maze = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    find_path(maze);
    
    return 0;
}
