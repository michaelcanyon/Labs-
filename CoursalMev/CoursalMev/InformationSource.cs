using SQLite;

namespace CoursalMev
{
    class InformationSource
    {
        [PrimaryKey, AutoIncrement, Unique]
        public int Id { get; set; }
        [NotNull, MaxLength(15),Unique]
        public string Type { get; set; }
        public InformationSource(string type)
        {
            Type = type;
        }
        public InformationSource()
        { }
    }
}
