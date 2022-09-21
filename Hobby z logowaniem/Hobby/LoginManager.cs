using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class LoginManager : HobbyEventManager
    {
        public void Register(Member m)
        {
            Console.WriteLine("Login: ");
            string newLogin = Console.ReadLine();
            Console.WriteLine("Hasło: ");
            string newPassword = Console.ReadLine();
            m.login = newLogin;
            m.password = newPassword;
            m.accountType = 0;
        }

        public int Login(string login, string password)
        {
            int wynik = 0;
            for(int i = 0; i < UserList.Count; i++)
            {
                if (UserList[i].login == login && UserList[i].password == password)
                {
                    wynik = i;
                    return wynik;
                }
            }
            Console.WriteLine("Zły login lub hasło");
            return run(); 
        }
    }
}
