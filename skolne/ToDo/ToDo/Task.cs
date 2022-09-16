using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDo
{
    internal class Task
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public string Deadline { get; set; }
        public bool Done { get; set; }
        public Task(string pName, bool pDone)
        {
            Name = pName;
            Description = "brak";
            Deadline = "brak";
            Done = pDone;
        }
        public Task(string pName)
        {
            Name = pName;
            Description = "brak";
            Deadline = "brak";
            Done = false;
        }

        public void showData()
        {
            Console.WriteLine("Nazwa zadania: " + Name);
            Console.WriteLine("Opis zadania: " + Description);
            Console.WriteLine("termin zadania: " + Deadline);
            if (!Done)
            {
                Console.WriteLine("Zadanie nie ukończone");
            }
            else Console.WriteLine("Zadanie ukończone");
        }
    }
}
