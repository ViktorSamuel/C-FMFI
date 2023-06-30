#include <iostream>
using namespace std;

// struktura pre ulozenie najmensej a najvacsej moznej cifry
struct interval {
    int min, max;
};

void vypis(int a[], int k) {
    /* funkcia vypise prvych k cifier z pola a */
    for (int i = 0; i < k; i++) {
        cout << a[i];
    }
    cout << endl;
}

// TODO: zmente funkciu podla potreby, vratane hlavicky
void generuj(int a[], int i, int k, interval limit[]) {
    /* v poli a dlzky k mame prvych i cifier,
     * chceme vygenerovat vsetky moznosti
     * poslednych k-i cifier z mnoziny 0..n-1 */
    if (i == k) {
        vypis(a, k);
    } else {
        for (int x = limit[i].min; x <= limit[i].max; x++) {
            a[i] = x;
            generuj(a, i + 1, k, limit);
        }
    }
} 

int main() {
    // maximalny pocet cifier
    const int maxN = 100;
    // nacitanie k
    int k;
    cin >> k;

    // nacitanie obmedzeni pre cifry
    interval obmedzenia[maxN];
    for (int i = 0; i < k; i++) {
        cin >> obmedzenia[i].min;
        cin >> obmedzenia[i].max;
    }

    // vytvorenie pola pre vysledok
    int a[maxN];

    // zavolanie rekurzivneho generovania variacii
    // TODO: zmente podla potreby
    generuj(a, 0, k, obmedzenia);
}
