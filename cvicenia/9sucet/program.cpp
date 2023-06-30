#include <cstdio>
#include <cassert>
using namespace std;

int main() {
    FILE *fr = fopen("vstup.txt", "r");
    FILE *fw = fopen("vystup.txt", "a");

    double x, y = 0;
    int e = fscanf(fr, "%lf%*c%*c", &x);
    assert(e != EOF);
    y += x;
    fprintf(fw, "   %10.2lf\n", x);
    while(!feof(fr))
    {
        e = fscanf(fr, "%lf%*c%*c", &x);
        assert(e != EOF);
        fprintf(fw, " + %10.2lf\n", x);
        y += x;
    }
  
    for(int j = 0; j < 14; j++) fprintf(fw, "-");
    fprintf(fw, "\n%13.2lf\n", y);

    fclose(fr);
    fclose(fw);
}