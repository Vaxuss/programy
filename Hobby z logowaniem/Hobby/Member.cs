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
        public string login { get; set; }
        public string password { get; set; }
        public int accountType { get; set; }

        public Member(string pFirstName, string pLastName)
        {
            FirstName = pFirstName;
            LastName = pLastName;
        }

        public Member(string pFirstName, string pLastName, string pLogin, string pPassword, int pAccountType)
        {
            FirstName = pFirstName;
            LastName = pLastName;
            login = pLogin;
            password = pPassword;
            accountType = pAccountType;
        }

        public string ShowData()
        {
            return FirstName + " " + LastName;
        }
    }
}
