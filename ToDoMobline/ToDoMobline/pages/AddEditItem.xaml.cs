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
    public partial class AddEditItem : ContentPage
    {
        JasonSO js = new JasonSO();
        public AddEditItem(int id)
        {
            InitializeComponent();
            if (id == 0)
                AddEditPage.Title = "Dodaj nową pozycje od listy";
            else
            {
                AddEditPage.Title = "Edytuj pozycje z listy";
                EventItem item = EventItem.List.Single(x => x.Id == id);
                hiddenId.Text = id.ToString();
                subjectEntry.Text = item.Subject;
                infoEditor.Text = item.Info;
            }

        }

        private async void button_Clicked(object sender, EventArgs e)
        {
            int id = 0;
            if (hiddenId.Text != "")
            {
                EventItem item = EventItem.List.Single(x => x.Id == int.Parse(hiddenId.Text));
                id = item.Id;
                EventItem.List.Remove(item);
            }
            if (id == 0)
            {
                if (EventItem.List.Any())
                    id = EventItem.List.Max(x => x.Id);
                id++;
            }

            EventItem.List.Add(new EventItem(id, subjectEntry.Text, infoEditor.Text));
            js.SaveEventList();
            await Navigation.PopAsync();
        }
    }
}