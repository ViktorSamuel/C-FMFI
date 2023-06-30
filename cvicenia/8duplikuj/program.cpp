#include <iostream>
#include <cassert>
using namespace std;

/** Struktura pre uzol jednosmerneho zoznamu */
struct node {
    int data;    // data v uzle
    node* next;  // dalsi uzol v zozname
};

/* Vypis zoznamu */
void vypisZoznam(node *zaciatok) {
    node * p = zaciatok;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "-1" << endl;
}


/* Rekurzivna funkcia, ktora zo vstupu cita cisla az po -1, ulozi ich
 * do spajaneho zoznamu a vrati smernik na prvy prvok zoznamu. */
node * nacitajZoznam() {
    int x;
    cin >> x;
    if (x == -1) {
        return NULL;
    } else {
        node * p = new node;
        p->data = x;
        p->next = nacitajZoznam();
        return p;
    }
}


/* Uvolnenie pamati pre zoznam */
void uvolni(node *zaciatok) {
    while (zaciatok != NULL) {
        node* p = zaciatok;
        zaciatok = zaciatok->next;
        delete p;
    }
}

/* Funkcia dostane smernik zaciatok na zaciatok vstupneho zoznamu.
 * Tento zoznam zmeni tak, ze za kazdy povodny uzol doplni jeden novy uzol,
 * v ktorom budu skopirovane tie iste data. */
void duplikuj(node *zaciatok) {
    // TODO: VAS KOD TU
    node *p = zaciatok;
    while(p != NULL)
    {
        node *n = new node;
        n->data = p->data;
        n->next = p->next;
        p->next = n;
        p = p->next->next;
    }
}

int main(void) {
    //nacitanie vstupneho zoznamu
    node *zoznam = nacitajZoznam();

    // zdvojenie uzlov v zozname
    duplikuj(zoznam);

    // vypisanie zoznamu
    vypisZoznam(zoznam);

    // uvolnenie pamati
    uvolni(zoznam);
}

