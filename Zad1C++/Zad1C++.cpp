#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

void main()
{
    cout << "Podaj Liczbe wieksza od 0: \n";
    int liczba;
    cin >> liczba;

    for (int i = 2; i < liczba; i++)
    {
        if (liczba / 1 == liczba && liczba / liczba == 1 && liczba %i != 0)
        {
            cout << "To jest liczba pierwsza" << "\n";
            break;
        }
        else 
        {
            cout << "To nie jest liczba pierwsza" << "\n";
            break;
        }
    }
    


    /*cout << "Podaj Liczbe: \n";
    int n;
    int i = 0;   
    int liczbaBinarna[8];
    int licznik1 = 0;
    int czyFib = 0;
    string Fib = "Tak";
    cin >> n;

    for (int i = 0; i < 8; i++) liczbaBinarna[i] = 0;
    while (n)
    {
        liczbaBinarna[i] = n % 2;

        if(liczbaBinarna[i] == 1)
        {
            licznik1++;
            czyFib++;
        }
        else
        {
            czyFib = 0;
        }

        if(czyFib == 2)
        {
            Fib = "Nie";
        }
      
        n /= 2;   
        i++;
    }

    for (int i = 7; i >= 0; i--)
    {
        cout << liczbaBinarna[i];
    }

    cout << "\n" << "Liczba 0: " << 8 - licznik1 << "\n";
    cout << "Liczba 1: " << licznik1 << "\n";
    cout << "Fibinari?: " << Fib;*/
}


