using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Assignment.Shared
{
    public class Email
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int ID { get; set; }
        [Required]
        public string FromEmail { get; set; }
        [Required]
        public string ToEmail { get; set; }
        [Required]
        public string Subject { get; set; }
        [Required]
        public string Body { get; set; }
       
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public DateTime Date { get; set; }
        public string Status { get; set; }
    }
}

