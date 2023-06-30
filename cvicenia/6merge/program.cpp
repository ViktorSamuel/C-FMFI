#include <iostream>
#include <cassert>
using namespace std;

void merge(int a[], int b[], int an, int am)
{
    int i = 0;
    int j = 0;
    
    while(i < an && j < am)
    {
        if(a[i] < b[j])
        {
            cout << a[i] << " A" << endl;
            i++;
        }
        else if(a[i] > b[j])
        {
            cout << b[j] << " B" << endl;
            j++;
        }  
        else
        {
            cout << a[i] << " AB" << endl;
            i++;
            j++;
        }
    }

    while(i < an)
    {
        cout << a[i] << " A" << endl;
        i++;
    }

    while(j < am)
    {
        cout << b[j] << " B" << endl;
        j++;
    }
}

int main() {
    const int MAX = 1000;

    /* nacitanie dlzok postupnosti n a m */
    int n, m;
    cin >> n >> m;

    /* vytvorenie poli a ich nacitanie */
    int a[MAX], b[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    merge(a, b, n, m);
    // TODO: spracovanie poli a vypisovanie vysledku
    // ako pomocku uvadzame zakomentovane
    // telo funkcie merge z prednasky
    // upravte podla potreby

    /*
    int aux[2 * MAX];
    int i = left;       // index v prvej postupnosti
    int j = middle + 1; // index v druhej postupnosti
    int k = 0;          // index v poli aux
    
    while (i <= middle && j <= right) { 
        // Kym su obe postupnosti a[i..middle], a[j..right] neprazdne,
        // mensi z prvkov a[i], a[j] uloz do aux[k] a posun indexy
        if (a[i] <= a[j]) {                         
            aux[k] = a[i];
            i++;
            k++;
        } else {
            aux[k] = a[j];
            j++;
            k++;
        }
    }
    
    while (i <= middle) {  
        // Ak nieco ostalo v prvej postupnosti, dokopiruj ju na koniec
        aux[k] = a[i];
        i++;
        k++;
    }
    
    while (j <= right) { 
        // Ak nieco ostalo v druhej postupnosti, dokopiruj ju na koniec
        aux[k] = a[j];
        j++;
        k++;
    }
    
    for (int t = left; t <= right; t++) { 
        // Prekopiruj pole aux naspat do pola a
        a[t] = aux[t - left];
    }
    */
    
}
