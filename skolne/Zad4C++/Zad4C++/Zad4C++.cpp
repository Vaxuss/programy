#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

void sortowanie(int tab[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int i = 1; i < 10; i++)
		{
			if (tab[i] > tab[i - 1])
			{
				swap(tab[i - 1], tab[i]);
			}
		}
	}
}

void shellSort(int tab[10])
{
	const int n = 10;
	for (int h = n / 2; h > 0; h--)
	{
		for (int i = 0; i < h; i++)
		{
			int k;

			for (int j = 1; j < (n - i) / h; j++)
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
}

int main()
{
	srand(time(NULL));	
	int limit = 0;
	int wybor = 0;
	int tab[10];

	cout << "Wybierz sposob sortowania 1 - shell'a, 2 - wstawiania: ";
	cin >> wybor;


	for (int i = 0; i < 10; i++)
	{
		tab[i] = rand() % 10 + 1;
		cout << tab[i] << endl;
	}

	if (wybor == 1)
	{
		shellSort(tab);
	}
	else
	{
		sortowanie(tab);
	}
	

	cout << endl;
	cout << "Tabela posortowana: " << endl;
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << tab[i] << endl;
	}
}

