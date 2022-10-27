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
    public partial class CreatePost : ContentPage
    {
        public CreatePost()
        {
            InitializeComponent();
            usersPicker.ItemsSource = UsersItems.List;
        }

        private void button_Clicked(object sender, EventArgs e)
        {
            int id = 0;
            if (PostItems.PostList.Any())
            {
                id = PostItems.PostList.Max(x => x.id);
                id++;
            }
                

            var selectedUser = usersPicker.SelectedIndex;
            UsersItems postingUser = UsersItems.List[selectedUser];
            PostItems.PostList.Add(new PostItems(id, PostText.Text, postingUser));
            PostText.Text = "";
        }
    }
}