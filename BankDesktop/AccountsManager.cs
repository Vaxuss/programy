﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankDesktop
{
    internal class AccountsManager
    {
        private IList<Account> _accounts;
        public AccountsManager()
        {
            _accounts = new List<Account>();
        }
        public IEnumerable<Account> GetAllAccounts()
        {
            return _accounts;
        }
        private int generateId()
        {
            int id = 1;
            if (_accounts.Any())
            {
                id = _accounts.Max(a => a.Id) + 1;
            }
            return id;
        }
        public SavingAccount CreateSavingsAccount(string firstName, string lastName, long pesel)
        {
            int id = generateId();
            SavingAccount account = new SavingAccount(id, 0.0M, firstName, lastName, pesel);
            _accounts.Add(account);
            return account;
        }
        public BillingAccount CreateBillingsAccount(string firstName, string lastName, long pesel)
        {
            int id = generateId();
            BillingAccount account = new BillingAccount(id, 0.0M, firstName, lastName, pesel);
            _accounts.Add(account);
            return account;
        }
        public IEnumerable<Account> GetAllAccountFor(long pesel)
        {
            //IList<Account> customers = new List<Account>();
            //foreach(Account account in _accounts)
            //    if(account.Pesel == pesel)
            //        customers.Add(account);
            //return customers;
            return _accounts.Where(a => a.Pesel == pesel);
        }
        public Account GetAccount(string accountNo)
        {
            return _accounts.Single(x => x.AccountNumber == accountNo);
        }
        public IEnumerable<string> ListOfCustomers()
        {
            return _accounts.Select(a => string.Format("Imię: {0} | Nazwisko: {1} | Pesel: {2}", a.FirstName, a.LastName, a.Pesel)).Distinct();
        }
        public void CloseMonth(decimal saving, decimal billing)
        {
            foreach (SavingAccount account in _accounts.Where(x => x is SavingAccount))
                account.AddInterest(saving);
            foreach (BillingAccount account in _accounts.Where(x => x is BillingAccount))
                account.TakeCharge(billing);
        }
        public void AddMoney(string accountNo, decimal value)
        {
            Account account = GetAccount(accountNo);
            account.ChangeBalance(value);
        }
        public void TakeMoney(string accountNo, decimal value)
        {
            Account account = GetAccount(accountNo);
            account.ChangeBalance(-value);
        }
    }
}
