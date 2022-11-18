using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using Xamarin.Forms;

namespace Snake
{
    internal class Snake : BoxView
    {
        public double X;
        public double Y;
        public double Kierunek = 1;
        public List<int> NastepneKierunki = new List<int>();
        public Snake() { }
        public Snake(double x, double y)
        {
            X = x;
            Y = y;
        }
    }
}
