#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sort()
{

}

int main()
{
    srand(time(NULL));
    int** tab2 = new int* [5];
    vector <int> wektor = {};
    int pole = 1;
    int suma = 0;
    for (int i = 0; i < 5; i++)
    {
        tab2[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            tab2[i][j] = rand()%25 +1;
            cout << tab2[i][j] << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {          
            wektor.push_back(abs(tab2[i][j] - pole));
            pole++;
        }
    }

    for (int element : wektor)
    {
        cout << element << " ";       
        suma += element;
    }

    cout << endl << suma;
    
    for (int i = 0; i < 5; i++)
    {
        delete[] tab2[i];
    }

    delete[] tab2;
}