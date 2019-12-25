using SQLite;

namespace CoursalMev
{
    class Source
    {
        [PrimaryKey, AutoIncrement, Unique]
        public int Id { get; set; }
        [NotNull, MaxLength(50),Unique]
        public string Title_site { get; set; }
        public Source(string title_site)
        {
            Title_site = title_site;
        }
        public Source()
        { }
    }
}
