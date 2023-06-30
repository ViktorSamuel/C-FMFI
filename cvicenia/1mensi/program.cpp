#include <iostream>
using namespace std;

int main() {
    int x, y;
    
    cin >> x >> y;
    
    if(x == y) {
        cout << "rovnake " << x << endl;
    } else if(x < y) {
        cout << "mensi " << x << endl;
        cout << "vacsi " << y << endl;
    } else{
        cout << "mensi " << y << endl;
        cout << "vacsi " << x << endl;
    }

}