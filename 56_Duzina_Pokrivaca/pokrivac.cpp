#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double, double> Interval;
typedef pair<double, bool> Tacka;
typedef vector<Interval> Intervali;
typedef vector<Tacka> Tacke;

Intervali ukrupni(Intervali& intervali)
{
    Tacke tacke;
    for (int i = 0; i < intervali.size(); i++) {
        tacke.push_back(make_pair(intervali[i].first, true));
        tacke.push_back(make_pair(intervali[i].second, false));
    }

    sort(tacke.begin(), tacke.end());

    Intervali novi_intervali;

    int br_intervala = 0;
    double interval_start = 0;
    bool je_poceo = false;

    int i = 0;
    while (i < tacke.size()) {
        int trenutna_tacka = tacke[i].first;
        while (i < tacke.size() && tacke[i].first == trenutna_tacka) {
            if (tacke[i++].second == true) {
                br_intervala++;
            } else {
                br_intervala--;
            }
        }

        if (!je_poceo && br_intervala > 0) {
            interval_start = trenutna_tacka;
            je_poceo = true;
        }

        if (je_poceo && br_intervala == 0) {
            Interval interval = make_pair(interval_start, trenutna_tacka);
            novi_intervali.push_back(interval);
            je_poceo = false;
        }
    }

    return novi_intervali;
}

int main(void)
{
    Intervali ulazni_intervali = {
        {2, 6}, {0, 4}, {8, 11}, {10, 12}, {3, 7}, {12, 15}
    };

    Intervali ukrupljeni_intervali = ukrupni(ulazni_intervali);

    for (Interval interval : ukrupljeni_intervali) {
        cout << interval.first << " " << interval.second << endl;
    }

    cout << ukrupljeni_intervali.size() << endl;

    return 0;
}
