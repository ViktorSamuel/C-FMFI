#include <iostream>
using namespace std;

struct bezec{
    int cislo = 0;
    int cas = 0;
};

void swap(int &x, int &y, int &z, int &v) {
    /* Vymeň hodnoty premenných x a y. */
    int tmp = x;
    x = y;
    y = tmp;

    int tmc = z;
    z = v;
    v = tmc;
}

int miNindex(bezec a[], int n){
    int index = 0;
    for(int i=1; i<n; i++) {
        if(a[i].cas>a[index].cas) {
            index = i;
        }
    }
    return index;
}

void sort(bezec a[], int n){
    for(int i = n-1; i >= 1; i--)
    {
        int index = miNindex(a, i + 1);
        swap(a[i].cas, a[index].cas, a[i].cislo, a[index].cislo);
    }
}

int main() {
    int n;
    cin >> n;
    bezec a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].cas;
        a[i].cislo = i;
    }

    sort(a, n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i].cislo << " " << a[i].cas << endl;
    }
    
}

