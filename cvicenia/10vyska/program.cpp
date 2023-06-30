#include <cstdio>
#include <cassert>
#include <cmath>

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
            int ret = scanf("%d", &(a[i][j]));
            assert(ret == 1 && a[i][j] >= 0);
        }
    }
}


/* TODO: zmente nasledujucu funkciu z prednasky podla potreby.
 * Mozete zmenit aj hlavicku. */
/* Prefarbi suvislu jednofarebnu oblast obsahujucu poziciu
 * (riadok,stlpec) na farbu s cislom farba. */
void vyfarbi(int **a, int m, int n, int riadok, int stlpec, int farba) {
    int staraFarba = a[riadok][stlpec];
    if (staraFarba == farba) {
        return;
    }
    a[riadok][stlpec] = farba;
    if (riadok - 1 >= 0 && abs(a[riadok - 1][stlpec]-staraFarba) <= 1) {
        vyfarbi(a, m, n, riadok - 1, stlpec, farba);
    }
    if (riadok + 1 <= m - 1 && abs(a[riadok + 1][stlpec]-staraFarba) <= 1) {
        vyfarbi(a, m, n, riadok + 1, stlpec, farba);
    }
    if (stlpec - 1 >= 0 && abs(a[riadok][stlpec - 1]-staraFarba) <= 1) {
        vyfarbi(a, m, n, riadok, stlpec - 1, farba);
    }
    if (stlpec + 1 <= n - 1 && abs(a[riadok][stlpec + 1]-staraFarba) <= 1) {
        vyfarbi(a, m, n, riadok, stlpec + 1, farba);
    }
}


int main(void) {
    /* nacitaj rozmery matice */
    int m, n;
    scanf("%d %d", &m, &n);

    /* vytvor a nacitaj maticu */
    int **a = vytvorMaticu(m, n);
    nacitajMaticu(a, m, n);

    /* TODO:  volanie vasej funkcie, zmente podla potreby */
    vyfarbi(a, m, n, 0, 0, -1);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %3d", a[i][j]);
        }
        printf("\n");
    }

    /* uvolni pamat matice */
    zmazMaticu(a, m);
}
