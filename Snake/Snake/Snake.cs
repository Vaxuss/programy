using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using Xamarin.Forms;

namespace Snake
{
    internal class Snake : BoxView
    {
        public decimal X;
        public decimal Y;

        public Snake() { }
        public Snake(decimal x, decimal y)
        {
            X = x;
            Y = y;
        }
    }
}
