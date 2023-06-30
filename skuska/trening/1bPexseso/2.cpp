#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
	cin >> n >> m;

	int** a = new int*[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}

	int x1, y1, x2, y2;
	while(true)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == -1) break;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(a[i][j] == -5) cout << "  .";
				else if((i == x1 && j == y1) || (i == x2 && j == y2)) printf("%3d", a[i][j]);
				else cout << "  #";
			}
			cout << endl;
		}

		if(a[x1][y1] == a[x2][y2])
		{
			a[x1][y1] = -5;
			a[x2][y2] = -5;
			cout << "SUPER" << endl << endl;
		}
		else cout << "SMOLA" << endl << endl;
	}

    for(int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
}