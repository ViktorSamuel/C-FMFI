#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int x = 0;
    while(true){
        int n;
        cin >> n;

        x++;

        if (n == 1)
        {
            cout << "A " << x << endl;
            break;
        }
        else if(n == 6)
        {
            cout << "B " << x << endl;
            break;
        }
    }
}
