#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>

struct node {
    /* vrchol stromu pre aritmeticky vyraz */
    int val; /* ciselna hodnota v pripade vrcholu pre konstantu */
    char op; /* typ vrcholu: '+', '*' (operatory), ' ' (konstanta), 'x' (premenna) */
    node * left; /* smernik na lavy podvyraz */
    node * right; /* smernik na pravy podvyraz */
};

node * createNode(int val, char op, node *left, node *right) {
    /* funkcia vytvori novy vrchol so zadanymi hodnotami a vrati smernik */
    node *v = new node;
    v->left = left;
    v->right = right;
    v->op = op;
    v->val = val;
    return v;
}

node * createOp(char op, node *left, node *right) {
    /* vytvori novy vrchol stromu s operatorom op
     * a do jeho laveho a praveho podvyrazu ulozi
     * smerniky left a right. */
    return createNode(0, op, left, right);
}

node * createNum(int val) {
    /* Vytvori novy vrchol stromu pre konstantu s danou hodnotou,
     * lavy a pravy podvyraz bude prazdny, op bude medzera */
    return createNode(val, ' ', NULL, NULL);
}

node * createVar() {
    /* vytvori novy vrchol stromu pre premennu.
     * Lavy a pravy podvyraz budu prazdne, op bude 'x' */
    return createNode(0, 'x', NULL, NULL);
}

node *readPrefix() {
    /* z konzoly precita vyraz v prefixovej forme, ulozi ho
     * do stromu a vrati koren tohto stromu. */

    // TODO: VASE ZMENY DO TEJTO FUNKCIE
    // - DOPLNIT ABY SPRAVNE SPRACOVAVALO ZAPORNE CISLA

    int c = getchar(); // preskakujeme biele znaky, kym nenajdeme prvy nebiely
    while (isspace(c)) {
        c = getchar();
    }
    assert(c != EOF); // skontrolujeme, ze nie je koniec suboru

    if (isdigit(c) || c == '-') { // na vstupe je cislo (konstanta)
        bool a = false;
        if (c == '-') { // ak zacina znamienkom minus
            c = getchar(); // nacitame prvu cifru cisla
            a = true;
        }

        int val = 0; // hodnota konstanty
        while (isdigit(c)) { // kym nacitavame cifry
            val = val * 10 + (c - '0'); // pridame novu cifru k cislu val
            c = getchar(); // nacitame dalsiu cifru alebo oddelovac
        }
        ungetc(c, stdin); // nacitany oddelovac vratime na vstup
        if(a) val *= -1;
        return createNum(val); // vytvorime vrchol pre konstantu a vratime ho

    } else if (c == 'x') { // na vstupe je premenna x
        return createVar(); // vytvorime vrchol pre premennu a vratime ho

    } else { // na vstupe je binarny operator
        assert(c == '+' || c == '*'); // dovolujeme len operatory + a *
        node * left = readPrefix(); // rekurzivne nacitame lavy podvyraz
        node * right = readPrefix(); // rekurzivne nacitame pravy podvyraz
        return createOp(c, left, right); // spojime ich do stromu s korenom s operatorom c
    }
}

int evaluate(node *v, int x) {
    /* vyhodnoti vyraz dany stromom s korenom vo vrchole v,
     * pricom za premennu dosadi hodnotu danu v argumente x */
    assert(v != NULL);

    if (v->op == ' ') { // vo vrchole pre konstantu vratime jej hodnotu
        return v->val;
    }

    if (v->op == 'x') { // vo vrchole pre premennu vratime parameter x
        return x;
    }

    /* rekurzivne vyhodnotime lavy a pravy podvyraz */
    int valLeft = evaluate(v->left, x);
    int valRight = evaluate(v->right, x);

    /* Hodnotu laveho a praveho podvyrazu spojime podla typu operatora
     * a vratime. Prikaz break netreba, pouzivame return. */
    switch (v->op) {
    case '+':
        return valLeft + valRight;
    case '*':
        return valLeft * valRight;
    default:
        assert(false);
    }
}

void infix(node * v) {
    /* funkcia na vypisanie vyrazu v infixovej notacii */
    if (v->op == ' ') { // konstanta
        if (v->val < 0) printf("("); // zaporne konstanty dame do zatvoriek
        printf("%d", v->val);
        if (v->val < 0) printf(")");
    } else if (v->op == 'x') { // premenna
        printf("x");
    } else { // operator: rekurzivne vypiseme lavu a pravu cast
        printf("(");
        infix(v->left);
        printf(" %c ", v->op);
        infix(v->right);
        printf(")");
    }
}

void destroyTree(node* v) {
    /* Funkcia uvolni pamat stromu s korenom vo vrchole v */
    assert(v != NULL);
    if (v->left != NULL) { // vnutorny vrchol - rekurzivne znicime podstromy
        destroyTree(v->left);
        destroyTree(v->right);
    }
    delete v; // odalokujeme samotny vrchol
}

bool containsX(node *v) {
    /* funkcia zisti, ci sa v strome s korenom v nachadza
     * list zodpovedajuci premennej x */
    if(v == NULL) return false;
    if(v->op == 'x') return true; 
    return containsX(v->left) || containsX(v->right);
    // TODO: VAS KOD TU

}

node * simplify(node *v) {
    /* funkcia upravi vyraz zadany stromom s vrcholom v
     * tak, ze kazdy podstrom, ktory neobsahuje premennu
     * nahradi listom s prislusnou hodnotou. Vrati
     * smernik na koren takto upraveneho stromu */

    // TODO: VAS KOD TU
    if(!containsX(v))
    {
        v->val = evaluate(v, 0);
        v->op = ' ';
        if (v->left != NULL) destroyTree(v->left);
        if (v->right != NULL) destroyTree(v->right);
        v->left = NULL;
        v->right = NULL;
        return v;
    }

    if(v->left != NULL && v->left->op != ' ') simplify(v->left);
    if(v->right != NULL && v->right->op != ' ') simplify(v->right);
    return v;
     // MOZETE ZMENIT PODLA POTREBY
}

int main() {

    // naciteme pocet vyrazov n
    int n;
    int ret = scanf("%d ", &n);
    assert(ret == 1 && n >= 0);

    for (int i = 0; i < n; i++) { //opakujeme pre kazdy vyraz
        node *v = readPrefix(); // nacitame vyraz do stormu s korenom v

        printf("Povodny vyraz: "); // vypiseme povodny vyraz
        infix(v);
        printf("\n");

        // vypiseme, ci obsahuje premennu x
        if (containsX(v)) {
            printf("Vyraz obsahuje premmenu x\n");
        } else {
            printf("Vyraz neobsahuje premennu x\n");
        }

        // zjednodusime vyraz a znovu ho vypiseme
        v = simplify(v);
        printf("Po volani funkcie simplify: ");
        infix(v);
        printf("\n\n");

        // uvolnime pamat
        destroyTree(v);
    }
}
