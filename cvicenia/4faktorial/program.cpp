#include <iostream>
#include <cassert>
using namespace std;

/** Maximalny pocet cifier v cisle. */
const int MAXN = 3000;

/** Reprezentacia velkeho cisla s najviac MAXN ciframi */
struct cislo {
    /** pocet cifier cisla */
    int pocet_cifier;
    /** Pole cifier, najmenej vyznamna cifra je na indexe 0. */
    int cifry[MAXN];
};

/** Funkcia do premennej a vytvori reprezentaciu
 * kladneho celeho cisla z premennej x */
void vytvorCislo(cislo &a, int x) {
    assert(x > 0);
    a.pocet_cifier = 0;
    while (x > 0) {
        a.cifry[a.pocet_cifier] = x % 10;
        x = x / 10;
        a.pocet_cifier++;
    }
}

/* Tato funkcia nacita cislo a ulozi ho do structu cislo.
 * Vyuziva typ char, ktory sme este nebrali, ale nemusite jej rozumiet. */
void nacitaj_cislo(cislo &a) {
    a.pocet_cifier = 0;
    char c;
    cin >> noskipws >> c;
    while (c >= '0' && c <= '9') {
        a.cifry[a.pocet_cifier] = c - '0';
        a.pocet_cifier++;
        assert(a.pocet_cifier <= MAXN);
        cin >> noskipws >> c;
    }
    assert(c == '\n');
    for (int i = 0; i < a.pocet_cifier - i - 1; i++) {
        swap(a.cifry[i], a.cifry[a.pocet_cifier - i - 1]);
    }
    cin >> skipws;
}



/* Tato funkcia vypise velke cislo a na vystup a ukonci riadok */
void vypis(cislo &a) {
    /* TODO: Naprogramujte tuto funkciu */
    for(int i = a.pocet_cifier - 1; i >= 0 ; i--){
        cout << a.cifry[i];
    }
    cout << endl;
}


/* Tato funkcia prenasobi velke cislo a cislom x.
 * Vysledok zapise priamo do premennej a */
void nasob(cislo &a, int x) {
    /* TODO: Naprogramujte tuto funkciu. Nezabudnite zmenit 
     * aj polozku a.pocet_cifier */

    int z = 0;

    for(int i = 0; i < a.pocet_cifier; i++)
    {
        int temp = ((a.cifry[i] * x) + z);
        a.cifry[i] = temp % 10;
        z = temp / 10;
    }

     for(int i = a.pocet_cifier; z >= 1; i++)
    {
        a.cifry[i] = z % 10;
        a.pocet_cifier++;
        z /= 10;
    }
}

/* Tato funkcia do premennej a spocita n! */
void faktorial(cislo &a, int n) {
    /* TODO: Naprogramujte tuto funkciu.
       Odporucame pouzit funkcie vytvorCislo a nasob. */
    vytvorCislo(a, n);

    for(int i = n - 1; i > 0; i--)
    {
        nasob(a, i);
    }

    // a.pocet_cifier=0; // zmazte alebo zmente podla potreby
}


/* Funkcia main je hotova, nemente ju */
int main() {
    /* Nacitame velke cislo a dve male cisla. */
    cislo a;
    nacitaj_cislo(a);
    int b;
    cin >> b;
    int n;
    cin >> n;

    cout << "a: ";
    vypis(a);
    cout << "  pocet cifier: " << a.pocet_cifier << endl;

    cout << "a*" << b << ": ";
    nasob(a, b);
    vypis(a);
    cout << "  pocet cifier: " << a.pocet_cifier << endl;


    cislo f;
    cout << n << "!: ";
    faktorial(f, n);
    vypis(f);
    cout << "  pocet cifier: " << f.pocet_cifier << endl;
}
