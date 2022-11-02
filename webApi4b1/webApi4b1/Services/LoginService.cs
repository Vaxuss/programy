using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace webApi4b1.Services
{
    public class LoginService : ILoginRepository
    {
        public async Task<UserInfo> Login(string username, string password)
        {
            var userInfo = new List<UserInfo>(); 
            var client = new HttpClient();
            string url = "http://10.0.0.187/Artur_Derybowski_4B/?user=" + username + "&pass=" + password;

            client.BaseAddress = new Uri(url);
            HttpResponseMessage response = await client.GetAsync("");

            if (response.IsSuccessStatusCode)
            {
                string content = response.Content.ReadAsStringAsync().Result;
                userInfo = JsonConvert.DeserializeObject<List<UserInfo>>(content);
                return await Task.FromResult(userInfo.FirstOrDefault());
            }
            else { return null; }
        }
    }
}
