#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 101;

/* TODO: naprogramujte funkciu substitucia podla zadania */
void substitucia(char prvy[], char druhy[], char vysledok[]){
    int np = strlen(prvy);
    int nd = strlen(druhy);
    int z = 0;

    for(int i = 0; i < np; i++)
    {
        if(prvy[i] == 'x')
        {
            for (int j = 0; j < nd; j++)
            {
                vysledok[z] = druhy[j];
                z++;
            }
        }
        else
        {
            vysledok[z] = prvy[i];
            z++;
        }
    }
    vysledok[z] = 0;
}

int main() {
    char prvy[MAXN];      // prvy riadok - text a
    char druhy[MAXN];     // druhy riadok - text b
    char vysledok[MAXN];  // text c

    // nacitaj vstup
    cin.getline(prvy, MAXN);
    cin.getline(druhy, MAXN);
    substitucia(prvy, druhy, vysledok);
    cout << vysledok << endl;
}
