using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using webApi4b1.Services;
using Xamarin.Forms;

namespace webApi4b1
{
    public partial class MainPage : ContentPage
    {
        readonly ILoginRepository _loginRepository = new LoginService();
        public MainPage()
        {
            InitializeComponent();
        }

        private async void btnLogin_Clicked(object sender, EventArgs e)
        {
            string userName = txtUserName.Text;
            string password = txtPassword.Text;
            if(userName == null || password == null)
            {
                await DisplayAlert("UWAGA!", "Wpisz login i haslo użytkownika", "OK");
            }
            
            UserInfo userInfo = await _loginRepository.Login(userName, password);
            
            if(userInfo != null)
            {
                await Navigation.PushAsync(new HomePage());
            }
            else
            {
                await DisplayAlert("UWAGA!", "Login i/lub hasło jest niepoprawne", "OK");
            }
        }
    }
}
