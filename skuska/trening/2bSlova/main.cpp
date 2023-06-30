#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

const int alphSize = 26; /* velkost abecedy, znaky cislujeme 0..alphSize-1 */
const int maxLen = 100;  /* maximalna dlzka slova v strome */

struct node {
    /* vrchol prefixoveho stromu  */
    char data;       // pismeno ulozene na hrane do rodica
    bool isWord;     // je tento vrchol koncom slova?
    node *children[alphSize]; // pole smernikov na deti
    node *parent;    // smernik na rodica
    int depth;       // hlbka vrcholu
};

struct trie {
    /* samotny prefixovy strom si pamata smernik na koren */
    node *root;
};

node* createNode(char data, node *parent) {
    /* vytvor vrchol stromu s danymi datami a s danym rodicom*/
    node* v = new node; // novy vrchol
    for (int i = 0; i < alphSize; i++) v->children[i] = NULL; // inicializacia deti
    v->isWord = false;
    v->data = data;
    //TODO VAS KOD TU: nastavte parent a depth
    v->parent = parent;
    if(parent == NULL) v->depth = 0;
    else v->depth = parent->depth+1;
    return v;
}

void trieInit(trie &t) {
    /* inicializuj prazdny prefixovy strom, ktory bude mat iba koren */
    t.root = createNode('\0', NULL); // koren si oznacime specialnym znakom 0
}

void destroySubtree(node *root) {
    /* rekurzivne uvolni pamat pre podstrom prefixoveho stromu
     * s korenom vo vrchole root */
    if (root != NULL) {
        for (int i = 0; i <= alphSize - 1; i++) {
            destroySubtree(root->children[i]);
        }
        delete root;
    }
}

void trieDestroy(trie &t) {
    /* uvolni pamat alokovanu pre prefixovy strom t */
    destroySubtree(t.root);
}

void trieInsert(trie &t, const char* word) {
    /* do prefixoveho stromu t pridaj slovo word */
    node *v = t.root;
    for (int i = 0; word[i] != 0; i++) { // posuvame sa od korena na spravne miesto
        int c = word[i] - 'a';
        assert(c >= 0 && c < alphSize);
        if (v->children[c] == NULL) { // ak vrchol chyba, spravime novy
            v->children[c] = createNode(word[i], v);
        }
        v = v->children[c];
    }

    /* Aktualny vrchol v je koncom slova */
    v->isWord = true;
}

void writeWord(node *v) {
    /* Vypise slovo reprezentovane vrcholom v,
     * pred nim vypise medzeru.
     * Odporucame pouzit smerniky na rodicov. */
    //TODO VAS KOD TU
    int h = v->depth;
    int j = 1;
    char *a = new char[h];
    while(v->parent != NULL) 
    {
        a[h-j] = v->data;
        j++;
        v = v->parent;
    }
    printf(" ");
    for(int i = 0; i < h; i++) printf("%c", a[i]);

    delete[] a;
}

bool endsWith(node *v, char str[]) {
    /* Zisti, ci slovo reprezentovane vrcholom v
     * konci retazcom str.
     * Odporucame pouzit smerniky na rodicov. */
    //TODO VAS KOD TU
        int slen = strlen(str);
        if(v->depth < slen) return false;
        
        for(int i = 1; i <= slen; i++)
        {
            if(str[slen-i] != v->data) return false;
            v = v->parent;
        }
        return true;   
}

void writeSubtreeWords(node *v) {
    /* Vypise vsetky slovnikove slova v podstrome
     * s korenom v v abecednom poradi. Pouziva funkciu writeWord */
    if (v == NULL) return;
    if (v->isWord) {
        writeWord(v);
    }
    for (int i = 0; i < alphSize; i++) {
        writeSubtreeWords(v->children[i]);
    }
}

void search(node *v, char str[]) {
    /* V podstrome s korenom v najde a vypise
     * vsetky slovnikove slova obsahujuce retazec str
     * v abecednom poradi.
     * Odporucame pouzit funkcie endsWidth a writeSubtreeWords. */
    //TODO VAS KOD TU
    if(endsWith(v, str)) 
    {
        writeSubtreeWords(v);
        return;
    }
    for(int i = 0; i < alphSize; i++)
    {
        if(v->children[i] != NULL)
        {
            search(v->children[i], str);
        } 
    }
}

int main(void) {
    trie t;  // vytvorenie prefixoveho stromu
    trieInit(t);

    // nacitanie slovnika
    char word[maxLen + 2];
    while (true) {
        scanf(" %100s ", word);  // nacitame slovo
        if (strcmp(word, "END") == 0) { // koniec slovnika - prerusime cyklus
            break;
        }
        trieInsert(t, word);         // vlozenie do stromu
    }

    // nacitanie retazcov od uzivatela
    while (true) {
        scanf(" %100s", word);
        if (strcmp(word, "END") == 0) {  // koniec programu
            break;
        }
        printf("Vyskyty retazca \"%s\":", word);  // vypis zaciatok odpovede
        search(t.root, word);  // rekurzivne prejdi strom
        printf("\n");     // vypis koniec riadku za odpovedou
    }

    trieDestroy(t);           // uvolnenie pamati pre strom
}
