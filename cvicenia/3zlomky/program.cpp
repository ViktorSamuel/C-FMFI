#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
    while(true)
    {
        int r = a % b;
        a = b;
        b = r;

        if(b == 0)
        {
            return a;
            break;
        }

    }
}

/* Funkcia dostane zlomok a upraví ho na základný tvar tak, že čitateľ
 * a menovateľ predelí ich najväčším spoločným delitelom a zabezpečí,
 * aby menovateľ bol kladné číslo. Hodnota zlomku zostane po úprave rovnaká. */
void uprav(int &citatel, int &menovatel) {
    // Túto časť funkcie nemeňte
    int d = gcd(abs(citatel), abs(menovatel));
    citatel /= d;
    menovatel /= d;
    // TODO: Doprogramujte zvyšok funkcie - úpravu znamienok,
    // aby menovateľ bol kladný
    if (menovatel < 0) // && citatel < 0
    {
        menovatel *= -1;
        citatel *= -1;
    } 
        
}

void scitaj(int c1, int m1, int c2, int m2, int &c3, int &m3){
    
    c3 = c1 * m2 + c2 * m1;
    m3 = m1 * m2;

    uprav(c3, m3);
}

void vypis(int g, int h)
{
    cout << g << "/" << h;
}


int main() {
    // Funkciu main nemeňte

    // nacitanie zlomkov z1 a z2
    int citatel1, menovatel1, citatel2, menovatel2;
    cin >> citatel1;
    cin >> menovatel1;
    cin >> citatel2;
    cin >> menovatel2;

    // vypis zlomkov v povodnom tvare
    cout << "Povodny vstup" << endl;
    cout << "Zlomok 1: ";
    vypis(citatel1, menovatel1);
    cout << endl;
    cout << "Zlomok 2: ";
    vypis(citatel2, menovatel2);
    cout << endl << endl;

    // uprava zlomkov na zakladny tvar
    uprav(citatel1, menovatel1);
    uprav(citatel2, menovatel2);

    // vypis zlomkov po uprave
    cout << "Po uprave" << endl;
    cout << "Zlomok 1: ";
    vypis(citatel1, menovatel1);
    cout << endl;
    cout << "Zlomok 2: ";
    vypis(citatel2, menovatel2);
    cout << endl << endl;

    // scitanie zlomkov a vypis vysledku
    cout << "Sucet: ";
    int citatel3, menovatel3;
    scitaj(citatel1, menovatel1, citatel2, menovatel2,
           citatel3, menovatel3);
    vypis(citatel3, menovatel3);
    cout << endl;
}
