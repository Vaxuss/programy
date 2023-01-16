using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EgzaminPowtorka
{
    internal class Person
    {
        
        public string imie { get; set; }
        public string nazwisko { get; set; }
        public int telefon { get; set; }

        public Person(string imie, string nazwisko, int telefon)
        {
            this.imie = imie;
            this.nazwisko = nazwisko;
            this.telefon = telefon;
        }
    }
}
