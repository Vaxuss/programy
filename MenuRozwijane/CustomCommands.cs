﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace MenuRozwijane
{
    internal class CustomCommands
    {
        public static readonly RoutedUICommand Exit = new RoutedUICommand(
            "_Zamknij aplikacje",
            "Exit",
            typeof(CustomCommands),
            new InputGestureCollection() 
            { 
                new KeyGesture(Key.Q, ModifierKeys.Control)
            }
            );

        public static readonly RoutedUICommand Help = new RoutedUICommand(
            "Pomoc",
            "Exit",
            typeof(CustomCommands),
            new InputGestureCollection()
            {
                new KeyGesture(Key.F1)
            }
            );
    }
}
