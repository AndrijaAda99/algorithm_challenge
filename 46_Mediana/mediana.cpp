#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> levi;
priority_queue<int, vector<int>, less<int>> desni;

double mediana() {
    if (levi.size() == desni.size()) {
        return (levi.top() + desni.top()) / 2.0;
    }
    return desni.top();
}

void dodaj(int n)
{
    if (desni.empty()) {
        desni.push(n);
    } else {
        if (n <= desni.top()) {
            levi.push(n);
        } else {
            desni.push(n);
        }
        if (levi.size() > desni.size()) {
            desni.push(levi.top());
            levi.pop();
        } else if (desni.size() > levi.size() + 1) {
            levi.push(desni.top());
            desni.pop();
        }
    }  
}

int main(void)
{
    vector<int> a = {2, 3, 1, 5, 4};

    for (int i = 0; i < a.size(); i++) {
        dodaj(a[i]);
        cout << a[i] << ": " << mediana() << endl;
    }

    
    return 0;
}
