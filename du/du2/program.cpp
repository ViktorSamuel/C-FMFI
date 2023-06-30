#include <iostream>
using namespace std;

// struct pre zavazia
struct zavazie
{
    int hmotnost, pocet;
};

// GLOBALNE PREMENNE
int n, m, pouzite = 1;
bool a = false;
zavazie *zavazia;
int *naj;

// generovanie postupnosti zavazi
void generuj(int tmp[], int j, int vaha, int p){
    if(j < n)
    {   // skusa kolko sa ich vojde
        for(int i = 0; i <= zavazia[j].pocet; i++)
        {
            // pridavanie zavazi
            if(i != 0) vaha += zavazia[j].hmotnost;
            
            // kontrola vahy
            if(vaha <= m)
            {
                tmp[j] = i;
                //kontrola posctu
                if((tmp[j] + p) >= pouzite) return;
                //kontrola spravnosti vahy
                if(vaha == m)
                {
                    pouzite = tmp[j] + p;
                    // naj = tmp;
                    // tmp = new int[n];
                    for(int i = 0; i < n; i++) naj[i] = tmp[i];
                    a = true;
                    return;
                }
                generuj(tmp, j+1, vaha, p+tmp[j]);
            }
            //rekurzivne volania
            else if(i == 0) generuj(tmp, j+1, vaha, p+tmp[j]);
            else generuj(tmp, j+1, vaha-zavazia[j].hmotnost, p+tmp[j]);
        }
    }
}

int main(){
    // nacitaj pocet druhov zavazi a pozadovanu hmotnost 
    cin >> n >> m;

    // alokuje a nacitaj pole zavazi
    zavazia = new zavazie[n];
    for(int i = 0; i < n; i++) 
    {
        cin >> zavazia[i].hmotnost >> zavazia[i].pocet;
        pouzite += zavazia[i].pocet;
    }

    // vytvor a vynuloj pole pre docasne rozlozenie zavazi
    int *tmp;
    tmp = new int[n];
    naj = new int[n]; 
    
    for(int i = 0; i < n; i++) 
    {
        tmp[i] = 0;
        naj[i] = 0;
    }
    // generuj postupnosti zavazi
    generuj(tmp, 0, 0, 0);

    // vypis
    if(a) 
    {
        cout << "Pocet pouzitych zavazi: " << pouzite << endl;
        for(int i = 0; i < n; i++) cout << "Zavazie " << zavazia[i].hmotnost << ": " << naj[i] << endl;
    }
    else cout << "Hmotnost sa neda vytvorit" << endl;

    // uvolnim pamet
    delete[] tmp;
    delete[] naj;
}