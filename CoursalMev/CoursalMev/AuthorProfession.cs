using SQLite;

namespace CoursalMev
{
    class AuthorProfession
    {
        [PrimaryKey, AutoIncrement, Unique]
        public int Id { get; set; }
        [NotNull, MaxLength(20),Unique]
        public string ProfessionTitle { get; set; }
        public AuthorProfession(string professionTitle)
        {
            ProfessionTitle = professionTitle;
        }
        public AuthorProfession()
        { }
    }
}
