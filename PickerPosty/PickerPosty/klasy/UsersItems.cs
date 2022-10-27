using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace PickerPosty.klasy
{
    internal class UsersItems
    {
        public static ObservableCollection<UsersItems> List = new ObservableCollection<UsersItems>();

        public int id { get; set; }
        public string name { get; set; }
        public string surname { get; set; }
        public int age { get; set; }
        public string display_user { get; set; }

        public UsersItems(int id, string name, string surname, int age)
        {
            this.id = id;
            this.name = name;
            this.surname = surname;
            this.age = age;
            display_user = name + " " + surname;
        }
    }
}
