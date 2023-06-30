#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 1; j <= (2*n-1); j++)
        {
            if (j >= (n - i) && j <= (n + i))
            {
                x++;

                if (x % 2 == 1)
                    cout << "X";
                else
                    cout << ".";
            }
            else
               cout << "."; 
        }
        cout << endl;
    }
}