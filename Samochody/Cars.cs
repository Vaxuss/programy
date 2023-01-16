using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Samochody
{
    internal class Cars
    {
        public int id { get; set; }
        public string nrRejestracji { get; set; }
        public string marka { get; set; }
        public string rokProdukcji { get; set; }
        public string kolor { get; set; }
        public int iloscPasazerow { get; set; }

        public Cars() { }
       public Cars(int id, string nrRejestracji, string marka, string rokProdukcji, string kolor, int iloscPasazerow)
        {
            this.id = id;
            this.nrRejestracji = nrRejestracji;
            this.marka = marka;
            this.rokProdukcji = rokProdukcji;
            this.kolor = kolor;
            this.iloscPasazerow = iloscPasazerow;
        }
    }
}
