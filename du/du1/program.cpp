#include <iostream>
#include <cmath>
#include "SVGdraw.h"
using namespace std;

// struktura pre suradnice budov
struct bod {
    double x, y;
};

// vypocet vzdialenost medzi bodmi
double dlzka(bod &bod1, bod &bod2) {
    double dx = bod1.x - bod2.x;
    double dy = bod1.y - bod2.y;
    return sqrt(dx * dx + dy * dy);
}

// najblizsia posta k domu
int najPosta(bod dom, bod post[], int p)
{
    int najp = 0;
    int najvzdialenost = dlzka(dom, post[0]);

    for(int i = 1; i < p; i++)
    {
        int vzdialenost = dlzka(dom, post[i]);
        if(najvzdialenost > vzdialenost)
        {
            najvzdialenost = vzdialenost;
            najp = i;
        }
    }
    return najp;
}

int main(){
    // pocet domov, post
    int d, p;
    cin >> d >> p;

    // pole budov s ich suradnicami
    bod domy[d], posty[p];

    // NACITANIE SURADNIC
    //domov
    for(int i = 0; i < d; i++)
        cin >> domy[i].x >> domy[i].y;

    // posty
    for(int i = 0; i < p; i++)
        cin >> posty[i].x >> posty[i].y;
    
    // rozmery obrazku a velkost utvarov
    int h, w, r;
    cin >> w >> h >> r;

    //  pocet domov k postam pd(postadom)
    int pd[p]; 

    // vynulovanie poctu domov k postam
    for(int i = 0; i < p; i++)
        pd[i] = 0;

    // farby
    const int MAXP = 10;
    const char *farby[MAXP] = 
    {
        "red", "green", "blue", "white", "black", "gray", "yellow", "brown", "orange", "purple"
    };

    // vyvorenie obrazka s rozmermi h x w
    SVGdraw drawing(w, h, "posty.svg");

    // priradi k kazdemu domu postu, k kazdej poste pocet domov a vypise a vyfarbi sa dom podla jeho posty
    for(int i = 0; i < d; i++)
    {
        // posta k domu
        int dp = najPosta(domy[i], posty, p);
        pd[dp]++;
        cout << "dom " << i << " posta " << dp << endl;

        // ciara posta dom
        drawing.drawLine(domy[i].x, domy[i].y, posty[dp].x, posty[dp].y);

        // vykresli a vyfarby dom
        drawing.setFillColor(farby[dp]);
        drawing.drawEllipse(domy[i].x, domy[i].y, r/2, r/2);
    }

    // vykresli a vyfarby postu
    for(int i = 0; i < p; i++)
    {
        int x = posty[i].x - r/2;
        int y = posty[i].y - r/2;
        drawing.setFillColor(farby[i]);
        drawing.drawRectangle(x, y, r, r);
    }

    // ukonci kreslenie
    drawing.finish();

    // vypis pocetu domov k postam
    for(int i = 0; i < p; i++)
    {
        cout << "posta " << i << " pocet domov " << pd[i] << endl;  
    }
}