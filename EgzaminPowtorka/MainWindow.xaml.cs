using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
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

namespace EgzaminPowtorka
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ObservableCollection<Person> persons = new ObservableCollection<Person>();

        public MainWindow()
        {
            InitializeComponent();
            dataGrid.ItemsSource = persons;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Window1 dodaj = new Window1();
            dodaj.ShowDialog();
            persons.Add(new Person(dodaj.imieBox.Text, dodaj.nazwiskoBox.Text, int.Parse(dodaj.telefonBox.Text)));
        }



        //private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        //{
        //    e.CanExecute = true;
        //}

        //private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        //{
        //    OpenFileDialog dlg = new OpenFileDialog();
        //    //dlg.Filter = "TXT plik tekstowy(*txt)|*.txt";
        //    if(dlg.ShowDialog() == true)
        //    {
        //        string text = File.ReadAllText(dlg.FileName);
        //        TxtBox.Text = text;
        //    }
        //}

        //private void CommandBinding_Executed_1(object sender, ExecutedRoutedEventArgs e)
        //{
        //    SaveFileDialog dlg = new SaveFileDialog();
        //    if (dlg.ShowDialog() == true)
        //    {
        //        File.WriteAllText(dlg.FileName, TxtBox.Text);
        //    }
        //}
    }
}
