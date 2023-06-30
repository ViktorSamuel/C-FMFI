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

    bool **b = vytvorMaticu(m, n);
    nacitajMaticu(b, m, n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!(a[i][j] == true && b[i][j] == true))
            {
                a[i][j] = false;
            }
        }
    }

    /* vypis maticu */
    vypisMaticu(a, m, n);

    /* uvolni pamat matice */
    zmazMaticu(a, m);
    zmazMaticu(b, m);
}
