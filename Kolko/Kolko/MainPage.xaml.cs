using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Xamarin.Forms;

namespace Kolko
{
    public partial class MainPage : ContentPage
    {
        int ktoraTura = 0;
        int tura = 0;
        int punktyX = 0;
        int punktyO = 0;
        Button[,] przycisk = new Button[3, 3];
        string ileWin;
        int wygrywaO = 0;
        int wygrywaX = 0;
        public MainPage()
        {
            InitializeComponent();

            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    przycisk[i, j] = new Button
                    {
                        Text = "",
                        FontSize = 20,
                        CornerRadius = 20,
                        BorderWidth = 2,
                        BorderColor = Color.Black,
                    };
                    przycisk[i, j].IsEnabled = true;
                    przycisk[i, j].Clicked += Button_Clicked;
                    Grid.SetColumn(przycisk[i, j], j);
                    Grid.SetRow(przycisk[i, j], i+1);
                    mainGrid.Children.Add(przycisk[i, j]);
                }
            }
            Button reset = new Button
            {
                Text = "RESETUJ",
                FontSize = 25,
                CornerRadius = 20,
                BackgroundColor = Color.Navy,
                TextColor = Color.White,
                VerticalOptions = LayoutOptions.Center,
                
            };
            reset.Clicked += buttonReset;
            Grid.SetColumn(reset, 1);
            Grid.SetRow(reset, 6);
            mainGrid.Children.Add(reset);
            start();
        }

        private async void start()
        {
            ileWin = await DisplayPromptAsync("Zasady", "Do ilu zwycięstw chcesz grać?", initialValue: "3", maxLength: 2, keyboard: Keyboard.Numeric);
        }

        public void Button_Clicked(object sender, EventArgs e)
        {
            ktoraTura++;
            Button button = (Button)sender;
            if(tura == 0)
            {
                button.Text = "X";
                button.IsEnabled = false;
                button.BackgroundColor = Color.FromRgb(4, 138, 40);
                Tura.Text = "Jest Tura O";
                mainGrid.BackgroundColor = Color.FromRgb(4, 138, 40);
                czyWygrana();
                tura = 1;
            }
            else
            {
                button.Text = "O";
                button.IsEnabled = false;
                button.BackgroundColor = Color.FromRgb(125, 3, 3);
                Tura.Text = "Jest Tura X";
                mainGrid.BackgroundColor = Color.FromRgb(145, 3, 3);
                czyWygrana();
                tura = 0;
            }
        }

        public void buttonReset(object sender, EventArgs e)
        {
            mainGrid.BackgroundColor = Color.FromRgb(11, 169, 219);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    przycisk[i, j].Text = "";
                    przycisk[i, j].IsEnabled = true;
                }
            }
            punktyX = 0;
            punktyO = 0;
            ktoraTura = 0;
            tura = 0;
            pX.Text = "" + punktyX;
            pO.Text = "" + punktyO;
            Tura.Text = "Jest Tura X";

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    przycisk[i, j].BackgroundColor = Color.White;
                }
            }
            start();
        }

        public void Restart()
        {
            mainGrid.BackgroundColor = Color.FromRgb(84, 5, 115);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    przycisk[i, j].Text = "";
                    przycisk[i, j].IsEnabled = true;
                    przycisk[i, j].BackgroundColor = Color.White;
                    pX.Text = "" + punktyX;
                    pO.Text = "" + punktyO;
                    ktoraTura = 0;
                    Tura.Text = "Jest Tura X";
                    tura = 0;
                }
            }
        }

        private async void czyWygrana()
        {
            int wygrana = 0;

            if (przycisk[0, 0].Text == "X" && przycisk[0, 1].Text == "X" && przycisk[0, 2].Text == "X") { wygrana = 1; }
            if (przycisk[1, 0].Text == "X" && przycisk[1, 1].Text == "X" && przycisk[1, 2].Text == "X") { wygrana = 1; }
            if (przycisk[2, 0].Text == "X" && przycisk[2, 1].Text == "X" && przycisk[2, 2].Text == "X") { wygrana = 1; }

            if (przycisk[0, 0].Text == "X" && przycisk[1, 0].Text == "X" && przycisk[2, 0].Text == "X") { wygrana = 1; }
            if (przycisk[0, 1].Text == "X" && przycisk[1, 1].Text == "X" && przycisk[2, 1].Text == "X") { wygrana = 1; }
            if (przycisk[0, 2].Text == "X" && przycisk[1, 2].Text == "X" && przycisk[2, 2].Text == "X") { wygrana = 1; }

            if (przycisk[0, 0].Text == "X" && przycisk[1, 1].Text == "X" && przycisk[2, 2].Text == "X") { wygrana = 1; }
            if (przycisk[0, 2].Text == "X" && przycisk[1, 1].Text == "X" && przycisk[2, 0].Text == "X") { wygrana = 1; }


            if (przycisk[0, 0].Text == "O" && przycisk[0, 1].Text == "O" && przycisk[0, 2].Text == "O") { wygrana = 2; }
            if (przycisk[1, 0].Text == "O" && przycisk[1, 1].Text == "O" && przycisk[1, 2].Text == "O") { wygrana = 2; }
            if (przycisk[2, 0].Text == "O" && przycisk[2, 1].Text == "O" && przycisk[2, 2].Text == "O") { wygrana = 2; }

            if (przycisk[0, 0].Text == "O" && przycisk[1, 0].Text == "O" && przycisk[2, 0].Text == "O") { wygrana = 2; }
            if (przycisk[0, 1].Text == "O" && przycisk[1, 1].Text == "O" && przycisk[2, 1].Text == "O") { wygrana = 2; }
            if (przycisk[0, 2].Text == "O" && przycisk[1, 2].Text == "O" && przycisk[2, 2].Text == "O") { wygrana = 2; }

            if (przycisk[0, 0].Text == "O" && przycisk[1, 1].Text == "O" && przycisk[2, 2].Text == "O") { wygrana = 2; }
            if (przycisk[0, 2].Text == "O" && przycisk[1, 1].Text == "O" && przycisk[2, 0].Text == "O") { wygrana = 2; }

            if (ktoraTura == 9 && wygrana == 0) { wygrana = 3; }

            if (wygrana == 1)
            {
                bool answer = await DisplayAlert("Runde wygrywa X", "Czy chcesz grać dalej?", "Tak", "Nie");
                punktyX++;
                wygrywaX++;
                czyDalej(answer);
            }
            if(wygrana == 2)
            {
                bool answer = await DisplayAlert("Runde wygrywa O", "Czy chcesz grać dalej?", "Tak", "Nie");
                punktyO++;
                wygrywaO++;
                czyDalej(answer);
            }
            if (wygrana == 3)
            {
                bool answer = await DisplayAlert("Remis", "Czy chcesz grać dalej?", "Tak", "Nie");
                czyDalej(answer);
            }
        }

        private async void czyDalej(bool ans)
        {
            if (int.Parse(ileWin) == wygrywaX || int.Parse(ileWin) == wygrywaO)
            {
                bool end = true;
                if (wygrywaO > wygrywaX) { end = await DisplayAlert("Grę wygrywa O", "Czy chcesz grać dalej?", "Tak", "Nie"); }
                if (wygrywaO < wygrywaX) { end = await DisplayAlert("Grę wygrywa X", "Czy chcesz grać dalej?", "Tak", "Nie"); }

                if(end == true)
                {
                    punktyX = 0;
                    punktyO = 0;
                    wygrywaO = 0;
                    wygrywaX = 0;
                    Restart();
                    mainGrid.BackgroundColor = Color.Gray;
                    start();
                }
            }
            else
            {
                if (ans == false)
                {
                    punktyX = 0;
                    punktyO = 0;
                }
                Restart();
            }
        }
    }
}
