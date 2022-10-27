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
    public partial class UserData : ContentPage
    {
        public UserData()
        {
            InitializeComponent();
            usersPicker.ItemsSource = UsersItems.List;
        }

        private void users_SelectedIndexChanged(object sender, EventArgs e)
        {
            var selectedUser = usersPicker.SelectedIndex;
            displayName.Text = UsersItems.List[selectedUser].name;
            displaySurname.Text = UsersItems.List[selectedUser].surname;
            int postNumber = 0;
            for(int i = 0; i < PostItems.PostList.Count; i++)
            {
                if (PostItems.PostList[i].user.id == selectedUser)
                {
                    postNumber++;
                }
            }
            displayPosts.Text = postNumber.ToString();
        }
    }
}