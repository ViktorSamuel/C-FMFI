#include <cstdio>
#include <cstring> 
#include <cassert>
using namespace std;

// max pocet riadkov, znakov v riadku a rozsah vypisu
int MaxR, MaxC, MaxP;
// smernik text
char **txt;
// poloha kurzora
int x = 0,
    y = 0;
// aktualne vykovanany prikaz
char key[7];

// nacitanie vstupov
void start(){
    char c;
    assert(scanf("%c", &c) == 1);

    // alokacia 
    txt = new char *[MaxR];
    for (int i = 0; i < MaxR; i++)
    {
        txt[i] = new char [MaxC+1];
        for (int j = 0; j < MaxC; j++) txt[i][j] = 0;
        txt[i][MaxC] = 0;
    }

    // nacitanie riadkov
    for (int i = 0; i < MaxR; i++)
    {
        for (int j = 0; j <= MaxC; j++)
        {
            assert(scanf("%c", &c) == 1);
            if (c != '\n') txt[i][j] = c;
            else break;
        }

        // ukoncenie editora
        if(!strcmp(txt[i], "END"))
        {
            for(int j = 0; j < 2; j++) txt[i][j] = 0; 
            break;
        }

        // rozsah vypisu
        if(strlen(txt[i])) MaxP = i+1;
    }
    
}

/// vypis
void print(){
    // meno suboru
    char name[21];
    bool a = false;
    assert(scanf("%s", name) == 1);

    // otvorenei lokacie
    FILE *f;
    if(!strcmp(name, "-")) f = stdout;
    else {
        f = fopen(name, "a");
        a = true;
    }
    
    // vypis
    fprintf(f, "START\n");
    for(int i = 0; i < MaxP; i++) fprintf(f, "%s\n", txt[i]);
    fprintf(f, "END\n");

    // uzatvorenie vypisu
    if(a) fclose(f);
}

// posun do lava
void left(){
    // zaciatok neprveho riadku
    if(0 < x && y == 0)
    {   
        x--;
        y = strlen(txt[x]);
    }
    // nie zaciatok riadku
    else if(y > 0) y--;

    printf("%s %d %d\n", key, x, y);
}

// posun v pravo
void right(){
    int len = strlen(txt[x]);

    // na konci poslendeho
    if(x < MaxR-1 && y == len)
    {
        x++;
        y = 0;
    }
    // nie koniec neposledneho
    else if(y < len) y++;

    printf("%s %d %d\n", key, x, y);
}

// zmazanie
void del(){
    int len = strlen(txt[x]);
    // nie je posledny
    if(y < len && x < MaxP)
    {
        for(int i = y; i < len; i++) txt[x][i] = txt[x][i+1];
    }

    // upravenie rozsahu vypisu
    for (int i = 0; i < MaxR; i++)
    {
        if (strlen(txt[i]))MaxP = i+1;   
    }
    
    printf("%s %d %d\n", key, x, y);
}

// vlozenie
void ins(){
    int len = strlen(txt[x]);

    // ak sa zmesti
    if(len < MaxC)
    {
        // nacitanie znak na vlozenie
        char newC[3];
        assert(scanf("%c", &newC[0]) == 1);
        for(int i = 0; i < 3; i++) assert(scanf("%c", &newC[i]) == 1);

        // posun
        for(int i = len; i > y; i--) txt[x][i] = txt[x][i-1];
        txt[x][y] = newC[1];

        // uprava rozsahhu vypisu
        if(x >= MaxP) MaxP = x+1;
    }
    printf("%s %d %d\n", key, x, y);
}

int main(){
    // rozsah editora
    for(int i = 0; i < 2; i++)
    {
        assert(scanf("%s", key) == 1);
        if(!strcmp(key, "MAXR")) assert(scanf("%d", &MaxR) == 1);
        if(!strcmp(key, "MAXC")) assert(scanf("%d", &MaxC) == 1);
    }

    // spustenie editora
    while (true)
    {
        assert(scanf("%s", key) == 1);
        if(!strcmp(key, "START")) 
        {
            start();
            break;
        }
    }

    // tabulka prikazov
    while (true)
    {
        assert(scanf("%s", key) == 1);
        if(!strcmp(key, "PRINT")) print();
        if(!strcmp(key, "LEFT")) left();
        if(!strcmp(key, "RIGHT")) right();
        if(!strcmp(key, "DELETE")) del();
        if(!strcmp(key, "INSERT")) ins();
        if(!strcmp(key, "EXIT")) break;
    }

    // UVOLNENIE PAMETE
    for(int i = 0; i < MaxR; i++)
    {
        delete[] txt[i];
    }
    delete[] txt;
}

