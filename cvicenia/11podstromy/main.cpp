#include <iostream>
#include <cassert>
using namespace std;

typedef int dataType;

struct node {
    /* vrchol stromu  */
    dataType data;    /* data vo vrchole */
    node * left;  /* lavy podstrom */
    node * right; /* pravy podstrom */
};

/* funkcia vytvori novy vrchol s danymi datami a podstromami */
node * createNode(dataType data, node *left, node *right) {
    node *v = new node;
    v->data = data;
    v->left = left;
    v->right = right;
    return v;
}

/* funkcia nacita strom zo vstupu */
node * readTree() {
    dataType data;
    char left, right;
    cin >> data >> left >> right;
    node *root = createNode(data, NULL, NULL);
    assert(left == 'Y' || left == 'N');
    assert(right == 'Y' || right == 'N');
    if (left == 'Y') {
        root->left = readTree();
    }
    if (right == 'Y') {
        root->right = readTree();
    }
    return root;
}

/* funkcia uvolni pamat alokovanu pre strom */
void destroyTree(node* v) {
    if (v != NULL) {
        destroyTree(v->left);
        destroyTree(v->right);
        delete v;
    }
}

int height(node *root) {
    if (root == NULL) {
        return -1;
    }
    // rekurzivne spocita vysku laveho a praveho podstromu
    int hLeft = height(root->left);    
    int hRight = height(root->right);  
    
    return hLeft + hRight + 2;
}

void printPostorder(node *root){
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d %d\n", root->data, height(root)+1);
}

int main(void) {
    node *root = readTree();

    // TODO: zavolajte vasu funkciu
    printPostorder(root);
    destroyTree(root);
}
