#include <iostream>
using namespace std;

// rozmery a hraci
int h, m, n;

// hracie pole
char **a;

// pocita najdlhsi usek
int dlzka(char c)
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        int d = 0;
        for(int j = 0; j < m; j++)
        {
            if(a[j][i] == c) d++;
            else d = 0;

            if(d > max) max = d;
        }
    }
    return max;
}

int main()
{
    // nacitanie rozmerov a hracov
    cin >> h >> m >> n;

    a = new char*[m];

    // nacitanie hracej plochy
    for (int  i = 0; i < m; i++)
    {
        a[i] = new char[n];
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    // vypis
    for(int i = 0; i < h; i++) 
    {
        cout << (char)(i+97) << " " << dlzka(i+97) << endl;
    }

    // uvolnenie pamete
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;    
}