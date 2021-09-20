#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sortowanie_wstawianie(int* tab, int n)
{
    int j = 1, k;
    while (j <= n)
    {
        for (k = j; k > 0; k--)
        {
            if (tab[k] > tab[k - 1])
            {
                swap(tab[k], tab[k - 1]);
            }
            else break;
        }
        j++;
    }
}

int main()
{
    srand(time(NULL));
    int j, h, n, k=0, ile = 3;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; i++) tab[i] = rand() % 100;
    for (int i = 0; i < n; i++) cout << tab[i] << " ";
    cout << "\n";

    for (h = n / 2; h > 1; h--)
    {
        for (int i = 0; i < h; i++)
        {
            j = i;
            k = 0;
            int* wsk = new int[ile];
            while (j < n)
            {
                *(wsk + k) = tab[j];
                k++;
                j += h;
            }
            sortowanie_wstawianie(wsk, k);
            while (j >= 0)
            {
                k--;
                tab[j - h] = *(wsk + k);
                j -= h;
            }
            delete[] wsk;
        }
        ile++;
    }

    sortowanie_wstawianie(tab, n);
    for (int i = 0; i < n; i++) cout << tab[i] << " ";








    ///*int suma = 0;*/
    //int pivot = rand()%100 + 1, n = 0;
    //vector <int> wektor = {};

    //cout << "podaj liczbe od 1 - 100: ";
   
    //while (n != pivot)
    //{
    //    cin >> n;
    //    cout << endl;

    //    if (n == pivot)
    //    {
    //        cout << "trafiles na pivot!" << endl;

    //        for (int i = 0; i < wektor.size(); i++)
    //        {
    //            cout << wektor[i] << " ";
    //        }

    //    }
    //    if (n > pivot)
    //    {
    //        wektor.push_back(n);
    //        for (int i = 0; i < wektor.size(); i++)
    //        {
    //            cout << wektor[i] << " ";
    //        }
    //    }
    //    if (n < pivot)
    //    {
    //        wektor.insert(wektor.begin(), n);
    //        for (int i = 0; i < wektor.size(); i++)
    //        {
    //            cout << wektor[i] << " ";
    //        }
    //    }
    //}

    //wektor.insert(wektor.begin(), 1);

    //wektor.push_back(60);
   
    ///*cout << wektor[wektor.size() - 1];*/

    //for (int element : wektor)
    //{
    //    suma += element;     
    //}
    //cout << suma;
    



}

