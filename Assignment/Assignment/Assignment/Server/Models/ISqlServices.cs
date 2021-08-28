using Assignment.Shared;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assignment.Server.Models
{
    public interface ISqlServices
    {
        public Task<IEnumerable<Email>> GetEmails();
        public Task<IEnumerable<SMS>> GetSMSs();
        public Task<Email> SendEmail(Email email);
        public Task<SMS> SendSMS(SMS sms);

    }
}
