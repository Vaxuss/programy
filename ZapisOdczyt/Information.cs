using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZapisOdczyt
{
    internal class Information
    {
        public string Name { get; set; }
        public string Description { get; set; } 
        public string Email { get; set; }
        public Information() { }

        public Information(string name, string description, string email)
        {
            Name = name;
            Description = description;
            Email = email;
        }   
    }
}
