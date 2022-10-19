using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using Newtonsoft.Json;
using System.IO;

namespace ToDoMobline.classes
{
    internal class JasonSO
    {

        public JasonSO() { }
        public void SaveEventList()
        {
            var json = JsonConvert.SerializeObject(EventItem.List);
            File.WriteAllText(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList.txt"), json);
        }
        public void SaveEventListDone()
        {
            var json = JsonConvert.SerializeObject(EventItem.ListDone);
            File.WriteAllText(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList_.txt"), json);
        }
        public ObservableCollection<EventItem> OpenEventList()
        {
            var backingFile = Path.Combine(System.Environment.GetFolderPath(System.Environment.SpecialFolder.LocalApplicationData), "ToDoList.txt");
            if (File.Exists(backingFile))
                return JsonConvert.DeserializeObject<ObservableCollection<EventItem>>(File.ReadAllText(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList.txt")));
            else return new ObservableCollection<EventItem>();
        }
        public ObservableCollection<EventItem> OpenEventListDone()
        {
            var backingFile = Path.Combine(System.Environment.GetFolderPath(System.Environment.SpecialFolder.LocalApplicationData), "ToDoList_.txt");
            if (File.Exists(backingFile))
                return JsonConvert.DeserializeObject<ObservableCollection<EventItem>>(File.ReadAllText(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "ToDoList_.txt")));
            else return new ObservableCollection<EventItem>();
        }
    }
}
