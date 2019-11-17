#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int zbir_prefiksa[n + 1];
    zbir_prefiksa[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        zbir_prefiksa[i] = zbir_prefiksa[i - 1] + x;
        
    }
    
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int zbir = zbir_prefiksa[j + 1] - zbir_prefiksa[i];
            if (max_sum < zbir) {
                max_sum = zbir;
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}
