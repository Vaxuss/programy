using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Xamarin.Forms;

namespace Aplikacja_Mobilna
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
            komunikat.Text = "Autor 12345678910";
        }


        /*
           * Nazwa funkcji : Zatwierdz_Clicked
           * parametry wejściowe: sender - Obiekt przesyłający funkcje
           * wartowsc zwracana: wyświetla komunikaty w przestrzeni komunikatów
           * Autor 12345678910
           */
        private async void Zatwierdz_Clicked(object sender, EventArgs e)
        {
            
            string haslo = hasloEntry.Text;
            string hasloPowtorzone = hasloPowtorzEntry.Text;
            string email = emailEntry.Text;

            if (EmailCheck())
            {
                if (haslo == hasloPowtorzone)
                {
                    komunikat.Text = "Witaj " + email;
                }
                else
                {
                    komunikat.Text = "Hasła róznią się";
                    Reset();
                }
            }
            else
            {
                komunikat.Text = "Nieprawidłowy adres e-mail";
                Reset();
            }
        }
        /*
           * Nazwa funkcji : EmailCheck
           * parametry wejściowe: brak
           * wartowsc zwracana: nic nie zwraca, sprawdza czy podany email jest poprawnie napisany
           * Autor 12345678910
           */
        bool EmailCheck()
        {
            string email = emailEntry.Text;
            bool emailPoprawny = false;

            for (int i = 0; i < email.Length; i++)
            {
                if (email[i] == '@')
                {
                    emailPoprawny = true;
                }
            }
            return emailPoprawny;
        }

        void Reset()
        {
            hasloEntry.Text = "";
            hasloPowtorzEntry.Text = "";
            emailEntry.Text = "";
        }

        
    }
}
