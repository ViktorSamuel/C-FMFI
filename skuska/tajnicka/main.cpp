#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char word[100];
	cin >> word;

	int n;
	cin >> n;	

	char *line;
	line = new char[n];
	
	for(int i = 0; i < n; i++) cin >> line[i];

	cout << "results " << endl;

	int slen = strlen(word);
	int w = 0;
    int index = 0;

	for(int i = 1; i < n-1; i++)
	{
		if(line[i] == '.' || line[i] == word[w]) 
		{
			if(w == 0) index = i;
			w++;
        }
        else w = 0;
        
		if(w == slen && line[i+1] == '#') 
		{
			cout << "0 " << index << endl;	
			w = 0;
		}
		if(line[i] == '#' || w > slen) w = 0;
	}

	delete[] line;
}