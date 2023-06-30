#include <iostream>
#include <cstdio>
using namespace std;

struct karticka
{
    int val;
    bool strana = false;
};

int main(){
    int n, m;
    karticka **pole;
    cin >> n >> m;

    pole = new karticka*[n];
    for(int i = 0; i < n; i++) pole[i] = new karticka[m];

    for(int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin >> pole[i][j].val;
            if(pole[i][j].val == 46) pole[i][j].val = -8;
        }
    }

    int *hra = new int[4];
    while (true)
    {
        int end = 0;
        for(int i = 0; i < 4; i++)
        {
            cin >> hra[i];
            if(hra[i] == -1) end++;
        }
        if(end == 4) break;

        pole[hra[0]][hra[1]].strana = true;
        pole[hra[2]][hra[3]].strana = true;

         for(int i = 0; i < n; i++)
        {
            for (int  j = 0; j < m; j++)
            {
                if(pole[i][j].strana) 
                {
                    if(pole[i][j].val == 46) printf("%3c", pole[i][j].val);
                    else if(pole[i][j].val == -8) printf("%3d", 46);
                    else printf("%3d", pole[i][j].val);
                }
                else printf("  #");    
            }
            cout << endl;
        }
        if(pole[hra[0]][hra[1]].val == pole[hra[2]][hra[3]].val)
        {
            pole[hra[0]][hra[1]].val = '.';
            pole[hra[2]][hra[3]].val = '.';
            cout << "SUPER" << endl << endl;
        }
        else{
            pole[hra[0]][hra[1]].strana = false;
            pole[hra[2]][hra[3]].strana = false;
            cout << "SMOLA" << endl << endl;
        }
    }

    for(int i = 0; i < n; i++) delete[] pole[i];
    delete[] pole;
    delete[] hra;
}