using System;
using System.Collections.Generic;
using System.Linq;
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

namespace BankDesktop
{
    public partial class MainWindow : Window
    {
        AccountsManager _accountsManager = new AccountsManager();
        public MainWindow()
        {
            InitializeComponent();
            _accountsManager.CreateBillingsAccount("Jan", "Kowalski", 12345678910);
            _accountsManager.CreateSavingsAccount("Jan", "Kowalski", 12345678910);
            _accountsManager.CreateBillingsAccount("Adam", "Nowak", 124);

            ListaBanku.ItemsSource = _accountsManager.GetAllAccounts();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            PeselWindow peselWindow = new PeselWindow();
            peselWindow.ShowDialog();

            if (peselWindow.PeselTextBox.Text != null && peselWindow.PeselTextBox.Text != "")
            {
                if (long.TryParse(peselWindow.PeselTextBox.Text, out long Pesel))
                {
                    ListaBanku.ItemsSource = _accountsManager.GetAllAccountFor(Pesel);
                }
                else MessageBox.Show("Nieprawidłowy numer Pesel");
            }
            else
                MessageBox.Show("Nieprawidłowe dane");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            AddAccountWindow addAccountWindow = new AddAccountWindow();
            addAccountWindow.ShowDialog();
            if (addAccountWindow.ImieTextBox.Text != "" || addAccountWindow.NazwiskoTextBox.Text != "" || 
                addAccountWindow.PeselTextBox.Text != "" && addAccountWindow.PeselTextBox.Text != null)
            {
                if(long.TryParse(addAccountWindow.PeselTextBox.Text, out long Pesel))
                {
                    if (addAccountWindow.RodzajKonta.Text == "Rozliczeniowe")
                    {
                        _accountsManager.CreateBillingsAccount(addAccountWindow.ImieTextBox.Text, addAccountWindow.NazwiskoTextBox.Text, Pesel);
                    }
                    else
                    {
                        _accountsManager.CreateSavingsAccount(addAccountWindow.ImieTextBox.Text, addAccountWindow.NazwiskoTextBox.Text, Pesel);
                    }
                    ListaBanku.ItemsSource = _accountsManager.GetAllAccountFor(long.Parse(addAccountWindow.PeselTextBox.Text));
                }
                else
                    MessageBox.Show("Nie podano odpowiednich danych");
            }
            else 
                MessageBox.Show("Nie podano odpowiednich danych");
            
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            BalanceWindow balanceWindow = new BalanceWindow();
            balanceWindow.ShowDialog();

            Account klient = (Account)ListaBanku.SelectedItem;
            if(balanceWindow.KwotaTextBox.Text != "" && balanceWindow.KwotaTextBox.Text != null)
            {
                if (balanceWindow.Rodzaj.Text == "Wpłać")
                {
                    _accountsManager.AddMoney(klient.AccountNumber, decimal.Parse(balanceWindow.KwotaTextBox.Text));
                }
                else
                {
                    _accountsManager.TakeMoney(klient.AccountNumber, decimal.Parse(balanceWindow.KwotaTextBox.Text));
                }
                ListaBanku.ItemsSource = _accountsManager.GetAllAccountFor(klient.Pesel);
            }
            else
                MessageBox.Show("Wpisz kwote");

        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            ListaBanku.ItemsSource = _accountsManager.GetAllAccounts();
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            CloseMonthWindow closeMonth = new CloseMonthWindow();
            closeMonth.ShowDialog();
            if(closeMonth.KwotaTextBox.Text != "" || closeMonth.ProcentTextBox.Text != "")
            {
                if(decimal.TryParse(closeMonth.ProcentTextBox.Text, out decimal Procent)
                    && decimal.TryParse(closeMonth.KwotaTextBox.Text, out decimal Kwota))
                {
                    _accountsManager.CloseMonth(Procent * 0.01M, Kwota);
                    ListaBanku.ItemsSource = _accountsManager.GetAllAccounts();
                }
                else
                    MessageBox.Show("Podaj wszystkie dane poprawnie");
            }
            else
                MessageBox.Show("Podaj wszystkie dane poprawnie");

        }
    }
}
