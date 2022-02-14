using Assignment.Shared;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using System.Net;
using System.Net.Mail;

namespace Assignment.Server.Models
{
    public class SqlServices : ISqlServices
    {
        private readonly AppDbContext appDbContext;

        public SqlServices(AppDbContext appDbContext)
        {
            this.appDbContext = appDbContext;
        }
        public async Task<Email> SendEmail(Email email)
        {
            try
            {
                MailMessage emailmsg = new MailMessage();
                emailmsg.From = new MailAddress(email.FromEmail);
                emailmsg.To.Add(new MailAddress(email.ToEmail));
                emailmsg.Subject = email.Subject;
                emailmsg.Body = email.Body;
                emailmsg.IsBodyHtml = false;
                SmtpClient smtp = new SmtpClient("smtp.gmail.com", 587);
                smtp.UseDefaultCredentials = false;
                smtp.EnableSsl = true;
                smtp.Credentials = new NetworkCredential("sidharathjain2@gmail.com", "Ypjain@0439");
                smtp.DeliveryMethod = SmtpDeliveryMethod.Network;
                smtp.Send(emailmsg);
                email.Status = "sent";


            }
            catch (Exception e)
            {
                email.Status = "failed";
            }
            await appDbContext.Emails.AddAsync(email);
            await appDbContext.SaveChangesAsync();
            return email;
        }

        public async Task<SMS> SendSMS(SMS sms)
        {
            throw new NotImplementedException();
        }

        public async Task<IEnumerable<Email>> GetEmails()
        {
            var em = await appDbContext.Emails.ToArrayAsync();
            if (em.Count() == 0)
            { em.Prepend(new Email()); }
            return em;
        }

        public async Task<IEnumerable<SMS>> GetSMSs()
        {

            return await appDbContext.SMSs.ToListAsync();
        }
        
    }
}
