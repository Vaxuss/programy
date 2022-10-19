using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToDoMobline.classes;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace ToDoMobline.pages
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ListDonePage : ContentPage
    {
        JasonSO js = new JasonSO();
        public ListDonePage()
        {
            InitializeComponent();
            EventItem.ListDone = js.OpenEventListDone();
            eventsItemListView.ItemsSource = EventItem.ListDone;
        }

        private void eventsItemListView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            var item = e.SelectedItem as EventItem;
            DisplayAlert(item.Subject, item.Info, "Zamknij");
        }

        private void Return_Clicked(object sender, EventArgs e)
        {
            var item = sender as MenuItem;
            var events = item.CommandParameter as EventItem;
            EventItem.ListDone.Remove(events);

            int id = 0;
            if (EventItem.List.Any())
                id = EventItem.List.Max(x => x.Id);
            id++;
            events.Id = id;

            EventItem.List.Add(events);
            js.SaveEventList();
            js.SaveEventListDone();
        }

        private void Delete_Clicked(object sender, EventArgs e)
        {
            var item = sender as MenuItem;
            var events = item.CommandParameter as EventItem;
            EventItem.ListDone.Remove(events);
            js.SaveEventListDone();
        }
    }
}