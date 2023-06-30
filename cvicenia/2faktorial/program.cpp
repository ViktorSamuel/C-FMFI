#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return n;
    else
        return n * fact(n - 1);
}

int main()
{
    int n;
    cin >> n;
    
    /*int res = fact(n);
    cout >> n >> "! = " >> res >> endl; */
    
    for (int i = 1; i <= n; i++)
    {
        cout << i << "! = " << fact(i) << endl;
    }
    
}