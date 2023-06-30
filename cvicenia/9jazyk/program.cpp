#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

const int n = 26;
const int m = 21;

void LoadAndCout(char l[], int t[])
{
    FILE *f = fopen(l, "r");
    assert(f != NULL);
    char c;
    int num = 0;
    while((c = getc(f)) != EOF)
    {
        if('a' <= c && c <= 'z')
        {
            t[c - 'a']++;
            num++;
        }
    }

    fclose(f);

    cout << l << endl;
    for(int i = 0; i < n; i++) 
    {
        t[i] = t[i]*100/num;
        if(i < n-1) cout << t[i] << " ";
        else cout << t[i] << endl;
    }
}

int match(int tx[], int t[])
{
    int r = 0;
    for(int i = 0; i < n; i++) r += abs(tx[i] - t[i]);
    cout << r << endl;
    return r;
}

int main() {
    char lx[m], l1[m], l2[m];
    int tx[n], t1[n], t2[n];

    for(int i = 0; i < n; i++) tx[i] = t1[i] = t2[i] = 0;

    cin >> lx;
    LoadAndCout(lx, tx);

    cin >> l1;
    LoadAndCout(l1, t1);
    int a = match(tx, t1);
    
    cin >> l2;
    LoadAndCout(l2, t2);
    int b = match(tx, t2);

    if(a < b) cout << l1 << endl;
    else cout << l2 << endl;
}