using Microsoft.VisualBasic;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
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

namespace Samochody
{
    public partial class MainWindow : Window
    {
        ObservableCollection<Cars> cars = new ObservableCollection<Cars>();
        public MainWindow()
        {
            cars.Add(new Cars(1, "123", "volvo", "2003", "bialy", 5));

            InitializeComponent();
            dataGrid.ItemsSource = cars;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Cars newCar = new Cars();
            newCar.id = cars.Last().id++;
            newCar.nrRejestracji = nrRejestracji.Text;
            newCar.marka = marka.Text;
            newCar.rokProdukcji = rokProd.Text;
            newCar.kolor = kolor.Text;
            newCar.iloscPasazerow = int.Parse(iloscPasazerow.Text);

            cars.Add(newCar);
            dataGrid.ItemsSource = cars;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            cars.Clear();
            dataGrid.ItemsSource = cars;
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            SaveFileDialog dlg = new SaveFileDialog();
            dlg.Filter = "JSON file (*.json)|*.json";
            if (dlg.ShowDialog() == true)
            {
                File.WriteAllText(dlg.FileName, JsonSerializer.Serialize(cars));
            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "JSON file (*.json)|*.json";
            if (dlg.ShowDialog() == true)
            {
                string json = File.ReadAllText(dlg.FileName);
                cars.Clear();
                cars = JsonSerializer.Deserialize<ObservableCollection<Cars>>(json);
                dataGrid.ItemsSource = cars;
            }
        }
    }
}
