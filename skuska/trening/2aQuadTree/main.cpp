#include <cstdio>
#include <cassert>
#include <cstring>

/** štruktúra pre vrchol stromu quadtree */
struct vrchol {
    bool jeList;    // je tento vrchol list?
    char farba;     // znak pre farbu v liste
    int riadok, stlpec; // súradnice ľavého horného rohu štvorca
    int velkost;  // počet riadkov resp. stĺpcov štvorca
    vrchol *deti[4];  // smerníky na vrcholy detí, alebo NULL
};

/** Položka deltaRiadok[i] určuje, či pre vnútorný vrchol v je
 * v->dieta[i] na tom istom riadku (hodnota 0) alebo nižšie (hodnota
 * 1) ako samotný vrchol v. */
const int deltaRiadok[4] = {0, 0, 1, 1};
/** Pole deltaStlpec funguje podobne ako deltaRiadok, iba pre stĺpce */
const int deltaStlpec[4] = {0, 1, 0, 1};


/** Funkcia zistí, či políčko s danými súradnicami stĺpca a riadku je
 * vo vnútri štvorca reprezentovaného vrcholom v. */
bool jeVnutri(vrchol *v, int riadok, int stlpec) {
    return riadok >= v->riadok && stlpec >= v->stlpec
           && riadok < v->riadok + v->velkost
           && stlpec < v->stlpec + v->velkost;
}

/** Funkcia vráti farbu pre políčko s danými súradnicami stĺpca a
 * riadku v strome s koreňom vo vrchole v. Môžete použiť už hotovú
 * funkciu jeVnutri. */
char najdiFarbu(vrchol *v, int riadok, int stlpec) {
    // TODO VÁŠ KÓD TU
    if(v->farba) return v->farba;
    for(int i = 0; i < 4; i++)
    {
        if(jeVnutri(v->deti[i], riadok, stlpec))
        {
            return najdiFarbu(v->deti[i], riadok, stlpec);
        }
    }
}

/** Funkcia dostane vrchol v, pre ktorý sú už všetky jeho deti
 * zjednodušené a zistí, či je možné vrchol v nahradiť listom, t.j. či
 * všetky jeho deti sú listy, ktoré zodpovedajú tej istej farbe.
 * Ak je v listom, funkcia vráti false. */
bool daSaZjednodusit(vrchol *v) {
    if (v->jeList) {
        return false;
    }

    // sú všetky deti listami?
    for (int i = 0; i < 4; i++) {
        if (!v->deti[i]->jeList) {
            return false;
        }
    }

    // majú všetky deti rovnakú farbo ako prvé dieťa?
    char farba = v->deti[0]->farba;
    for (int i = 1; i < 4; i++) {
        if (farba != v->deti[i]->farba) {
            return false;
        }
    }
    return true;
}

/** Funkcia uvoľní všetku pamäť alokovanú dynamicky pre strom s koreňom v */
void uvolni(vrchol *v) {
    if (!v->jeList) {
        for (int i = 0; i < 4; i++) {
            uvolni(v->deti[i]);
        }
    }
    delete v;
}

/** Funkcia dostane koreň stromu v a zjednoduší tento strom, t.j, z
 * každého vrcholu, ktorý zodpovedá jednofarebnej ploche, spraví
 * list. Ak už sú všetky deti vrchola v zjednodušené, môžete použiť
 * funkciu daSaZjednodusit, ktorá overí, či sa zadaný vrchol dá
 * nahradiť listom. Vrcholy odstránené zo stromu odalokujte. */
void zjednodus(vrchol *v) {
    // TODO VÁŠ KÓD TU
    for(int i = 0; i < 4; i++)
    {
        if(v->deti[i] != NULL && !v->deti[i]->jeList) zjednodus(v->deti[i]);
    }
    if(daSaZjednodusit(v))
    {
        v->farba = v->deti[0]->farba;
        v->jeList = true;
        for(int i = 0; i < 4; i++)
        {
            uvolni(v->deti[i]);
            v->deti[i] = NULL;
        }
    }
}

/** Funkcia, ktorá vymení dva smerníky na vrchol */
void swap(vrchol *&a, vrchol *&b) {
    vrchol *tmp = a;
    a = b;
    b = tmp;
}

/** Funkcia, ktorá strom s koreňom v prerobí tak, aby zdpovedal
 * obrázku s opačným poradím riadkov. Vo funkcii nealokujte ani
 * nerušte žiadne vrcholy, len meňte poradie detí v poliach detí v
 * jednotlivých vrcholoch. Položku riadok vo vrcholoch
 * nemusíte meniť, vyrieši sa to neskôr vo funkcii main. */
void prevrat(vrchol *v) {
    // TODO VÁŠ KÓD TU
    for(int i = 0; i < 4; i++)
    {
        if(v->deti[i] != NULL && !v->deti[i]->jeList) prevrat(v->deti[i]);
    }
    swap(v->deti[0], v->deti[2]);
    swap(v->deti[1], v->deti[3]);
}

/** Funkcia vráti počet listov v podstrome s koreňom v. */
int pocetListov(vrchol *v) {
    if (v->jeList) {
        return 1;
    } else {
        int pocet = 0;
        for (int i = 0; i < 4; i++) {
            pocet += pocetListov(v->deti[i]);
        }
        return pocet;
    }
}

/** Funkcia vypíše obrázok reprezentovaný stromom s daným koreňom. Pre
 * každý pixel obrázku zavolá funkciu najdiFarbu a vypíše príslušný
 * znak (aj keď strom by sa dal vypisovať aj efektívnejšie). Na záver
 * vypíše počet listov v strome. */
