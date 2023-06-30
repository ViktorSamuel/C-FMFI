#include <iostream>
using namespace std;

int main() {
    int x, y, z, m;
    
    cin >> x >> y >> z;
    
    m = x;
    
    if (y < m){
        m = y;
    }
    
    
    if (z < m){
        m = z;
    }
    
    cout << m << endl;
    
}
