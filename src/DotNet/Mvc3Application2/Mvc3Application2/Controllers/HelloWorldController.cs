using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Mvc3Application2.Controllers
{
    public class HelloWorldController : Controller
    {
        //
        // GET: /HelloWorld/

        public ActionResult Index()
        {
            return View();
        }

        /*public string Index()
        {
            return "This is <b>default</b> values";
        }*/

        public ActionResult Welcome(string name, int value=1)
        {
            ViewBag.Message = "Hello " + name;
            ViewBag.NumTimes = value;
            return View();
        }
    }
}
