#include <cstdio>
#include <cctype>
#include <cassert>
using namespace std;

// vstup budeme citat z konzoly
FILE *fr = stdin;
int x[26]; 

struct stack;
typedef int dataType;

struct node {
    dataType data;
    node *next;
};

struct stack {
    node *top; // Smernik na vrch zasobnika (zaciatok spajaneho zoznamu). Ak je zasobnik prazdny, ma hodnotu NULL.
};

/* Inicializuje prazdny zasobnik */
void init(stack &s) {
    s.top = NULL;
}

/* Zisti, ci je zasobnik prazdny */
bool isEmpty(stack &s) {
    return s.top == NULL;
}

/* Prida prvok item na vrch zasobnika */
void push(stack &s, dataType item) {
    node *tmp = new node;
    tmp->data = item;
    tmp->next = s.top;
    s.top = tmp;  
} 

/* Odoberie prvok z vrchu zasobnika a vrati jeho hodnotu */
dataType pop(stack &s) {
    assert(!isEmpty(s));
    dataType result = s.top->data;
    node *tmp = s.top->next;
    delete s.top;
    s.top = tmp;
    return result;
}

/* Vrati prvok na vrchu zasobnika, ale necha ho v zasobniku */          
dataType peek(stack &s) {
    assert(!isEmpty(s));
    return s.top->data;
}

/* Uvolni pamat */
void destroy(stack &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void evaluate()
{    
    stack s;
    init(s);
    
    while (true) {
        // preskakujeme medzery na vstupe
        int c = getc(fr);
        while (c != EOF && c != '\n' && isspace(c)) {
            c = getc(fr);
        }
        // koniec riadku alebo EOF znamenaju koniec vyrazu
        if (c == EOF || c == '\n') {
            break;
        } else if (isdigit(c)) {
            // ked najdeme cifru, vratime ju 
            // a nacitame realne cislo
            ungetc(c, fr);
            int num;
            fscanf(fr, "%d", &num);
            push(s, num);
        } 
        else if(isalpha(c)) {
            push(s, x[c-97]);
        }
        else {
            // nacitali sme zrejme nejake znamienko 
            // vyberieme 2 operandy zo zasobnika
            // najskor druhy operand
            int num2 = pop(s);
            int num1 = pop(s);
            // vykoname operaciu podla typu operatora
            // a vysledok dame na zasobnik
            switch (c) {
                case '+':
                    push(s, num1 + num2);
                    break;
                case '-':
                    push(s, num1 - num2);
                    break;
                case '*':
                    push(s, num1 * num2);
                    break;    
                case '/':
                    push(s, num1 / num2);
                    break;    
            }
        }
    }
    
    // vysledna hodnota je na vrchu zasobnika,
    // vyberieme ju a vypiseme
    printf("%d\n", pop(s));
    // teraz by uz mal byt zasobnik prazdny
    assert(isEmpty(s));

    destroy(s);
}

int main() {   
    char c;
    
    while(true)
    {
        assert(scanf("%c", &c) == 1);
        if(c == '\n') break;
        if(isalpha(c))
        {
            assert(scanf("%*c%d", &x[c-97]) == 1);
        }
    }

    evaluate();
}