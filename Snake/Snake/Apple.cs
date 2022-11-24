using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace Snake
{
    internal class Apple : Label
    {
        public decimal X;
        public decimal Y;
        
        public Apple() { }

        public Apple(decimal x, decimal y) 
        { 
            X = x; 
            Y = y; 
        }
    }
}
