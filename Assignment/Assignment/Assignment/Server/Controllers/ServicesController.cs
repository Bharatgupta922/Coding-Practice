using Assignment.Server.Models;
using Assignment.Shared;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assignment.Server.Controllers
{
    [Route("[controller]")]
    [ApiController]
    public class ServicesController : ControllerBase
    {
        private readonly ISqlServices sqlServices;

        public ServicesController(ISqlServices sqlServices)
        {
            this.sqlServices = sqlServices;
        }
        [HttpGet]
        //[Route("~/emails")]
        public async Task<IEnumerable<Email>> GetEmails()
        {
                return await sqlServices.GetEmails();   
        }
        //[HttpGet]
        //public async Task<ActionResult> GetSMSs() {
        //    try
        //    {
        //        return Ok(await sqlServices.GetSMSs());
        //    }
        //    catch (Exception)
        //    {

        //        return StatusCode(StatusCodes.Status500InternalServerError, "Error while retrieving SMSs list from database");
        //    }
        //}
        [HttpPost]
        //[Route("~/sendemail")]
        public async Task<ActionResult> SendEmails([FromBody]Email email)
        {
            try
            {

                return Ok(await sqlServices.SendEmail(email));
            }
            catch (Exception ex)
            {

                return StatusCode(StatusCodes.Status500InternalServerError, "Error while sending email");
            }
        }

        //[HttpPost]
        //public async Task<ActionResult> SendSmss() {
        //    try
        //    {

        //        return Ok();
        //    }
        //    catch (Exception)
        //    {

        //        throw;
        //    }
        //}

    }
}
