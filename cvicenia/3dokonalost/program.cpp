#include<iostream>
using namespace std;

// TODO napiste funkciu sucet_delitelov
// Tato funkcia dostane kladne cele cislo n a vrati
// sucet celych cisel z rozsahu 1 az n-1, ktore delia cisla n

// TODO napiste funkciu je_dokonale
// ktora dostane kladne cele cislo n
// a vrati true ak je n dokonale cislo
// a false v opacnom pripade.
// Vo funkcii pouzite funkciu sucet_delitelov

int sucet_delitelov(int n)
{
    int x = 0;

    for (int j = 1; j < n; j++) {
        if (n % j == 0) {
            x += j;
        }
    }

    return x;
    
}

bool je_dokonale(int n)
{
    int y = sucet_delitelov(n);

    if (y == n)
    {
        return true;
    }
    else{
        return false;
    }
}


// funkciu main nemente
int main() {
    // nacitame zaciatok a koniec
    int zaciatok, koniec;
    cin >> zaciatok >> koniec;

    // pre kazde cislo z rozsahu od zaciatku do konca
    // vypiseme sucet delitelov a poznamku, ak je dokonale
    for(int i = zaciatok; i <= koniec; i++) {
	cout << i << " " << sucet_delitelov(i);
	if(je_dokonale(i)) {
	    cout << " dokonale";
	}
	cout << endl;
    }
}


