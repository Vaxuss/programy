using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Snake
{
    public partial class MainPage : ContentPage
    {
        List<Snake> snake = new List<Snake>();
        List<int> kierunki = new List<int>();
        public MainPage()
        {
            InitializeComponent();
            snake.Add(new Snake(0.5,0.45));
            snake.Add(new Snake(0.5,0.5));
            snake.Add(new Snake(0.5,0.55));


            for(int i=0; i< snake.Count(); i++)
            {
                layout.Children.Add(snake[i]);
                AbsoluteLayout.SetLayoutBounds(snake[i], new Rect(snake[i].X, snake[i].Y, 40, 40));
                AbsoluteLayout.SetLayoutFlags(snake[i], AbsoluteLayoutFlags.PositionProportional);
            }

            Device.StartTimer(new TimeSpan(0, 0, 0, 0, 200), () =>
            {
                Device.BeginInvokeOnMainThread(() =>
                {
                    Ruch();
                });
                return true; // runs again, or false to stop
            });
        }

        public void Ruch()
        {
            if(kierunki.Count > 0)
            {
                bool wszystkie = true;
                for (int i = 0; i < snake.Count(); i++)
                {
                    if (snake[i].Kierunek != kierunki[0])
                    {
                        wszystkie = false;
                        break;
                    }
                }
                if (wszystkie)
                    kierunki.RemoveAt(0);
                
            }
            if(kierunki.Count > 0)
            {
                int stop = kierunki.Count();
                int licznik = 0;
                for (int i = 0; i < snake.Count(); i++)
                    if(snake[i].Kierunek != kierunki[0])
                    {
                        snake[i].Kierunek = kierunki[0];
                        break;
                    }
                    else
                    {
                        
                    }
                
            }
            for(int i = 0; i < snake.Count(); i++)
            {
                switch (snake[i].Kierunek)
                {
                    case 1:
                        snake[i].Y -= 0.05;
                        break;
                    case 2:
                        snake[i].Y += 0.05;
                        break;
                    case 3:
                        snake[i].X -= 0.1;
                        break;
                    case 4:
                        snake[i].X += 0.1;
                        break;
                }
                AbsoluteLayout.SetLayoutBounds(snake[i], new Rect(snake[i].X, snake[i].Y, 40, 40));
            }
        }

        public void nowyKierunek(int k)
        {
            bool wpis = false;
            if (snake[0].NastepneKierunki.Count() > 0)
            {
                if (snake[0].NastepneKierunki.Last() != k)
                    wpis = true;
            }
            else if (snake[0].Kierunek != k)
                wpis = true;
            for(int i = 0; i < snake.Count(); i++)
            {
                snake[i].NastepneKierunki.Add(k);
            }
        }

        private void Up_Swiped(object sender, SwipedEventArgs e)
        {
            nowyKierunek(1);
        }
        private void Down_Swiped(object sender, SwipedEventArgs e)
        {
            nowyKierunek(2);
        }
        private void Left_Swiped(object sender, SwipedEventArgs e)
        {
            nowyKierunek(3);
        }
        private void Right_Swiped(object sender, SwipedEventArgs e)
        {
            nowyKierunek(4);
        }
    }
}
