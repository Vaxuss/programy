using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace PickerPosty.klasy
{
    internal class PostItems
    {
        public static ObservableCollection<PostItems> PostList = new ObservableCollection<PostItems>();

        public int id { get; set; }
        public string text { get; set; }
        public UsersItems user { get; set; }

        public PostItems(int id, string text, UsersItems user)
        {
            this.id = id;  
            this.text = text;
            this.user = user;
        }
    }
}
