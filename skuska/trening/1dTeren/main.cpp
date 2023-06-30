#include <iostream>
using namespace std;

int main(){
    
    // pocet riadkov stlpcov a uprav
    int m, n, u;
    cin >> m >> n >> u;

    // vyrvorenie matic
    int **a, **b;
    a = new int*[m];
    b = new int*[m];

    // nacitanie matic
    for(int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        b[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    int x1, y1, x2, y2, h;
    for(int i = 0; i < u; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> h;

        if(x1 >= m || y1 >= n || x2 < 0 || y2 < 0) continue;
        if(x1 < 0) x1 = 0;
        if(y1 < 0) y1 = 0;
        if(x2 >= m) x2 = m-1;
        if(y2 >= n) y2 = n-1;

       
        for(int a = x1; a <= x2; a++)
        {
            for(int j = y1; j <= y2; j++) b[a][j] += h;
        }
    }

    // vypis 
    int v = 0, maxv = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j < n-1) cout << b[i][j] << " ";
            else cout << b[i][j];

            v = abs(a[i][j] - b[i][j]);
            if(v > maxv) maxv = v;
        }
        cout << endl;
    }
    cout << maxv << endl;

    // uvolnenie pamete
    for(int i = 0; i < m; i++) 
    {
        delete[] a[i];
        delete[] b[i];
    }

    delete[] a;
    delete[] b;
}