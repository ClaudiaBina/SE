namespace ProjectIS.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddSecondName : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.AspNetUsers", "secondName", c => c.String(nullable: false));
        }
        
        public override void Down()
        {
            DropColumn("dbo.AspNetUsers", "secondName");
        }
    }
}
