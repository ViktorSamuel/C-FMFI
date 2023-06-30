#include <cstdio>
#include <cassert>
#include <cstring>

const int MAXLINE = 1001;  // maximálna povolená dĺžka riadku

/* Struct square obsahuje údaje o jednom políčku plochy. */
struct square {
    char color;          // farba políčka
    int row, column;     // číslo riadku a stĺpca políčka
    square *next[4];     // smerníky na štyroch susedov
};

/* Konštanty určujúce smery v poli next pre struct square,
 * napr. next[UP] je horný sused políčka. */
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

/* Funkcia vytvorí nové políčko, nastaví mu zadanú farbu a súradnice,
 * všetkých susedov v poli next nastaví na NULL.
 * Vráti smerník na nové políčko.*/
square *newSquare(char color, int row, int column) {
    assert(color >= 'a' && color <= 'z');
    square *s = new square;
    s->color = color;
    s->row = row;
    s->column = column;
    for (int i = 0; i < 4; i++) {
        s->next[i] = NULL;
    }
    return s;
}

/* Funkcia zo vstupu načítava maticu farieb až kým nenačíta prázdny
 * riadok. Pre jednotlivé políčka matice vytvorí políčka typu square a
 * vráti smerník na políčko v ľavom hornom rohu.  Avšak v poli next sú
 * správne nastavené len smerníky smerom doprava (next[RIGHT]) a v
 * nultom stĺpci matice aj smerníky smerom nadol.  Ostatné smerníky sú
 * vždy NULL. */
square* readMatrix() {
    char line[MAXLINE];         // pole na nacitanie riadku
    square *topLeft = NULL;     // smernik na lavy horny roh matice
    square *lastRow = NULL;     // smernik na lave policko v aktualnom riadku

    int row = 0;  // cislo riadku
    int lineLength = 0;  // dlzka riadku v znakoch
    while (true) {
        // nacitaj riadok
        char *ret = fgets(line, MAXLINE, stdin);
        assert(ret != NULL);
        int currentLength = strlen(line);
        assert(currentLength >= 1);
        assert(line[currentLength] == 0);
        assert(line[currentLength - 1] == '\n');

        // skonci ak obsahuje iba koniec riadku
        if (currentLength == 1) {
            break;
        }

        // skontroluj, ze dlzka tohto riadku currentLength
        // sedi s lineLength, ale pre prvy riadok treba lineLength nastavit
        if (row == 0) {
            lineLength = currentLength;
        }
        assert(currentLength == lineLength);

        // vytvor policko v nultom stlpci a spravne ho zarad
        square *s = newSquare(line[0], row, 0);
        if (row == 0) {
            topLeft = s;
        } else {
            lastRow->next[DOWN] = s;
        }
        lastRow = s;
        // vytvaraj policka v dalsich stlpcoch a spravne ich zarad
        square *lastColumn = s;  // smernik na posledne policko v riadku
        for (int column = 1; column + 1 < lineLength; column++) {
            s = newSquare(line[column], row, column);
            lastColumn->next[RIGHT] = s;
            lastColumn = s;
        }
        row++;  // zvys pocitadlo riadkov
    }
    return topLeft;
}


/* Funkcia dostane smerník na square, ktorý môže byť aj NULL a vypíše
 * súradnice a farbu tohto štvrčeka vo formáte podľa zadania. Ak je smerník
 * NULL, vypíše namiesto hodnôt pomlčky. */
void printSquare(square *s) {
    if (s != NULL) {
        printf("(%d,%d,%c)\n", s->row, s->column, s->color);
    } else {
        printf("(-,-,-)\n");
    }
}

/* Funcia dostane nenulový smerník na square a vráti smerník na susedný
 * štvorček v smere zadanom znakom direction, t.j. U pre hore (up),
 * D pre dole (down), L pre doľava (left) a R pre doprava (right).
 * Ak susedný štvroček v požadovanom smere neexistuje, vráti
 * vstupný štvorček s. Štvorček v požadovanom smere aj vypíše
 * pomocou printSquare. */
square *oneMove(square *s, char direction) {
    // prepocitaj smer zo znaku na cislo 0..3
    int dir = 0;
    switch (direction) {
    case 'U':
        dir = UP;
        break;
    case 'R':
        dir = RIGHT;
        break;
    case 'D':
        dir = DOWN;
        break;
    case 'L':
        dir = LEFT;
        break;
    default:
        assert(false);
    }
    // najdi suseda v danom smere
    square *s2 = s->next[dir];
    // vypis suseda
    printSquare(s2);
    // vrat suseda alebo povodne policko ak je sused NULL
    if (s2 != NULL) {
        return s2;
    } else {
        return s;
    }
}

/* Funkcia dostane smerník na ľavé horné políčko matice, ktorá bola
 * načítaná zo vstupu funkciou readMatrix a doplní do nej chýbajúce
 * smerníky. Konkrétne v matici už sú smerníky smerom RIGHTa v nultom
 * stĺpci aj smerom DOWN, ale treba doplniť LEFT, UP a v stĺpcoch
 * okrem nultého aj DOWN. */
void addPointers(square *topLeft) {
    // TODO VÁŠ KÓD TU
}


/* Funkcia dostane smerník na ľavé horné políčko matice a celú maticu
 * uvoľní. */
void destroy(square *topLeft) {
    // TODO VÁŠ KÓD TU
}

/* Funkcia dostane smerník na políčko a jednodfarebnú plochu s tou
 * istou farbou ako toto políčko prefarbí na novú farbu '.'.
 * Vráti počet prefarbených políčok. */
int computeArea(square *s) {
    // TODO VÁŠ KÓD TU
    return 0;  // zmažte alebo zmeňte podľa potreby
}

int main(void) {

    // nacita maticu a vytvori policka
    square *topLeft = readMatrix();
    // prida do matice chybajuce smerniky na susedov
    addPointers(topLeft);

    // nacita riadok s prikazmi
    char line[MAXLINE];
    char *ret = fgets(line, MAXLINE, stdin);
    assert(ret != NULL);
    // pohyb po matici podla prikazov
    square *s = topLeft;
    printSquare(s);
    for (int i = 0; line[i] != '\n'; i++) {
        s = oneMove(s, line[i]);
    }

    // vyfarbovanie suvislej plochy
    int area = computeArea(s);
    // vypis velkosti plochy
    printf("area %d\n", area);

    // uvolnenie pamati
    destroy(topLeft);
}
