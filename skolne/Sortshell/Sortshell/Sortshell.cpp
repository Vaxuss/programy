#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

//quick sort przez rekurencje pd.
//Bąbelkowe, Wybór, Naiwne, zwarjowane, wstawiania 

int main()
{
	srand(time(NULL));
	const int n = 10;
	int tab[n];

	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 10+1;
		
	}

	for (int h = n / 2; h > 0; h--)
	{
		for (int i = 0; i < h; i++)
		{
			int k;

			for(int j = 1; j < (n - i) / h; j++)
			{
				for (k = j; k > 0; k--)
				{
					if (tab[(k + i) * h] < tab[((k + i) - 1) * h])
					{
						swap(tab[(k + i) * h], tab[((k + i) - 1) * h]);
					}
					else break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << endl;
	}
}
