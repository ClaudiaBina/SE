using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(ProjectIS.Startup))]
namespace ProjectIS
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
