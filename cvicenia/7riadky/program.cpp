#include <iostream>
#include <cassert>
using namespace std;

bool ** vytvorMaticu(int m, int n) {
    /* vytvor maticu s m riadkami a n stlpcami */
    bool **a;
    a = new bool *[m];
    for (int i = 0; i < m; i++) {
        a[i] = new bool[n];
    }
    return a;
}

void zmazMaticu(bool **a, int m) {
    /* uvolni pamat matice s m riadkami */
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void nacitajMaticu(bool **a, int m, int n) {
    /* matica je vytvorena, velkosti m krat n, vyplnime ju cislami zo vstupu */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;  // nacitaj znak, preskoc biele znaky, ak nejake su
            a[i][j] = (c == '1');
        }
    }
}

/** Funkcia otoci poradie riadkov matice tym, ze bude prehadzovat
 * smerniky na jednotlive riadky. V premennej m je pocet riadkov,
 * pocet stlpcov nie je vo funkcii potrebny. */
void otocRiadky(bool **a, int m) {
    /* TODO VAS KOD TU */
    bool *tmp;
    for(int i = 0; i < m/2; i++)
    {
        tmp = a[i];
        a[i] = a[m - i - 1];
        a[m - i - 1] = tmp;
    }
}

/** Funkcia vypise maticu na vystup */
void vypisMaticu(bool **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    /* nacitaj rozmery matice */
    int m, n;
    cin >> m >> n;

    /* vytvor a nacitaj maticu */
    bool **a = vytvorMaticu(m, n);
    nacitajMaticu(a, m, n);

    /* otoc poradie riadkov matice */
    otocRiadky(a, m);

    /* vypis maticu */
    vypisMaticu(a, m, n);

    /* uvolni pamat matice */
    zmazMaticu(a, m);
}
