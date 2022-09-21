using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class UserHobbyManager : HobbyEventManager
    {
        public int RunAccount()
        {
            bool running = true;
            while (running)
            {
                Console.Clear();
                Console.WriteLine("Operacje: ");
                Console.WriteLine("1 - Dodaj event");
                Console.WriteLine("2 - Pokaż listę hobby");
                Console.WriteLine("3 - Pokaż listę eventów");
                Console.WriteLine("4 - pokaż uczestników eventu");
                Console.WriteLine("5 - wyloguj");
                int action = int.Parse(Console.ReadLine());
                switch (action)
                {
                    case 1:
                        AddEvent();
                        break;
                    case 2:
                        Console.Clear();
                        ShowHobby();
                        Console.ReadKey();
                        break;
                    case 3:
                        Console.Clear();
                        ShowEvent();
                        Console.ReadKey();
                        break;
                    case 4:
                        Console.Clear();
                        ShowMembersOfEvent();
                        break;
                    case 5:
                        Console.Clear();
                        run();
                        break;
                    default:
                        return RunAccount();
                }
            }
            return 0;
        }
    }
}
