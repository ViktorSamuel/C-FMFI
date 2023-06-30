#include <iostream>
#include <cassert>
using namespace std;

/** struktura pre uzol jednosmerneho zoznamu */
struct node {
    int data;    // data v uzle
    node* next;  // dalsi uzol v zozname
};

/* vypis zoznamu */
void vypisZoznam(node *zaciatok) {
    node * p = zaciatok;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "-1" << endl;
}

/* rekurzivna funkcia, ktora zo vstupu cita cisla az po -1, ulozi ich
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


/* uvolnenie pamati pre zoznam */
void uvolni(node *zaciatok) {
    while (zaciatok != NULL) {
        node* p = zaciatok;
        zaciatok = zaciatok->next;
        delete p;
    }
}

/* Funkcia dostane smernik zoznamVstup na zaciatok vstupneho zoznamu.
 * Tento zoznam rozdeli na dve casti tak, aby prva cast mala
 * pozadovanu dlzku zadanu ako parameter dlzka.  Smerniky na zaciatky
 * zoznamov ulozi do premennych zoznam1 a zoznam2.  Ak je niektory zo
 * zoznamov prazdny, prislusny smernik bude NULL.  Vo funkcii
 * nepouzivajte new ani delete, mente iba polozky uz existujucich
 * uzlov. */
void rozdel(node *zoznamVstup, int dlzka, node *&zoznam1, node *&zoznam2) {
    // TODO: VAS KOD TU
   node *p;
   if(dlzka != 0)
   {
    zoznam1 = zoznamVstup;
    p = zoznamVstup;
    for(int i = 0; i < dlzka - 1; i++) p = p -> next;
    zoznam2 = p->next;
    p->next = NULL;
   }
   else{
    zoznam2 = zoznamVstup;
    zoznam1 = NULL;
   }
}

int main(void) {
    node *zoznamVstup = nacitajZoznam();
    int dlzka;
    cin >> dlzka;

    // rozdelenie vstupneho zoznamu na dva
    node *zoznam1, *zoznam2;
    rozdel(zoznamVstup, dlzka, zoznam1, zoznam2);

    // vypisanie zoznamov
    vypisZoznam(zoznam1);
    vypisZoznam(zoznam2);

    // uvolnenie pamati
    uvolni(zoznam1);
    uvolni(zoznam2);

}
