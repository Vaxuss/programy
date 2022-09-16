using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hobby
{
    internal class HobbyEventManager
    {
        List<Hobby> HobbyList = new List<Hobby>();
        List<Event> EventList = new List<Event>();
        List<Member> UserList = new List<Member>();
        public void run()
        {
            bool running = true;
            while (running)
            {
                Console.Clear();
                Console.WriteLine("\nOperacje: ");
                Console.WriteLine("1 - Dodaj Użytkownika");
                Console.WriteLine("2 - Dodaj hobby");
                Console.WriteLine("3 - Dodaj event");
                Console.WriteLine("4 - Pokaż listę użytkowników");
                Console.WriteLine("5 - Pokaż listę hobby");
                Console.WriteLine("6 - Pokaż listę eventów");
                Console.WriteLine("7 - Dodaj użytkownika do eventu");
                Console.WriteLine("8 - pokaż uczestników eventu");
                int action = int.Parse(Console.ReadLine());
                switch (action)
                {
                    case 1:
                        AddUser();
                        break;
                    case 2:
                        AddHobby();
                        break;
                    case 3:
                        AddEvent();
                        break;
                    case 4:
                        Console.Clear();
                        ShowUsers();
                        Console.ReadKey();
                        break;
                    case 5:
                        Console.Clear();
                        ShowHobby();
                        Console.ReadKey();
                        break;
                    case 6:
                        Console.Clear();
                        ShowEvent();
                        Console.ReadKey();
                        break;
                    case 7:
                        Console.Clear();
                        AddMemberToEvent();
                        break;
                    case 8:
                        Console.Clear();
                        ShowMembersOfEvent();
                        break;
                }
            }
        }
        public void AddUser()
        {
            Console.Clear();
            Console.WriteLine("Proszę podać");
            Console.WriteLine("Imię: ");
            string name = Console.ReadLine();
            Console.WriteLine("Nazwisko: ");
            string surname = Console.ReadLine();
            Member member = new Member(name, surname);
            UserList.Add(member);
        }
        public void AddHobby()
        {
            Console.Clear();
            Console.WriteLine("Proszę podać");
            Console.WriteLine("Nawę hobby: ");
            string name = Console.ReadLine();
            Hobby hobby = new Hobby(name);
            HobbyList.Add(hobby);
        }
        public void AddEvent()
        {
            Console.Clear();
            if (HobbyList.Count != 0)
            {
                Console.WriteLine("Proszę podać");
                Console.WriteLine("Nawę Eventu: ");
                string name = Console.ReadLine();
                Console.WriteLine("Typ Eventu z list(wpisz cyfre przy rodzaju by wybrać): ");
                ShowHobby();
                int type = int.Parse(Console.ReadLine());
                string hobbyName = "";
                for (int i = 0; i < HobbyList.Count; i++)
                {
                    if (type - 1 == i)
                    {
                        hobbyName = HobbyList[i].Name;
                        Console.WriteLine("Datę Eventu w formie (dzien/miesiąc/rok): ");
                        DateTime data = Convert.ToDateTime(Console.ReadLine());
                        Event newEvent = new Event(hobbyName, name, data);
                        HobbyList[i].HobbyEvents.Add(newEvent);
                        EventList.Add(newEvent);
                        break;
                    }
                }
            }
            else
            {
                Console.WriteLine("Musisz najpierw dodać hobby");
                Console.ReadKey();
            }

        }
        public void ShowUsers()
        {
            for (int i = 0; i < UserList.Count; i++)
            {
                Console.WriteLine(i + 1 + " - " + UserList[i].ShowData());
                if (UserList[i].AtendedEvents.Count != 0)
                {
                    Console.WriteLine("Uczęszcza na: ");
                    for (int j = 0; j < UserList[i].AtendedEvents.Count; j++)
                    {
                        Console.WriteLine("- " + UserList[i].AtendedEvents[j].EventName);
                    }
                }
            }
        }
        public void ShowHobby()
        {
            for (int i = 0; i < HobbyList.Count; i++)
            {
                Console.WriteLine(i + 1 + " - " + HobbyList[i].showData());
                if (HobbyList[i].HobbyEvents.Count != 0)
                {
                    Console.WriteLine("Eventy związane z hobby: ");
                    for (int j = 0; j < HobbyList[i].HobbyEvents.Count; j++)
                    {
                        Console.WriteLine("- " + HobbyList[i].HobbyEvents[j].EventName);
                    }
                }
            }
        }
        public void ShowEvent()
        {
            for (int i = 0; i < EventList.Count; i++)
            {
                Console.WriteLine(i + 1 + " - " + EventList[i].ShowData());
            }
        }
        public void AddMemberToEvent()
        {
            Console.WriteLine("Wybierz do jakiego eventu chesz dołączyć (wpisz liczbe): ");
            ShowEvent();
            int eventID = int.Parse(Console.ReadLine()) - 1;
            Console.WriteLine("Wybierz do jakiego użytkownika chesz dołączyć do tego eventu (wpisz liczbe): ");
            ShowUsers();
            int memberID = int.Parse(Console.ReadLine()) - 1;
            bool badInput = false;
            for (int i = 0; i < EventList.Count; i++)
            {
                if (eventID == i)
                {
                    for (int j = 0; j < EventList[i].Members.Count; j++)
                    {
                        if (UserList[memberID].FirstName == EventList[i].Members[j].FirstName && UserList[memberID].LastName == EventList[i].Members[j].LastName)
                        {
                            Console.WriteLine("Użytkownik już jest wpisany.");
                            Console.WriteLine("Kliknij cokolwiek by kontynuować");
                            Console.ReadKey();
                            badInput = true;
                            break;
                        }
                    }
                    if (badInput == false)
                    {
                        Console.WriteLine("Użytkownik został dodany");
                        EventList[i].Members.Add(UserList[memberID]);
                        UserList[memberID].AtendedEvents.Add(EventList[i]);
                        Console.WriteLine("Kliknij cokolwiek by kontynuować");
                        Console.ReadKey();
                        break;
                    }
                }
            }
        }
        public void ShowMembersOfEvent()
        {
            Console.WriteLine("Wybierz do jakiego eventu chesz dołączyć (wpisz liczbe): ");
            ShowEvent();
            int eventID = int.Parse(Console.ReadLine()) - 1;
            for (int i = 0; i < EventList[eventID].Members.Count; i++)
            {
                Console.WriteLine(i + 1 + " - " + EventList[eventID].Members[i].FirstName + " " + EventList[eventID].Members[i].LastName);
            }
            Console.WriteLine("Kliknij cokolwiek by kontynuować");
            Console.ReadKey();
        }
    }
}
