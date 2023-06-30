#include <iostream>
using namespace std;

void printBinary(int n) {
    /* Rekurzivna funkcia na vypis kladneho cisla n v binarnej sustave.
     TODO: upravte funkciu tak, aby fungovala.
     Treba pridat trivialny pripad, ktory nebude obsahovat rekurzivne volanie
     a zmenit uz hotovu cast kodu tak, aby vypisovala cifry v spravnom poradi.
    */
   if(n != 0)
   {
    printBinary(n / 2);
    cout << n % 2;
   }
}

int main() {
    int n;
    cin >> n;
    printBinary(n);
    cout << endl;
}
