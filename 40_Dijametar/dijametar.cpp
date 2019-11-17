#include <iostream>
#include <algorithm>

using namespace std;

struct cvor {
    int vrednost;
    struct cvor* levo;
    struct cvor* desno;
};

int visina(struct cvor* koren)
{
    if (koren == nullptr) {
        return 0;
    }
    return max(visina(koren->levo), visina(koren->desno)) + 1;
}

int dijametar(struct cvor* koren)
{
    if (koren == nullptr) {
        return 0;
    }
    int dijametar_l = dijametar(koren->levo);
    int dijametar_d = dijametar(koren->desno);
    int dijametar_c = visina(koren->levo) + 2 + visina(koren->desno);
    return max({dijametar_l, dijametar_c, dijametar_d});
}

void visina_i_dijametar(cvor* koren, int& visina, int& dijametar)
{
    if (koren == nullptr) {
        visina = 0;
        dijametar = 0;
        return;
    }

    int visina_l, dijametar_l;
    visina_i_dijametar(koren->levo, visina_l, dijametar_l);
    int visina_d, dijametar_d;
    visina_i_dijametar(koren->desno, visina_d, dijametar_d);
    int dijametar_c = visina_l + 2 + visina_d;
    visina = max(visina_l, visina_d);
    dijametar = max({dijametar_l, dijametar_c, dijametar_d});
}

int main(void)
{
    
    return 0;
}
