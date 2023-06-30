#include <iostream>
using namespace std;

void vypis(int a[], int k) {
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

void generuj(int a[], int i, int k, int n) {
    /* v poli a dlzky k mame prvych i cifier,
     * chceme vygenerovat vsetky moznosti
     * poslednych k-i cifier */
    if (i == k) {
        vypis(a, k);
    } else {
        for (int x = 0; x < n; x++) {
            if(i != 0)
            {
                if(a[i - 1] != x) a[i] = x;
                else continue;
            }
            else a[i] = x;
            generuj(a, i + 1, k, n);
        }
    }
}

int main() {
    const int maxK = 100;
    int a[maxK];
    int n, k;
    cin >> n >> k;
    generuj(a, 0, k, n);
}
