using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Snake
{
    public partial class MainPage : ContentPage
    {
        List<Snake> snake = new List<Snake>();
        List<Apple> apple  = new List<Apple>();
        List<int> kierunki = new List<int>();
        Random rand = new Random();
        int ostatniKierunek = 0;
        int w = 0;
        bool timer = true;
        decimal tempX;
        decimal tempY;
        public MainPage()
        {
            InitializeComponent();
            snake.Add(new Snake(0.5M,0.45M));
            snake.Add(new Snake(0.5M,0.5M));
            snake.Add(new Snake(0.5M,0.55M));


            for(int i=0; i< snake.Count(); i++)
            {
                layout.Children.Add(snake[i]);
                AbsoluteLayout.SetLayoutBounds(snake[i], new Rect((double)snake[i].X, (double)snake[i].Y, 40, 40));
                AbsoluteLayout.SetLayoutFlags(snake[i], AbsoluteLayoutFlags.PositionProportional);
            }

            noweJablko();

            Device.StartTimer(new TimeSpan(0, 0, 0, 0, 350), () =>
            {
                if (timer)
                {
                    Device.BeginInvokeOnMainThread(() =>
                    {
                        if (ostatniKierunek != 0) Ruch();
                        Zjedz();
                    });
                }
                else
                {
                    KoniecGry();
                }
                return timer; // runs again, or false to stop
            });
        }

        public void Zjedz()
        {
            if (snake[0].X == apple[0].X && snake[0].Y == apple[0].Y)
            {
                layout.Children.Remove(apple[0]);
                apple.RemoveAt(0); 
                
                snake.Add(new Snake(tempX, tempY));
                layout.Children.Add(snake.Last());
                
                AbsoluteLayout.SetLayoutBounds(snake.Last(), new Rect((double)snake.Last().X, (double)snake.Last().Y, 40, 40));
                AbsoluteLayout.SetLayoutFlags(snake.Last(), AbsoluteLayoutFlags.PositionProportional);
                
                noweJablko();

                w++;
                Wynik.Text = w.ToString();
            }
            else
            {
                tempX = snake.Last().X;
                tempY = snake.Last().Y;
            }
        }

        public void noweJablko()
        {
            decimal X, Y;
            bool ok;
            do
            {
                ok = true;
                X = rand.Next(10) * 0.1M;
                Y = rand.Next(20) * 0.05M;
                foreach (var snake in snake)
                    if (snake.X == X && snake.Y == Y)
                        ok = false;
            }while (!ok);

            apple.Add(new Apple(X, Y));

            layout.Children.Add(apple[0]);
            AbsoluteLayout.SetLayoutBounds(apple[0], new Rect((double)apple[0].X, (double)apple[0].Y, 40, 40));
            AbsoluteLayout.SetLayoutFlags(apple[0], AbsoluteLayoutFlags.PositionProportional);
        }

        public void Ruch()
        {
            for(int i = snake.Count - 1; i > 0; i--)
            {
                snake[i].X = snake[i - 1].X;
                snake[i].Y = snake[i - 1].Y;
            }
            if(kierunki.Count() > 0)
            {
                ostatniKierunek = kierunki[0];
                kierunki.RemoveAt(0);
            }
            switch (ostatniKierunek)
            {
                case 1:
                    snake[0].Y -= 0.05M;
                    break;
                case 2:
                    snake[0].Y += 0.05M;
                    break;
                case 3:
                    snake[0].X -= 0.1M;
                    break;
                case 4:
                    snake[0].X += 0.1M;
                    break;
            }
            if (snake[0].X >= 0 && snake[0].X <= 1 && snake[0].Y >= 0 && snake[0].Y <= 1)
            {
                for (int i = 1; i < snake.Count(); i++)
                {
                    if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y)
                    {
                        dying();
                        timer = false;
                        break;
                    }
                }
                if (timer)
                {
                    for (int i = 0; i < snake.Count(); i++)
                    {
                        AbsoluteLayout.SetLayoutBounds(snake[i], new Rect((double)snake[i].X, (double)snake[i].Y, 40, 40));
                    }
                } 
            }
            else
            {
                dying();
                timer = false;
            }
                
        }

        public void dying()
        {
            for (int i = 0; i < snake.Count(); i++)
            {
                snake[i].BackgroundColor = Color.Black;
            }
        }

        public void nowyKierunek(int k)
        {
            if (ostatniKierunek == 0) ostatniKierunek = k;
            if(k != ostatniKierunek)
            {
                if (kierunki.Count() > 0)
                {
                    if (kierunki.Last() != k)
                    {
                        kierunki.Add(k);
                    }
                }
                else
                    kierunki.Add(k);
            }
        }

        private void Up_Swiped(object sender, SwipedEventArgs e)
        {
            if(ostatniKierunek != 2)
                nowyKierunek(1);
        }
        private void Down_Swiped(object sender, SwipedEventArgs e)
        {
            if (ostatniKierunek != 1 && ostatniKierunek != 0)
                nowyKierunek(2);
        }
        private void Left_Swiped(object sender, SwipedEventArgs e)
        {
            if (ostatniKierunek != 4)
                nowyKierunek(3);
        }
        private void Right_Swiped(object sender, SwipedEventArgs e)
        {
            if (ostatniKierunek != 3)
                nowyKierunek(4);
        }

        async void KoniecGry()
        {
            bool answer = await DisplayAlert("Koniec Gry!", $"Twój wynik to : {w} punktów. Czy chcesz grać jescze raz?", "TAK", "NIE");
            if (answer) (Application.Current).MainPage = new MainPage();
            else System.Diagnostics.Process.GetCurrentProcess().Kill();
        }
    }
}
