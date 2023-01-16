using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace XamarinPowtorka
{
    public partial class MainPage : ContentPage
    {
        Random rand = new Random();
        public MainPage()
        {
            InitializeComponent();
        }

        private void DragGestureRecognizer_DragStarting(object sender, DragStartingEventArgs e)
        {
            e.Data.Properties.Add("liczba", rand.Next(10).ToString());
        }

        private void DropGestureRecognizer_Drop(object sender, DropEventArgs e)
        {
            var data = e.Data.Properties["liczba"].ToString();
            label.Text = data;
            rect.VerticalOptions = LayoutOptions.End;
        }
    }
}
