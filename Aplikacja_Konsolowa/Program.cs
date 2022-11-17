using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aplikacja_Konsolowa
{
    internal class Program
    {
        public class Sortowanie
        {
            int[] tablicaLiczb = new int[10];
            int index = 0;

            /*
           * Nazwa funkcji : PodajWartosci
           * parametry wejściowe: Brak
           * wartowsc zwracana: nie zwraca nic tylko pobiera wartości podane przez urzytkownika
           * Autor 12345678910
           */
            public void PodajWartosci()
            {
                Console.WriteLine("Podaj 10 liczb calkowitych");

                for (int i = 0; i < tablicaLiczb.Length; i++)
                {
                    tablicaLiczb[i] = int.Parse(Console.ReadLine());
                }

                Console.WriteLine("Podaj index od którego zaczac sortowanie(od 1 do 10)\n");
                index = int.Parse(Console.ReadLine());
            }

            /*
            * Nazwa funkcji : Max
            * parametry wejściowe: Brak
            * wartowsc zwracana: Liczbę maksymalną w tabeli z podanego przedziału 
            * Autor 12345678910
            */
            public int Max()
            {
                int max = 0;
                for (int i = index; i < tablicaLiczb.Length; i++)
                {
                    if (tablicaLiczb[i] > max)
                    {
                        max = tablicaLiczb[i];
                    }
                }
                return max;
            }

            /*
           * Nazwa funkcji : Min
           * parametry wejściowe: max - maksymalną wartość w tabeli z podanego przedziału 
           * wartowsc zwracana: Liczbę minimalna w tabeli z podanego przedziału 
           * Autor 12345678910
           */
            public int Min(int max)
            {
                int min = max;
                for (int i = index; i < tablicaLiczb.Length; i++)
                {
                    if (tablicaLiczb[i] < min)
                    {
                        min = tablicaLiczb[i];
                    }
                    if (tablicaLiczb[i] == max)
                    {
                        for (int j = 0; j < tablicaLiczb.Length; j++)
                        {
                            for (int k = 0; k < tablicaLiczb.Length; k++)
                            {
                                if (tablicaLiczb[j] < tablicaLiczb[k])
                                {
                                    int temp = 0;
                                    temp = tablicaLiczb[j];
                                    tablicaLiczb[j] = tablicaLiczb[k];
                                    tablicaLiczb[k] = temp;
                                }
                            }
                        }
                    }
                }
                return min;
            }

            /*
            * Nazwa funkcji : Wynik
            * parametry wejściowe: max - maksymalną wartość w tabeli z podanego przedziału 
            * parametry wejściowe: min - Minimalną wartość w tabeli z podanego przedziału 
            * wartowsc zwracana: Wyświetla wartosći zmiennych min oraz max, wyświetla posortowaną tablicę
            * Autor 12345678910
            */
            public void Wynik(int min, int max)
            {
                Console.WriteLine("Wartosc Minimalna w podanym przedziale: " + min + "\n" + "Wartosc Maksymalna w podanym przedziale: " + max);

                Console.WriteLine("Tablica posortowana: ");
                for (int i = 0; i < tablicaLiczb.Length; i++)
                {
                    Console.WriteLine(tablicaLiczb[i]);
                }

                Console.ReadKey();
            }
        }
         
        static void Main(string[] args)
        {
            Sortowanie sortowanie = new Sortowanie();
            sortowanie.PodajWartosci();

            int max = sortowanie.Max();

            int min = sortowanie.Min(max);

            sortowanie.Wynik(min, max);
        }
    }
}