#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }

    for(int j = 0; j < n; j++){
        if (j % 2 == 0)
            cout << " " << a[j];
    }

    cout << endl;

    for(int j = 0; j < n; j++){
        if (j % 2 == 1)
            cout << " " << a[j];
    }

    cout << endl;
}