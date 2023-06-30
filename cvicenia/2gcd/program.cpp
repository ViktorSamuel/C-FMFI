#include <iostream>
using namespace std;

int e(int a, int b){
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b, x;
    cin >> x >> a >> b;
    
    for (int i = 0; i <= b - a; i++) {
        int d = e(x, a + i);
        
        cout << "gcd(" << x << "," << a + i << ")=" << d << endl;
    }
}