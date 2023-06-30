#include <iostream>
#include <cassert>
using namespace std;

int ** vytvorMaticu(int m, int n) {
    /* Vytvori a vrati maticu (obdlznikovu tabulku)
     * s m riadkami a n stlpcami. */
    int **a;
    a = new int *[m];
    for (int i = 0; i < m; i++) {
	a[i] = new int[n];
    }
    return a;
}

void zmazMaticu(int **a, int m) {
    /* Uvolni z pamate maticu s m riadkami. */
    for (int i = 0; i < m; i++) {
	delete[] a[i];
    }
    delete[] a;
}

void nacitajMaticu(int **a, int m, int n) {
    /* Nacita hodnoty do uz vytvorenej matice 
     * velkosti m krat n. */
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
	    cin >> a[i][j];
	}
    }
}

int pocetNul(int **a, int r1, int s1, int r2, int s2) {
    /* Funkcia dostane dvojrozmernu tabulku implementovanu pomocou
     * pola smernikov, ako aj suradnice laveho horneho a praveho
     * dolneho rohu obdlznika v tejto tabulke. Vrati pocet nulovych
     * hodnot v tomto obdlzniku tabulky. */

    /* TODO VAS KOD TU */
    int n = 0;
    for(int i = r1; i <= r2; i++)
    {
        for(int j = s1; j <= s2; j++)
        {
            if(a[i][j] == 0) 
            {
                n++;
            }
        }
    }
    return n;
}

int main(void) {
    /* nacitaj rozmery matice */
    int m, n;
    cin >> m >> n;

    /* vytvor a nacitaj maticu */
    int **a = vytvorMaticu(m, n);
    nacitajMaticu(a, m, n);

    /* nacitavaj a spracuj obdlzniky */
    while (true) {
        int r1, s1, r2, s2;
        cin >> r1 >> s1 >> r2 >> s2;
        if (r1 == -1) break;
        assert(0 <= r1 && r1 <= r2 && r2 < m);
        assert(0 <= s1 && s1 <= s2 && s2 < n);

        cout << pocetNul(a, r1, s1, r2, s2) << endl;
    }

    /* uvolni pamat matice */
    zmazMaticu(a, m);
}
