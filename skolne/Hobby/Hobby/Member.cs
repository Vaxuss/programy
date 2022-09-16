using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class Member
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        //List<Hobby> MyHobbies = new List<Hobby>();
        public List<Event> AtendedEvents = new List<Event>();

        public Member(string pFirstName, string pLastName)
        {
            FirstName = pFirstName;
            LastName = pLastName;
        }

        public string ShowData()
        {
            return FirstName + " " + LastName;
        }
    }
}
