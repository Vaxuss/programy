using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDo
{
    internal class Program
    {
        static void Main()
        {
            TaskManager manager = new TaskManager();
            manager.start();
        }
    }
}
