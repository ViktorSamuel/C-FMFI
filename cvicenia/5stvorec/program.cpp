#include <iostream>
using namespace std;

int stvorec(int n) {
    if (n == 0) {
        // TODO: dopiste aby funkcia vratila n na druhu pre n=0
        return n;
    } else {
        // TODO: spocitajte rekurzivne (n-1) na druhu funkciou stvorec
        // potom pouzite vysledok pri vypocte n na druhu
        return stvorec(n-1) + 2 * n - 1;
    }
}

int main(void) {
    while (true) {
        int n;
        cin >> n;
        if (n < 0) break;
        cout << n << " na druhu je " << stvorec(n) << endl;
    }
}
