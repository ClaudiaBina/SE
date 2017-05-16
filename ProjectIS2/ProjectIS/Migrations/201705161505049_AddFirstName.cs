namespace ProjectIS.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddFirstName : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.AspNetUsers", "fullName", c => c.String(nullable: false));
        }
        
        public override void Down()
        {
            DropColumn("dbo.AspNetUsers", "fullName");
        }
    }
}
