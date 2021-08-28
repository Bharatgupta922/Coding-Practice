using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment.Shared
{
    public  class SMS
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int ID { get; set; }
        [Required]
        public string FromNumber { get; set; }
        [Required]
        public string ToNumber { get; set; }
        [Required]
        public string Message { get; set; }
        
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public DateTime Date { get; set; }
        public string SenderId { get; set; }
        public string Status { get; set; }
    }
}
