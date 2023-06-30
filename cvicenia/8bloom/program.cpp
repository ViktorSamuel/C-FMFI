#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

/** struktura pre Bloomov filter */
struct table {
    int m;      // velkost hasovacej tabulky
    int k;      // pocet hasovacich funkcii
    int p;      // prvocislo p z hasovacej funkcie
    int *a;     // pole koeficientov hasovacich funkcii dlzky k
    bool *data; // hasovacia tabulka dlzky m
};

/** Funkcia nacita prvy riadok vstupu
 * a inicializuje prazdnu hasovaciu tabulku */
void init(table &tab) {
    // nacitame cisla m, k, p
    int ret;
    ret = scanf("hash %d %d %d ", &(tab.m), &(tab.k), &(tab.p));
    assert(ret == 3 && tab.m > 1 && tab.k >= 1 && tab.p > 1);

    // alokacia pola a, nacitanie jeho hodnot
    tab.a = new int[tab.k];
    for (int i = 0; i < tab.k; i++) {
        ret = scanf("%d ", &(tab.a[i]));
        assert(ret == 1 && tab.a[i] > 0);
    }

    // alokujeme hasovaciu tabulku a vyplnime hodnotou false
    tab.data = new bool[tab.m];
    for (int i = 0; i < tab.m; i++) {
        tab.data[i] = false;
    }
}

/** Funkcia vypise obsah hasovacej tabulky ako postupnost znakov T a F */
void print(table &tab) {
    for (int i = 0; i < tab.m; i++) {
        if (tab.data[i]) {
            printf("T");
        } else {
            printf("F");
        }
    }
    printf("\n");
}

/** Hasovacia funkcia, ktora dostane hodnotu x, ktoru treba zahasovat,
 * ako aj hodnoty a, p, m a spocita vysledny index. */
int hash(int x, int a, int p, int m) {
    return ((x * a) % p) % m;
}

/** Funkcia vlozi x do mnoziny algoritmom zo zadania */
void add(table &tab, int x) {
    // TODO: naprogramuje funkciu, vyuzite v nej funkciu hash
    for(int i = 0; i < tab.k; i++)
    {
        int o = hash(x, tab.a[i], tab.p, tab.m);
        tab.data[o] = true;
    }
}

/** Funkcia zisti, ci sa x nachadza v mnozine algoritmom zo
 * zadania. Algoritmus niekedy vrati true aj ked spravna odpoved je
 * false. */
bool contains(table &tab, int x) {
    // TODO: naprogramuje funkciu, vyuzite v nej funkciu hash
    int n = 0;
    for(int i = 0; i < tab.k; i++)
    {
        int o = hash(x, tab.a[i], tab.p, tab.m);
        if(tab.data[o] == true) n++;
    }
    if(n == tab.k) return true;
    else return false;
}

int main(void) {

    // nacitanie prveho riadku vstupu a inicializacia prazdnej tabulky
    table tab;
    init(tab);

    // cyklus na spracovanie prikazov
    while (true) {
        // nacitanie prikazu
        char command[101];
        int ret = scanf("%s", command);
        assert(ret == 1);
        if (strcmp(command, "add") == 0) {
            // spracovanie prikazu add
            int x;
            ret = scanf("%d", &x);
            assert(ret == 1 && x > 0);
            printf("add %d\n", x);
            add(tab, x);
        } else if (strcmp(command, "contains") == 0) {
            // spracovanie prikazu contains
            int x;
            ret = scanf("%d", &x);
            assert(ret == 1 && x > 0);
            printf("contains %d: ", x);
            bool result = contains(tab, x);
            if (result) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strcmp(command, "print") == 0) {
            // spracovanie prikazu print
            printf("print: ");
            print(tab);
        } else if (strcmp(command, "end") == 0) {
            // spracovanie prikazu end - koniec cyklu
            printf("end\n");
            break;
        } else {
            // nespravny prikaz
            assert(false);
        }
    }

    // uvolnenie pamate
    delete[] tab.a;
    delete[] tab.data;
}
