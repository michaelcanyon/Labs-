using SQLite;

namespace CoursalMev
{
    class Author
    {
        [PrimaryKey, AutoIncrement,  Unique]
        public int Id { get; set; }
        [NotNull, MaxLength(20)]
        public string Name { get; set; }
        [NotNull]
        public int Profession_id { get; set; }
        public Author(string name, int profession_id)
        {
            Name = name;
            Profession_id = profession_id;
        }
        public Author()
        { }
    }
}
