#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[101], str1[101];
    int n = 0;

    cin >> str;

    while(true)
    {
        cin >> str1;

        if(str1[0] == '.')
            break;

        if(!strcmp(str, str1))
            n++;

    }

    cout << n << endl;

    return 0;
}