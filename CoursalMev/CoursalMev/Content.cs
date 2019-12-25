using SQLite;

namespace CoursalMev
{
    class Content
    {
        [PrimaryKey, AutoIncrement, Unique]
        public int Id { get; set; }
        [MaxLength(30), NotNull]
        public string Title { get; set; }
        [NotNull]
        public int InformationSource_id { get; set; }
        [NotNull, MaxLength(40)]
        public string Source { get; set; }
        [NotNull,Unique]
        public string Date { get; set; }
        [NotNull]
        public int Genre_id { get; set; }
        [NotNull]
        public int Author_id { get; set; }
        [MaxLength(140)]
        public string Annotation { get; set; }  
        public Content()
        { }
        public Content(string title, int informationSource_id,string source, string date, int genre_id, int author_id, string annotation)
        {
            Source = source;
            Title = title;
            InformationSource_id = informationSource_id;

            Date = date;
            Genre_id = genre_id;
            Author_id = author_id;
            Annotation = annotation;
        }
    }
}
