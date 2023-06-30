#include <cstdio>
using namespace std;

// profil pretekara
struct pretekar
{
    bool *hotovo;
    int miesto = 0;
};

// pocet pretekarov a stanovist
int p, n;
// vysledkova listina
pretekar *zavodnici;

int main(){
    // nacitanie pocet pretekarov a stanovist
    scanf("%d %d", &p, &n);
    int m = 1;
    // vytvorenie vysledkova listina
    zavodnici = new pretekar[p];
    for(int i = 0; i < p; i++) 
    {
        zavodnici[i].hotovo = new bool[n];
        for(int j = 0; j < n; j++) zavodnici[i].hotovo[j] = false;
    }

    // tackovnie priehebu preteku
    int kto, kam;
    while(true)
    {
        // kto kam prisiel
        if(scanf("%d %d", &kto, &kam) != 2) break;
        zavodnici[kto].hotovo[kam] = true;

        // ak zavodnik nema umiestnenie
        if(zavodnici[kto].miesto == 0)
        {
            // kontrolujem ci uz bol vsade
            bool a = true;
            for(int j = 0; j < n; j++)
            {
                if(zavodnici[kto].hotovo[j] == false) a = false;
            }
            // ak an0 tak mu pridadim umiestnenie
            if(a)
            {
                zavodnici[kto].miesto = m;
                printf("%d. skoncil %d\n", m, kto);
                m++;
            }
        }
    }

    // vypis neuspesnych
    printf("Neuspesni ucastnici:");
    for(int i = 0; i < p; i++)
    {
        if(zavodnici[i].miesto == 0) printf(" %d", i);
    }
    printf("\n");

    // uvolnenie pamete
    for(int i = 0; i < p; i++) delete[] zavodnici[i].hotovo;
    delete[] zavodnici;
}