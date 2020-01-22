#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct building {
    int a, b, h;
    building(int a = 0, int b = 0, int h = 0) : a(a), b(b), h(h) {}
};

struct change {
    int x, h;
    change (int x = 0, int h = 0) : x(x), h(h) {}
};

typedef struct building Building;
typedef vector<Building> Buildings;
typedef struct change Change;
typedef vector<Change> Skyline;

Skyline find_skyline(Buildings& buildings, int l, int r)
{
    Skyline skyline;

    if (l == r) {
        skyline.push_back(change(buildings[l].a, buildings[l].h));
        skyline.push_back(change(buildings[l].b, 0));
        return skyline;
    }

    int m = l + (r - l) / 2;

    Skyline skyline_l = find_skyline(buildings, l, m);
    Skyline skyline_r = find_skyline(buildings, m + 1, r);

    int index_l = 0;
    int index_r = 0;
    int height_l = 0;
    int height_r = 0;

    while (index_l < skyline_l.size() || index_r < skyline_r.size()) {
        int x;
        if (index_l == skyline_l.size()) {
            x = skyline_r[index_r].x;
            height_r = skyline_r[index_r].h;
            index_r++;
        } else if (index_r == skyline_r.size()) {
            x = skyline_l[index_l].x;
            height_l = skyline_l[index_l].h;
            index_l++;
        } else {
            if (skyline_l[index_l].x <= skyline_r[index_r].x) {
                x = skyline_l[index_l].x;
                height_l = skyline_l[index_l].h;
                index_l++;
            } else {
                x = skyline_r[index_r].x;
                height_r = skyline_r[index_r].h;
                index_r++;
            }
        }

        int h = max(height_l, height_r);

        if (skyline.size() > 0) {
            if (skyline.back().x == x) {
                skyline.back().h = h;
            } else if (skyline.back().h != h) {
                skyline.push_back(change(x, h));
            }
        } else {
            skyline.push_back(change(x, h));
        }
    }

    return skyline;
}

int main (void)
{
    Buildings buildings ={  
        {10, 18, 15},
        {22, 30, 18},
        {2, 7, 10},
        {17, 26, 25},
        {5, 12, 20}
    };

    Skyline skyline = find_skyline(buildings, 0, buildings.size() - 1);

    for (Change change : skyline) {
        cout << change.x << " " << change.h << endl;
    }

    return 0;
}
