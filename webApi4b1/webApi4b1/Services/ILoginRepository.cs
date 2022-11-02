using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace webApi4b1.Services
{
    public interface ILoginRepository
    {
        Task<UserInfo> Login(string username, string password);
    }
}
