#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

typedef char dataType;

struct queue;

/* inicializuje prázdny rad */
void init(queue &q);

/* zistí, či je rad prázdny */
bool isEmpty(queue &q);

/* pridá prvok item na koniec radu */
void enqueue(queue &q, dataType item);

/* odoberie prvok zo začiatku radu a vráti jeho hodnotu */
dataType dequeue(queue &q);

/* vráti prvok zo začiatku radu, ale nechá ho v rade */
dataType peek(queue &q);

/* funkcia spočíta počet prvov v rade q, pričom dodrží požiadavky zadania  */
int dlzka(queue &q) {
    // TODO: VÁŠ KÓD TU 
    enqueue(q, 0);
    char c;
    int i = 0;
    while ((c = dequeue(q)) != 0)
    {
        i++;
        enqueue(q, c);
    }
    return i;
}

/** štruktúra pre uzol jednosmerného zoznamu */
struct node {
    dataType data;    // dáta v uzle
    node* next;  // ďalší uzol v zozname
};

struct queue {
    node *first; // Smernik na prvy uzol alebo NULL
    node *last;  // Smernik na posledny uzol alebo NULL
};

/* inicializuje prázdny rad */
void init(queue &q) {
    q.first = NULL;
    q.last = NULL;
}

/* zisti, ci je rad prazdny */
bool isEmpty(queue &q) {
    return q.last == NULL;
}

/* prida prvok s hodnotou item na koniec radu */
void enqueue(queue &q, dataType item) {
    node *tmp = new node;
    tmp->data = item;
    tmp->next = NULL;
    if (isEmpty(q)) {
        q.first = tmp;
        q.last = tmp;
    } else {
        q.last->next = tmp;
        q.last = tmp;
    }
}

/* odoberie prvok zo začiatku radu a vráti jeho hodnotu */
dataType dequeue(queue &q) {
    assert(!isEmpty(q));
    dataType result = q.first->data;
    node *tmp = q.first->next;
    delete q.first;
    if (tmp == NULL) {
        q.first = NULL;
        q.last = NULL;
    } else {
        q.first = tmp;
    }
    return result;
}

/* vrati prvok zo zaciatku radu, ale necha ho v rade */
dataType peek(queue &q) {
    assert(!isEmpty(q));
    return q.first->data;
}

void destroy(queue &q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

/* vypise rad q, pricom predpoklada, ze dlzkaRadu je pocet jeho prvkov */
void printQueue(queue &q, int dlzkaRadu) {
    for (int i = 0; i < dlzkaRadu; i++) {
        char c = dequeue(q);
        enqueue(q, c);
        putc(c, stdout);
    }
    putc('\n', stdout);
}


int main(void) {
    queue q;
    init(q);
    char c;

    c = getc(stdin);
    while (c != '\n') {
        enqueue(q, c);
        c = getc(stdin);
    }

    int dlzkaRadu = dlzka(q);
    printf("%d\n", dlzkaRadu);

    printQueue(q, dlzkaRadu);
    destroy(q);
}
