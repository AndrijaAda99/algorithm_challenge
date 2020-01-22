#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Tacka;
typedef vector<Tacka> Tacke;

Tacka transliraj(const Tacka& t, int dx, int dy)
{
    return make_pair(t.first + dx, t.second + dy);
}

bool nadji_dva_temena(const Tacka& t1, const Tacka& t2, Tacka& t3, Tacka& t4)
{
    int x1 = t1.first;
    int y1 = t1.second;
    int x2 = t2.first;
    int y2 = t2.second;

    int dx = x2 - x1;
    int dy = y2 - y1;
    if ((dx + dy) % 2 != 0) {
        return false;
    }

    t3 = transliraj(t1, (dx - dy) / 2, (dy + dx) / 2);
    t4 = transliraj(t1, (dx + dy) / 2, (dy - dx) / 2);

    return true;
}

int broj_kvadrata(Tacke& tacke)
{
    sort(tacke.begin(), tacke.end());

    int broj_kvadrata = 0;
    for (int i = 0; i < tacke.size(); i++) {
        for (int j = i + 1; j < tacke.size(); j++) {
            Tacka t3, t4;
            if (nadji_dva_temena(tacke[i], tacke[j], t3, t4)) {
                if (binary_search(tacke.begin(), tacke.end(), t3) &&
                    binary_search(tacke.begin(), tacke.end(), t4)) {
                    broj_kvadrata++;
                }
            }
        }
    }

    return broj_kvadrata / 2;
}


int main(void)
{
    Tacke tacke = { {2, 3}, {4, 3}, {2, 5}, {4, 5}, 
                    {1, 8}, {3, 1}, {4, 4}, {1, 0}, 
                    {-1, 0}, {0, 0}, {0, 1}, {-1, 1}};

    cout << broj_kvadrata(tacke) << endl;
    
    return 0;
}
