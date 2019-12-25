using SQLite;

namespace CoursalMev
{
    class Genre
    {
        [PrimaryKey, AutoIncrement, Unique]
        public int Id { get; set; }
        [NotNull, MaxLength(15),Unique]
        public string pGenre { get; set; }
        public Genre(string genre)
        {
            pGenre = genre;
        }
        public Genre()
        { }
    }
}
