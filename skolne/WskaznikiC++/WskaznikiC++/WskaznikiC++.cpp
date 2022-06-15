#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

int main()
{
    srand(time(NULL));

    /* int bok1 = 10;
     int* w_bok1;
     w_bok1 = &bok1;

     int bok2 = 15;
     int* w_bok2 = &bok2;

     int pole;
     int* w_pole = &pole;

     *w_pole = (*w_bok1 * *w_bok2);
     pole = bok1 * bok2;
     cout << *w_pole << " " << w_pole << endl;
     cout << pole << " " << &pole;

     int* w_ocena = new int;
     *w_ocena = 4;// int* w_ocena = new int(4); <- to to samo co w kodzie;
     cout << *w_ocena << " " << w_ocena;
     delete w_ocena;
     */

     /*const int n = 5;
     int tab[n];
     int* wsk = tab;

     for (int i = 0; i < n; i++)
     {
         *wsk++ = rand() % 10;
     }

     wsk -= n;

     for (int& element : tab)
     {
         cout << element << " ";
     }*/

     //for (int i = 0; i < n; i++)
     //{
     //    *(wsk + i) = rand() % 10;//tab[i] = rand() % 10;
     //    cout << *(wsk + i) << " ";//tab[i]
     //}

    int n = rand() % 20;
    int* tab = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        *tab++ = rand() % 20;
    }
    tab -= n;
    for (int i = 0; i < n; i++)
    {
        cout << *tab++ << " ";
    }
        
}


