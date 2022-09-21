using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class Event
    {
        public string Type { get; set; }
        public string EventName { get; set; }
        public DateTime Date { get; set; }
        public List<Member> Members = new List<Member>();

        public Event(string type, string eventName, DateTime date)
        {
            Type = type;
            EventName = eventName;
            Date = date;
        }

        public string ShowData()
        {
            return EventName + " typu:  " + Type + " o godzienie: " + Date + " z " + Members.Count + " uczestnikami";
        }
    }
}
