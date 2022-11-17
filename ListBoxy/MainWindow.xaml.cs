using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
using System.ComponentModel;

namespace ListBoxy
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ObservableCollection<PersonData> list = new ObservableCollection<PersonData>();
        public MainWindow()
        {
            InitializeComponent();
            list.Add(new PersonData("Marek", 55, "amarek@gmail.com"));
            list.Add(new PersonData("Wiola", 25, "wiola@gmail.com"));
            list.Add(new PersonData("Arek", 27, "barek@gmail.com"));
            list.Add(new PersonData("Piotr", 18, "piotr@gmail.com"));
            ListaImion.ItemsSource = list;
        }

        private void ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            //MessageBox.Show(ListaImion.SelectedIndex.ToString());
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            AddToList okno = new AddToList();
            okno.ShowDialog();
            list.Add(new PersonData(okno.NameToAdd.Text, int.Parse(okno.AgeToAdd.Text), okno.EmailToAdd.Text));
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            PersonData selectedNameIndex = ListaImion.SelectedItem as PersonData;
            if (selectedNameIndex != null)
            {
                list.Remove(selectedNameIndex);
            }
        }

        private void GridViewColumnHeader_Click(object sender, RoutedEventArgs e)
        {
            GridViewColumnHeader header = (sender as GridViewColumnHeader);
            string columnNameToSort = header.Content.ToString();

            CollectionView view = (CollectionView)CollectionViewSource.GetDefaultView(ListaImion.ItemsSource);
            ListSortDirection howToSort = ListSortDirection.Ascending;

            if (view.SortDescriptions.Any())
            {
                SortDescription item = view.SortDescriptions.ElementAt(0);
                if(columnNameToSort == item.PropertyName.ToString())
                    if(item.Direction == ListSortDirection.Ascending)
                        howToSort = ListSortDirection.Descending;
                    else
                        howToSort = ListSortDirection.Ascending;
            }

            view.SortDescriptions.Clear();
            view.SortDescriptions.Add(new SortDescription(columnNameToSort, howToSort));
        }
    }
}
