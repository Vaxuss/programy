using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SaperWPF
{
    public partial class MainWindow : Window
    {
        Buttons[,] btn = new Buttons[10, 10];
        Random rand = new Random();
        int Flaga = 15, iloscRochow;
        bool Pierwszy = false;

        public MainWindow()
        {
            InitializeComponent();
            iloscRochow = 100 - Flaga;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    btn[i,j] = new Buttons();
                    plansza.Children.Add(btn[i,j]);
                    Grid.SetRow(btn[i, j], i);
                    Grid.SetColumn(btn[i, j], j);
                    btn[i, j].Click += Left_Click;
                    btn[i,j].MouseRightButtonDown += Right_Click;
                }
            }

           
            //for(int i = 0; i < 10; i++)
            //{
            //    for(int j =0; j < 10; j++)
            //    {
            //        btn[i, j].Content = btn[i, j].wartosc.ToString();
            //    }
            //}
        }

        private bool RozstawBomby(int xx, int yy)
        {
            for (int i = xx - 1; i <= xx + 1; i++)
                for (int j = yy - 1; j <= yy + 1; j++)
                    if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
                    {
                        btn[i, j].wartosc = 100;
                    }

            int licznik = 0;
            while (licznik < Flaga)
            {
                int x = rand.Next(10);
                int y = rand.Next(10);

                if (btn[x, y].wartosc < 10)
                {
                    licznik++;
                    btn[x, y].wartosc = 10;
                    for (int i = x - 1; i <= x + 1; i++)
                    {
                        for (int j = y - 1; j <= y + 1; j++)
                        {
                            if (i >= 0 && i <= 9 && j >= 0 && j <= 9 && btn[i, j].wartosc != 10)
                            {
                                btn[i, j].wartosc++;
                            }
                        }
                    }
                }
            }

            for (int i = xx - 1; i <= xx + 1; i++)
                for (int j = yy - 1; j <= yy + 1; j++)
                    if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
                    {
                        btn[i, j].wartosc -= 100;
                    }

            return true;
        }


        private void Left_Click(object sender, RoutedEventArgs e)
        {
            int y = Grid.GetColumn((Buttons)sender);
            int x = Grid.GetRow((Buttons)sender);
            if (!Pierwszy)
            {
                Pierwszy = RozstawBomby(x, y);
            }
            if (btn[x,y].flaga == false)
                Odkryj(x, y);
            if(iloscRochow == 0) odkryjPlansze(true);
        }

        private void Odkryj(int x, int y)
        {
            btn[x, y].Content = btn[x, y].wartosc.ToString();
            btn[x, y].odkryte = true;
            btn[x, y].IsEnabled = false;
            iloscRochow--;
            if (btn[x, y].flaga)
            {
                btn[x,y].flaga = false;
                Flaga++;
            }    

            if (btn[x, y].wartosc == 0)
            {
                for (int i = x - 1; i <= x + 1; i++)
                    for (int j = y - 1; j <= y + 1; j++)
                        if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
                        {
                            if (!btn[i, j].odkryte)
                            {
                                if (btn[i, j].wartosc == 0) Odkryj(i, j);
                                else
                                {
                                    btn[i, j].Content = btn[i, j].wartosc.ToString();
                                    btn[i, j].odkryte = true;
                                    btn[i, j].IsEnabled = false;
                                    iloscRochow--;
                                    if (btn[i, j].flaga)
                                    {
                                        btn[i, j].flaga = false;
                                        Flaga++;
                                    }
                                }
                            }
                        }
            }
            if (btn[x, y].wartosc == 10)
                odkryjPlansze(false);           
        }

        private void Right_Click(object sender, RoutedEventArgs e)
        {
            int y = Grid.GetColumn((Buttons)sender);
            int x = Grid.GetRow((Buttons)sender);
            if (btn[x, y].flaga == false)
            {
                if (Flaga > 0)
                {
                    btn[x,y].flaga = true;
                    btn[x, y].Content = "🚩";
                    Flaga--;
                }
            }
            else
            {
                btn[x, y].flaga = false;
                btn[x, y].Content = "";
                Flaga++;
            }
        }

        private void odkryjPlansze(bool wygrana)
        {
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                {
                    btn[i, j].IsEnabled = false;
                    if (btn[i, j].wartosc == 10)
                    {
                        if (btn[i, j].flaga) btn[i, j].Content = "🚩";
                        else btn[i, j].Content = "💣";
                    }  
                    else btn[i, j].Content = btn[i, j].wartosc.ToString();
                    
                }
            if (wygrana)
            {
                MessageBox.Show("Wygrana");
            }
            else MessageBox.Show("Przegrana");
        }
    }
}
