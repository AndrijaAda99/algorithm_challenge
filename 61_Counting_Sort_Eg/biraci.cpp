#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct birac {
    string opstina;
    string sifra;
};

typedef struct birac Birac;
typedef vector<Birac> Biraci;

void sortiraj(Biraci& biraci)
{
    map<string, int> count_biraci;
    for (Birac birac : biraci) {
        count_biraci[birac.opstina]++;
    }

    map<string, int> pozicije;
    int trenutna_pozicija = 0;
    for (auto opstina : count_biraci) {
        pozicije[opstina.first] += trenutna_pozicija;
        trenutna_pozicija += opstina.second;
    }

    Biraci novi_biraci (biraci.size());
    for (Birac birac : biraci) {
        novi_biraci[pozicije[birac.opstina]] = birac;
        pozicije[birac.opstina]++;
    }

    biraci = novi_biraci;
}

int main(void)
{
    Biraci biraci = { {"a", "123"}, 
                      {"c", "231"},
                      {"b", "123"},
                      {"a", "231"},
                      {"a", "321"},
                      {"b", "321"},
                      {"b", "123"},
                      {"c", "321"}, 
                      {"a", "123"} }; 
    
    sortiraj(biraci);

    for (Birac birac : biraci) {
        cout << birac.opstina << " " << birac.sifra << endl;
    }
    
    return 0;
}
