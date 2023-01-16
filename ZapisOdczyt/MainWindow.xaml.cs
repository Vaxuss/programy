using Microsoft.Win32;
using System;
using System.Collections.Generic;
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

namespace ZapisOdczyt
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List <Information> list = new List <Information>();    
        public MainWindow()
        {
            list.Add(new Information("Jan", "Wiadomosc od jana", "jan@op.pl"));
            list.Add(new Information("Adam", "Wiadomosc od adama", "adam@op.pl"));
            list.Add(new Information("Tomek", "Wiadomosc od tomka", "tomek@op.pl"));

            InitializeComponent();
            dataGrid.ItemsSource = list;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //zapis do json przez urzytkownika (okienko eksploratora)//
            SaveFileDialog dlg = new SaveFileDialog();
            dlg.Filter = "JSON file (*.json)|*.json";
            if (dlg.ShowDialog() == true)
            {
                File.WriteAllText(dlg.FileName, JsonSerializer.Serialize(list));
            }

            //zapis do json//
            //string fileName = "C:/Users/derybowskia/Desktop/dane.json";
            //string json = JsonSerializer.Serialize(list);
            //File.WriteAllText(fileName, json);

            //zapis przez urzytkownika//

            //SaveFileDialog dlg = new SaveFileDialog();
            //dlg.Filter = "Text file(*.txt)|*.txt";
            //if(dlg.ShowDialog() == true)
            //{
            //    File.WriteAllText(dlg.FileName, txtBox.Text);
            //}

            //automatyczny zpais pliku//

            //FileStream fs = new FileStream("C:/Users/derybowskia/Desktop/linia.txt", FileMode.Create);
            //StreamWriter sw = new StreamWriter(fs);
            //sw.WriteLine(txtBox.Text);
            //sw.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            //odczyt pliku json przez eksplorator//
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "JSON file (*.json)|*.json";
            if (dlg.ShowDialog() == true)
            {
                string json = File.ReadAllText(dlg.FileName);
                list.Clear();
                list = JsonSerializer.Deserialize<List<Information>>(json);
                dataGrid.ItemsSource = list;
            }

            //odczyt jason//

            //if (File.Exists("C:/Users/derybowskia/Desktop/dane.json"))
            //{
            //    string fileName = "C:/Users/derybowskia/Desktop/dane.json";
            //    string json = File.ReadAllText(fileName);

            //    list.Clear();
            //    list = JsonSerializer.Deserialize<List<Information>>(json);
            //    dataGrid.ItemsSource = list;
            //}


            //OpenFileDialog dlg = new OpenFileDialog();
            //dlg.InitialDirectory = "C:\\Users\\derybowskia\\Desktop";
            //dlg.Filter = "Text file(*.txt)|*.txt";
            //if (dlg.ShowDialog() == true)
            //{
            //    readBlock.Text = File.ReadAllText(dlg.FileName);
            //}


            //if (File.Exists("C:/Users/derybowskia/Desktop/linia.txt"))
            //{
            //    //odczyt z pliku automatyczny//

            //    FileStream fs = new FileStream("C:/Users/derybowskia/Desktop/linia.txt", FileMode.Open);
            //    StreamReader sr = new StreamReader(fs);
            //    readBlock.Text = sr.ReadToEnd();

            //    //string linia;
            //    //while ((linia = sr.ReadLine()) != null)
            //    //    //przypisz do czegoś
            //    sr.Close();

            //}
        }
    }
}
