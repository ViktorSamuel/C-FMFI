#include "SVGdraw.h"
#include <iostream>
using namespace std;

void kaktus(int n, double V, double S, double alfa, double beta,
            Turtle& turtle) {
    if (n == 0) {
        // trivialny pripad: vykreslime ciaru a vratime sa spat dole
        turtle.forward(V);
        turtle.forward(-V);
    } else {
        // TODO: doprogramujte pripad n>0
        turtle.forward(V);
        turtle.forward(-V + (V * beta));

        turtle.turnLeft(90);
        turtle.forward(S);
        turtle.turnRight(90);
        kaktus(n - 1, V * (1-beta), S * alfa, alfa, beta, turtle);
        
        turtle.turnRight(90);
        turtle.forward(2 * S);
        turtle.turnLeft(90);
        kaktus(n - 1, V * (1-beta), S * alfa, alfa, beta, turtle);

        turtle.turnLeft(90);
        turtle.forward(S);
        turtle.turnRight(90);
        turtle.forward(-V*beta);
    }
}

int main(void) {
    /* rozmery obrazku */
    double sirka, vyska;
    cin >> sirka >> vyska;

    int n;
    double V, S, alfa, beta;
    cin >> n >> V >> S >> alfa >> beta;

    /* vytvor korytnacku otocenu hore */
    Turtle turtle(sirka, vyska, "kaktus.svg",
                  sirka / 2, vyska - 10, 90);

    /* nakresli strom rekurzivne */
    kaktus(n, V, S, alfa, beta, turtle);

    /* ukonci vykreslovanie */
    turtle.finish();
}
