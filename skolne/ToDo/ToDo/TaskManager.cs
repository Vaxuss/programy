using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDo
{
    internal class TaskManager
    {
        List<Task> ActiveTasks = new List<Task>();
        List<Task> FinishedTasks = new List<Task>();
        public void start()
        {
            bool running = true;
            while (running)
            {
                Order();
                Console.Clear();
                Console.WriteLine("Aktywne Zadania: ");
                ShowActiveTasks();
                Console.WriteLine("\nOperacje: ");
                Console.WriteLine("1 - Dodaj zadanie");
                Console.WriteLine("2 - Ukończ zadanie");
                Console.WriteLine("3 - Edytuj aktywne zadanie");
                Console.WriteLine("4 - Usuń zadanie");
                Console.WriteLine("5 - Pokaż ukończone zadania");
                Console.WriteLine("6 - Cofnij ukończone zadanie");
                int action = int.Parse(Console.ReadLine());
                switch (action) 
                {
                    case 1:
                        AddTask();
                        break;
                    case 2:
                        FinishTask();
                        break;
                    case 3:
                        EditTask();
                        break;
                    case 4:
                        DeleteTask();
                        break;
                    case 5:
                        ShowFinishedTasks();
                        Console.WriteLine("Naciśnij cokolwiek by wrócić do menu");
                        Console.ReadKey();
                        break;
                    case 6:
                        ReturnToActive();
                        break;
                }

            }
        }

        public void AddTask()
        {
            Console.Clear();
            Console.WriteLine("Prosze podać nazwę zadania: ");
            string newTask = Console.ReadLine();
            Task task = new Task(newTask);
            ActiveTasks.Add(task);
            
            
        }

        public void FinishTask()
        {
            Console.Clear();
            Console.WriteLine("Prosze podać nazwę zadania które chcesz ukończyć: ");
            int task = int.Parse(Console.ReadLine());
            for (int i = 0; i < ActiveTasks.Count; i++)
            {
                if(task - 1 == i)
                {
                    FinishedTasks.Add(ActiveTasks[i]);
                    ActiveTasks.RemoveAt(i);
                }
            }
        }

        public void ShowActiveTasks()
        {
            for(int i = 0; i < ActiveTasks.Count; i++)
            {
                Console.WriteLine(i+1 + ": " + ActiveTasks[i].Name);
            }
        }

        public void ShowFinishedTasks()
        {
            Console.Clear();
            Console.WriteLine("Zadania Ukończone: ");
            for (int i = 0; i < FinishedTasks.Count; i++)
            {
                Console.WriteLine(i+1 + ": " + FinishedTasks[i].Name); 
            }
        }
        public void EditTask()
        {
            Console.Clear();
            ShowActiveTasks();
            Console.WriteLine("\nProsze podać numer zadania które chcesz edytować: ");
            int task = int.Parse(Console.ReadLine());
            for (int i = 0; i < ActiveTasks.Count; i++)
            {
                if (task - 1 == i)
                {
                    ActiveTasks[i].showData();
                    Console.WriteLine("\nNowa nazwa zadania: ");
                    string newName = Console.ReadLine();
                    Console.WriteLine("Nowy opis zadania: ");
                    string newDes = Console.ReadLine();
                    Console.WriteLine("Nowy termin zadania: ");
                    string newDead = Console.ReadLine();
                    Console.WriteLine("Czy zadanie ukończone? [1] - TAK ; [2] - NIE: ");
                    int action = int.Parse(Console.ReadLine());
                    if(action == 1) ActiveTasks[i].Done = true;
                    if(action == 2) ActiveTasks[i].Done = false;
                    ActiveTasks[i].Name = newName;
                    ActiveTasks[i].Description = newDes;
                    ActiveTasks[i].Deadline = newDead;

                }
            }
        }

        public void DeleteTask()
        {
            Console.Clear();
            ShowActiveTasks();
            Console.WriteLine("Prosze podać numer zadania które chcesz usunąć: ");
            int task = int.Parse(Console.ReadLine());
            for (int i = 0; i < ActiveTasks.Count; i++)
            {
                if (task - 1 == i)
                {
                    ActiveTasks.RemoveAt(i);
                }
            }
        }

        public void Order()
        {
            for (int i = 0; i < ActiveTasks.Count; i++)
            {
                if(ActiveTasks[i].Done == true)
                {
                    FinishedTasks.Add(ActiveTasks[i]);
                    ActiveTasks.RemoveAt(i);
                }
            }
        }

        public void ReturnToActive()
        {
            Console.Clear();
            ShowFinishedTasks();
            Console.WriteLine("Prosze podać numer zadania które chcesz cofnąć: ");
            int task = int.Parse(Console.ReadLine());
            for (int i = 0; i < FinishedTasks.Count; i++)
            {
                if (task - 1 == i)
                {
                    ActiveTasks.Add(FinishedTasks[i]);
                    FinishedTasks.RemoveAt(i);
                }
            }
        }
    }
}
