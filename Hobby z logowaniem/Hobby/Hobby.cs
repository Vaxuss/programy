using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class Hobby
    {
        public string Name { get; set; }
        public List<Event> HobbyEvents = new List<Event>();
        public Hobby(string pName)
        {
            Name = pName;
        }

        public string showData()
        {
            return Name;
        }
    }
}
