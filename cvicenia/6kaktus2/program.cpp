#include "SVGdraw.h"
#include <iostream>
using namespace std;

void kaktus(int n, int m, double V, double S[], double alfa, double alfa2,
            double beta[], Turtle& turtle) {
    if (n == 0) {
        // trivialny pripad: vykreslime ciaru a vratime sa spat dole
        turtle.forward(V);
        turtle.forward(-V);
    } else {
        // TODO: doprogramujte pripad n>0
        for(int i = 0; i < m; i++)
        {
            turtle.forward(V);
            turtle.forward(-V + (V * beta[i]));
            turtle.turnRight(90);
            turtle.forward(S[i] * alfa2);
            turtle.turnLeft(90);
            kaktus(n-1, m, V * (1-beta[i]), S, alfa, alfa2 * alfa, beta, turtle);
            
            turtle.turnRight(90);
            turtle.forward(-S[i] * alfa2);
            turtle.turnLeft(90);
            turtle.forward(-V * beta[i]);
        }
    }
}

int main(void) {
    /* rozmery obrazku */
    double sirka, vyska;
    cin >> sirka >> vyska;

    const int MAXM = 10;
    double S[MAXM];
    double beta[MAXM];

    int n, m;
    double V, alfa;
    cin >> n >> m >>  V >> alfa;
    for (int i = 0; i < m; i++) {
        cin >> S[i] >> beta[i];
    }

    /* vytvor korytnacku otocenu hore */
    Turtle turtle(sirka, vyska, "kaktus.svg",
                  sirka / 2, vyska - 10, 90);

    /* nakresli strom rekurzivne */
    kaktus(n, m, V, S, alfa, 1, beta, turtle);

    /* ukonci vykreslovanie */
    turtle.finish();
}
