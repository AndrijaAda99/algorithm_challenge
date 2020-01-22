#include <iostream>
#include <vector>
#include <array>

using namespace std;

enum {
    IME = 0, 
    PREZIME = 1
};

typedef array<string, 2> Ucenik;
typedef vector<Ucenik> Ucenici;

void razvrstaj(Ucenici& ucenici, int ip)
{
    vector<int> count (26, 0);
    for (Ucenik ucenik : ucenici) {
        count[ucenik[ip][0] - 'A']++;
    }
    
    vector<int> position (26, 0);
    position[0] = 0;
    for (int i = 1; i < count.size(); i++) {
        position[i] = position[i - 1] + count[i - 1];
    }

    Ucenici novi_ucenici (ucenici.size());
    for (Ucenik ucenik : ucenici) {
        novi_ucenici[position[ucenik[ip][0] - 'A']] = ucenik;
        position[ucenik[ip][0] - 'A']++;
    }
        
    ucenici = novi_ucenici;
}

void sortiraj(Ucenici& ucenici)
{
    razvrstaj(ucenici, PREZIME);
    razvrstaj(ucenici, IME);
}

int main(void)
{
    Ucenici ucenici = { {"Ana", "Markovic"}, 
                        {"Lazar", "Markovic"}, 
                        {"Ilija", "Bajkovic"},
                        {"Cile", "Petrovic"},
                        {"Aljosa", "Mulutinovic"},
                        {"Luna", "Beckovic"},
                        {"Andrej", "Jovanovic"},
                        {"Jovana", "Vojovic"},
                        {"Katarina", "Pavlovic"}};

    sortiraj(ucenici);

    for (Ucenik ucenik : ucenici) {
        cout << ucenik[0] << " " << ucenik[1] << endl;
    }
    
    return 0;
}


