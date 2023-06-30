#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

/* Dynamicke pole celych cisel */
struct dynArray {
    int *p;                   // smernik na prvy prvok pola
    int size;                 // velkost alokovaneho pola
    int length;               // pocet prvkov pridanych do pola
};

void init(dynArray &a) {
    /* Inicializuje dynamicke pole,
     * pricom na zaciatok pren alokuje pole velkosti 2 */
    a.size = 2;
    a.length = 0;
    a.p = new int[a.size];
}

void reallocate(dynArray &a, int newSize) {
    /* Pre dynamicke pole a alokuje nove pole
     * velkosti newSize, presunie tam vsetky prvky
     * a spravne nastavi a.size a a.p */

    assert(a.length <= newSize && newSize >= 2);

    // TODO: Vas kod tu, pouzite kod z prednasky
    int *arr = new int[newSize];
    for(int i = 0; i < a.length; i++) arr[i] = a.p[i];
    delete[] a.p;
    a.p = arr;
    a.size = newSize;
}

void add(dynArray &a, int x) {
    /* Prida na koniec dynamickeho pola prvok x
     * a v pripade potreby realokuje pole */
    if (a.length == a.size) {                // ak uz sa x do pola nevojde
        reallocate(a, a.size * 2);
    }
    a.p[a.length] = x;                       // ulozi x na koniec pola
    a.length++;                              // zvysi pocet prvkov ulozenych v poli
}

void remove(dynArray &a) {
    /* Z dynamickeho pola a odstrani posledny prvok (na pozicii
     * a.length-1) a spravne nastavi novu hodnotu a.length. Ak a.length
     * klesne pod stvrtinu a.size, zmeni velkost pola na polovicnu
     * oproti terajsej pomocou funkcie reallocate.
     * Pole velkosti 2 uz dalej nezmensujte. */
    assert(a.length > 0);

    // TODO: Vas kod tu
    a.length--;
    if(a.size <= 2) return;
    if(a.length < a.size / 4) reallocate(a, a.size / 2);
}

int get(dynArray a, int index) {
    /* Vrati prvok dynamickeho pola a na pozicii index
     *  (ak ide o korektnu poziciu) */
    assert(index >= 0 && index <= a.length - 1);
    return a.p[index];
}

void set(dynArray &a, int index, int x) {
    /* Nastavi prvok dynamickeho pola a na pozicii index na hodnotu x
     * (ak ide o korektnu poziciu)*/
    assert(index >= 0 && index <= a.length - 1);
    a.p[index] = x;
}

int length(dynArray a) {
    /* Vrati pocet prvkov ulozenych v dynamickom poli a */
    return a.length;
}

void destroy(dynArray &a) {
    /* Zlikviduje dynamicke pole a (uvolni alokovanu pamat) */
    delete[] a.p;
}

int main() {
    /* inicializacia dynamickeho pola */
    dynArray a;
    init(a);

    /* inicializacia pola na nacitanie prikazu */
    char *command = new char[100];

    while (true) {
        /* nacitame prikaz a spracujeme ho */
        cin >> command;
        if (strcmp(command, "add") == 0) {
            int value;
            cin >> value;
            cout << "Adding value " << value << endl;
            add(a, value);
        } else if (strcmp(command, "remove") == 0) {
            cout << "Removing the last element " << endl;
            remove(a);
        } else if (strcmp(command, "set") == 0) {
            int pos, value;
            cin >> pos >> value;
            cout << "Setting value at position " << pos
                 << " to " << value << endl;
            set(a, pos, value);
        } else if (strcmp(command, "get") == 0) {
            int pos, value;
            cin >> pos;
            value = get(a, pos);
            cout << "Value at position " << pos << " is " << value << endl;
        } else if (strcmp(command, "size") == 0) {
            cout << "Size of the array is " << a.size << endl;
        } else if (strcmp(command, "end") == 0) {
            cout << "Finishing " << endl;
            break;
        }
    }

    /* odalokujeme pamat */
    destroy(a);
    delete[] command;
}
