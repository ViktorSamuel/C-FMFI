#include <iostream>
using namespace std;

int main(){
    int n = 101;
    char c, str[n];
    cin >> c;
    cin >> str;
    str[n-1] = 0;

    for(int i = 0; str[i] != 0; i++)
    {
        if(str[i] != c)
            cout << str[i];
    }

    cout << endl;
    return 0;
}
