#include<iostream>
#include <cmath>
using namespace std;

// funkcia, ktora spocita dlzku usecky zadanu pomocou
// suradnic koncovych bodov
double dlzka(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2; 
    return sqrt(dx * dx + dy * dy);
}


// TODO: sem napise vasu funkciu obvod
double obvod(double ax, double ay, double bx, double by, double cx, double cy)
{
    return dlzka(ax, ay, bx, by) + dlzka(ax, ay, cx, cy) + dlzka(cx, cy, bx, by);
}


int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

    // nacitame 4 body
    cin >> Ax >> Ay;
    cin >> Bx >> By;
    cin >> Cx >> Cy;
    cin >> Dx >> Dy;

    // pre kazdu trojicu vstupnych bodov vypise obvod trojuholnika
    cout << obvod(Ax, Ay, Bx, By, Cx, Cy) << endl;
    cout << obvod(Ax, Ay, Bx, By, Dx, Dy) << endl;
    cout << obvod(Ax, Ay, Cx, Cy, Dx, Dy) << endl;
    cout << obvod(Bx, By, Cx, Cy, Dx, Dy) << endl;
}
