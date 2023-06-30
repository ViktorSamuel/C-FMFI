#include <iostream>
using namespace std;

int main() {
    int n, x, y, p;
    p = 0;
    cin >> n;
    cin >> y;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            if (a[i] - a[j] == y)
                p++;
        }
    }

    cout << p << endl;

    
}