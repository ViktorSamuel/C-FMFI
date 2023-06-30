#include <iostream>
#include <cstring>
using namespace std;

void usporiadaj(char str[101])
{
    int n = strlen(str);

    for(int i = 0; i < n; i++)
    {
        int prvok = str[i];
        int kam = i;
        while (kam > 0 && str[kam - 1] > prvok) {
            str[kam] = str[kam - 1];
            kam--;
        }
        str[kam] = prvok;
    }
}

int main(){
    
    char str1[101], str2[101];

    cin.getline(str1, 101);

    while(str1[0] != 0)
    {
        cin.getline(str2, 101);
        usporiadaj(str1);
        usporiadaj(str2);

        cout << str1 << endl;
        cout << str2 << endl;

        if(strcmp(str1, str2))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        cin.getline(str1, 101);
    }

    return 0;
}