using PickerPosty.klasy;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace PickerPosty
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class CreateUser : ContentPage
    {
        public CreateUser()
        {
            InitializeComponent();
        }

        private void button_Clicked(object sender, EventArgs e)
        {
            int id = 0;
            if (UsersItems.List.Any())
            {
                id = UsersItems.List.Max(x => x.id);
                id++;
            }

            UsersItems.List.Add(new UsersItems(id, nameEntry.Text, surnameEntry.Text, int.Parse(ageEntry.Text)));
            nameEntry.Text = "";
            surnameEntry.Text = "";
            ageEntry.Text = "";
        }
    }
}