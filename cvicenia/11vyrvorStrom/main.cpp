#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

typedef int dataType;

/* Uzol binarneho vyhladavacieho stromu. */
struct node {
    int data;      // hodnota ulozena v uzle
    node *parent;  // smernik na rodica (NULL, ak neexistuje)
    node *left;    // smernik na lave dieta (NULL, ak neexistuje)
    node *right;   // smernik na prave dieta (NULL, ak neexistuje)
};

/* Samotna dynamicka mnozina (obal pre pouzivatela). */
struct set {
    node *root;  /* koren stromu, NULL pre prazdny strom */
};

/* Funkcia inicializuje prazdny binarny vyhladavaci strom */
void init(set &s) {
    s.root = NULL;
}

/* Uvolni pamat pre podstrom s korenom *root. */
void destroy(node *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

/* Zlikviduje mnozinu s (uvolni pamat). */
void destroy(set &s) {
    destroy(s.root);
}


/* Vytvori strom pre usek utriedeneho pola a od indexu left po index
 * right, vratane, podla algoritmu uvedeneho v zadani. Vrati koren
 * tohto stromu. V argumente parent dostane smernik na vrchol, ktory
 * je rodicom korena, ten ulozi do prislusnej polozky parent. */
node * buildSubtree(int left, int right, int a[], node *parent) {
    // TODO vas kod tu
    if(right < left) return NULL;
    else
    {
        int middle = (left + right) / 2;
        node *n = new node;
        n->data = a[middle];
        n->parent = parent;
        n->left = buildSubtree(left, middle-1, a, n);
        n->right = buildSubtree(middle+1, right, a, n);
        return n;
    }

}

/* Do prazdnej mnoziny s vyvori binarny vyhladavaci strom,
 * ktoreho kluce budu prvky z utriedeneho pola a dlzky n. */
void buildTree(set &s, int n, int a[]) {
    assert(s.root == NULL);
    s.root = buildSubtree(0, n - 1, a, NULL);
}

/* Dostane smernik na uzol stromu a vypise kluc v tomto uzle, ale ak
 * smernik je NULL, vypise slovo NULL. Pomocna funkcia pre funkciu
 * inorder. */
void printData(node *v) {
    if (v == NULL) {
        cout << "NULL";
    } else {
        cout << v->data;
    }
}

/* Strom s korenom *root vypise v inorder poradi, pricom v kazdom
 * uzle vypise riadok obsahujuci kluc, ako aj kluce v rodicovi, v
 * lavom a pravom dietati.  Ak rodic alebo deti neexistuju,
 * vypise namiesto ich kluca slovo NULL. */
void inorder(node *root) {
    if (root != NULL) {
        // vypiseme lavy podstrom
        inorder(root->left);
        // vypiseme hodnoty v koreni a v okolitych uzloch
        cout << "data: " << root->data;
        cout << ", parent: ";
        printData(root->parent);
        cout << ", left: ";
        printData(root->left);
        cout << ", right: ";
        printData(root->right);
        cout << endl;
        // vypiseme pravy podstrom
        inorder(root->right);
    }
}

/* Strom pre mnozinu s vypise v inorder poradi */
void printInorder(set &s) {
    inorder(s.root);
}

int main(void) {
    const int MAXN = 1000;

    // nacitame n a postupnost a
    int n;
    cin >> n;
    int a[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        assert(i == 0 || a[i - 1] < a[i]);
    }

    // inicializujeme prazdny strom
    set tree;
    init(tree);

    // vybudujeme strom podla pola a
    buildTree(tree, n, a);

    // vypiseme vybudovany strom
    printInorder(tree);

    // uvolnime pamat
    destroy(tree);
}
