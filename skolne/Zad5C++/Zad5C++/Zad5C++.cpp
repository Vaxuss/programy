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
    string slowo = "ARMAGEDDON";
    int klucz = rand()% 100 + 1;
    int zmiana;
    string slowoZmienione;

    for (int i = 0; i < slowo.length(); i++)
    {
        zmiana = int(slowo[i]);
        zmiana += klucz;
        while (zmiana > 90)
        {
            zmiana -= 26;
        }
        slowoZmienione += char(zmiana);
        cout << char(zmiana);
    }

    cout << endl;
    cout << "Odszyfrowane: " << endl;

    for (int i = 0; i < slowoZmienione.length(); i++)
    {
        zmiana = int(slowoZmienione[i]);
        zmiana -= klucz;
        while(zmiana < 65)
        {
            zmiana += 26;
        }
        cout << char(zmiana);
    }
}


