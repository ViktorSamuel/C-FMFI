#include <iostream>
#include <cassert>
using namespace std;

void printArray(int a[], int n, int oddelovac) {
    /* Vypise pole a dlzky n, pricom pred cislo na pozicii oddelovac
     * vypise zvislu ciaru. Ak oddelovac je zaporny, ciaru
     * nevypise. Ak je oddelovac rovny n, vypise ho za koniec pola. */
    for (int i = 0; i < n; i++) {
        if (i == oddelovac) {
            cout << " |";
        }
        cout << " ";
        cout << a[i];
    }
    if (oddelovac == n) {
        cout << " |";
    }
    cout << endl;
}


void swap(int &x, int &y) {
    /* Vymeni hodnoty premennych x a y. */
    int tmp = x;
    x = y;
    y = tmp;
}


int maxIndex(int a[], int s, int n) {
    /* v poli najde poziciu najvacsieho cisla medzi cislami na
     * na poziciach a[0],a[1],...,a[n-1] */

    int index = s;
    // for(int i=1; i<n; i++) {
    //     if(a[i]>a[index]) {
    //         index = i;
    //     }
    // }
    for(int i = s; i < n; i++)
    {
        if(a[i]<a[index]) {
            index = i;
        }
    }
    return index;
}

void sort(int a[], int n) {
    /* usporiada prvky v poli a od najmensieho po najväcsi */

    // for(int kam = n - 1; kam >= 1; kam--) {
    //     printArray(a, n, kam+1);
    //     int index = maxIndex(a, kam + 1);
    //     swap(a[index], a[kam]);
    // }

    for(int i = 0; i < n - 1; i++){
        printArray(a, n, i);
        int index = maxIndex(a, i, n);
        swap(a[i], a[index]);
    }
}


int main() {
    // maximalny pocet cisel v poli
    const int MAXN = 100;

    // nacitame vstup
    int n;
    cin >> n;
    int a[MAXN];
    assert(n <= MAXN);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // triedenie a vypis
    sort(a, n);
    cout << "Vysledok:" << endl;
    printArray(a, n, -1);
}

