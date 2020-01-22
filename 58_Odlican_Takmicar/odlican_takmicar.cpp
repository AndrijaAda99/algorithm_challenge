#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct takmicar {
    int mat;
    int prog;
};

typedef struct takmicar Takmicar;
typedef vector<Takmicar> Takmicari;

void odlicni(Takmicari& takmicari)
{
    sort(takmicari.begin(), takmicari.end(),
            [] (Takmicar a, Takmicar b) {
                return a.mat > b.mat || 
                        (a.mat == b.mat && a.prog > b.prog);
            });

    int max_prog = 0;
    for (int i = 0; i < takmicari.size() - 1; i++) {
        if (max_prog <= takmicari[i].prog) {
            cout << takmicari[i].mat << " " << takmicari[i].prog << endl;
            max_prog = takmicari[i].prog;
        }
    }
}

int main(void)
{
    Takmicari takmicari = {{10, 35}, {10, 25}, {15, 20}, {10, 20}, {35, 25}};

    odlicni(takmicari);
    
    return 0;
}
