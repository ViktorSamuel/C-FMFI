#include <iostream>
#include <cstdlib>
using namespace std;

void c(int n){

    int k, p;
    p = 1;
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            p = i;
            k = 0;
            break;
        }
    }

    while(n % p == 0)
    {
        k++;
        n /= p;
    }

    cout << p << " " << k << endl;

    if (n != 1){
        c(n);
    }
}

int main() {
    int x;
    cin >> x;

    c(x);
}