void vypis(vrchol *koren) {
    // postupne vypisujeme jednotlivé riadky obrázku
    for (int riadok = 0; riadok < koren->velkost; riadok++) {
        for (int stlpec = 0; stlpec < koren->velkost; stlpec++) {
            char farba = najdiFarbu(koren, riadok, stlpec);
            printf("%c", farba);
        }
        printf("\n");
    }
    printf("Pocet listov %d\n\n", pocetListov(koren));
}

/** Funkcia dostane vstupný obrázok v matici znakov a vytvorí a vráti
 * strom, ktorý ho reprezentuje. Každý list bdue reprezentovať jeden
 * pixel. Parametre riadok, stlpec a velkost určujú štvorec, ktorý
 * práve uvažujeme. */
vrchol * vybudujPodstrom(char **a, int riadok, int stlpec, int velkost) {
    bool jeList = velkost == 1;

    // uložíme základné údaje o vrchole
    vrchol *v = new vrchol;
    v->riadok = riadok;
    v->stlpec = stlpec;
    v->velkost = velkost;
    v->jeList = jeList;
    if (jeList) {
        // dokončíme položky listu
        v->farba = a[riadok][stlpec];
        for (int i = 0; i < 4; i++) {
            v->deti[i] = NULL;
        }
    } else {
        // rekurzívne dokončíme vnútorný vrchol
        assert(velkost % 2 == 0);
        int novaVelkost = velkost / 2;
        v->farba = 0;
        v->deti[0] = vybudujPodstrom(a, riadok, stlpec, novaVelkost);
        v->deti[1] = vybudujPodstrom(a, riadok, stlpec + novaVelkost,
                                     novaVelkost);
        v->deti[2] = vybudujPodstrom(a, riadok + novaVelkost, stlpec,
                                     novaVelkost);
        v->deti[3] = vybudujPodstrom(a, riadok + novaVelkost,
                                     stlpec + novaVelkost, novaVelkost);
    }
    return v;
}

/** Funkcia načíta obrázok z konzoly a uloží ho do stromu */
vrchol *nacitaj() {
    // načítame znaky do matice a
    int n;
    scanf("%d ", &n);
    char **a = new char*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new char[n + 2];
        fgets(a[i], n + 2, stdin);
        assert((int)strlen(a[i]) == n + 1 && a[i][n] == '\n');
    }

    // zavoláme rekurzívne tvorenie stromu
    vrchol *koren = vybudujPodstrom(a, 0, 0, n);

    // uvoľníme maticu a
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return koren;
}

/** Funkcia dostane koreň stromu v, súradncie ľavého horného rohu jeho
 * štvorca a veľkosť štvorca a všetkým vrcholom v jeho podstrome
 * správne nastaví položky velkost, riadok a stlpec. */
void suradnice(vrchol *v, int riadok, int stlpec, int velkost) {
    v->velkost = velkost;
    v->riadok = riadok;
    v->stlpec = stlpec;
    if (!v->jeList) {
        assert(velkost % 2 == 0);
        int pol = velkost / 2;
        for (int i = 0; i < 4; i++) {
            suradnice(v->deti[i],
                      riadok + pol * deltaRiadok[i],
                      stlpec + pol * deltaStlpec[i], pol);
        }
    }
}

/** Funkcia dostane koreň stromu v a skontroluje, či sú všetky položky
 * všetkých vrcholov v strome konzistentne nastavené. */
void kontrola(vrchol *v) {
    assert(v != NULL);
    // velkost ma byt aspon 1 a suradnice nezaporne
    assert(v->velkost >= 1 && v->riadok >= 0 && v->stlpec >= 0);
    if (v->jeList) {
        // v liste je farba aj deti nenulove
        assert(v->farba != 0);
        for (int i = 0; i < 4; i++) {
            assert(v->deti[i] == NULL);
        }
    } else {
        // vo vnutornom vrchole je farba 0, velkost delitelna 2,
        // deti su nenulove a ich velkost a poloha sedi s velkostou a polohou rodica
        assert(v->farba == 0);
        assert(v->velkost % 2 == 0);
        int pol = v->velkost / 2;
        for (int i = 0; i < 4; i++) {
            assert(v->deti[i] != NULL);
            assert(v->deti[i]->velkost == pol);
            assert(v->deti[i]->riadok == v->riadok + pol * deltaRiadok[i]);
            assert(v->deti[i]->stlpec == v->stlpec + pol * deltaStlpec[i]);
        }
    }
}

int main(void) {

    // načítame stromu z konzoly
    vrchol *koren = nacitaj();
    // uložíme si veľkosť obrázku
    int velkost = koren->velkost;

    // kontrola a výpis vstupného stromu
    printf("Vstupny strom:\n");
    kontrola(koren);
    vypis(koren);

    // zjednodušíme strom
    zjednodus(koren);
    // kontrola a výpis stromu po zjednodušení
    printf("Strom po zjednoduseni:\n");
    kontrola(koren);
    vypis(koren);

    // prevrátime poradie riadkov v strome
    prevrat(koren);
    // doplníme vrcholom správne súradnice
    suradnice(koren, 0, 0, velkost);
    // kontrola a výpis stromu po prevrateni
    printf("Strom po prevrateni:\n");
    kontrola(koren);
    vypis(koren);

    // uvoľníme pamäť stromu
    uvolni(koren);
}
