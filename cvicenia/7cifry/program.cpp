#include <iostream>
#include <cstring>
using namespace std;

const int N = 10, M = 100;

int main(){
    
    char *a[N];
    char riadok[M];

    for(int i = 0; i < N; i++)
    {
        cin.getline(riadok, M);
        a[i] = new char[strlen(riadok)+1];
        strcpy(a[i], riadok);
    }

    char cislo[M];
    cin.getline(cislo, M);
    int l = strlen(cislo);

    for(int i = 0; i < l; i++)
    {
        if(i != l - 1) cout << a[(int)cislo[i] - 48] << " ";
        else cout << a[(int)cislo[i] - 48] << endl;
    }

    for(int i = 0; i < N; i++) delete[] a[i];
}