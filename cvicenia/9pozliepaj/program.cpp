#include <cstdio>
using namespace std;

int maxN = 101;

int main() {
    FILE *fw = fopen("vystup.txt", "a");

    for(char name[6] = "a.txt"; name[0] != 'z' + 1; name[0]++)
    {
        FILE *fr = fopen(name, "r");
        if(fr != NULL)
        {
            char str[maxN];
            char *s = fgets(str, maxN, fr);
            if(s != NULL) fputs(str, fw);
            fclose(fr);
        }
        else printf("subor %c.txt nemozno otvorit\n", name[0]);
    }
    fclose(fw);
}