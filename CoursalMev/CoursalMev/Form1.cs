using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SQLite;

namespace CoursalMev
{
    public partial class Form1 : Form
    {
        SQLiteConnection db = new SQLiteConnection("InformationConsuptionAnalyser.db", false);
        List<Content> contents = new List<Content>();
        List<Author> authors = new List<Author>();
        List<AuthorProfession> authorProfessions = new List<AuthorProfession>();
        List<InformationSource> information_sources = new List<InformationSource>();
        List<Source> sources = new List<Source>();
        List<Genre> genres = new List<Genre>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int count;
            db.CreateTable<Content>();
            db.CreateTable<InformationSource>();
            db.CreateTable<Genre>();
            db.CreateTable<Author>();
            db.CreateTable<AuthorProfession>();
            try
            {
                db.Insert(new InformationSource("Internet"));
                db.Insert(new InformationSource("TV"));
                db.Insert(new InformationSource("Radio"));
                db.Insert(new InformationSource("Email"));

            }
            catch
            { 
            }

            try
            {
                contents.Clear();
                var contentsi = db.Table<Content>();
                foreach (Content i in contentsi)
                { contents.Add(i); }
                ContentGrid.DataSource = null;
            }
            catch { }
            ContentGrid.DataSource = contents;

            count = db.Table<InformationSource>().Count();
            for (int i = 1; i <= count; i++)
                information_sources.Add(db.Get<InformationSource>(i));
            Infrom_SourceGrid.DataSource = information_sources;

            count = db.Table<Author>().Count();
            for (int i = 1; i <= count; i++)
                authors.Add(db.Get<Author>(i));
            AuthorGrid.DataSource = authors;

            count = db.Table<AuthorProfession>().Count();
            for (int i = 1; i <= count; i++)
                authorProfessions.Add(db.Get<AuthorProfession>(i));
            ProfessionGrid.DataSource = authorProfessions;

            count = db.Table<Genre>().Count();
            for (int i = 1; i <= count; i++)
                genres.Add(db.Get<Genre>(i));
            Genre_Grid.DataSource = genres;

            count = db.Table<Source>().Count();
            for (int i = 1; i <= count; i++)
                sources.Add(db.Get<Source>(i));
            Source_Grid.DataSource = sources;

            foreach (Author i in authors)
                ContentAuthor.Items.Add(i.Name);
            foreach (Genre i in genres)
                ContentGenre.Items.Add(i.pGenre);
            foreach (InformationSource i in information_sources)
                ContentType.Items.Add(i.Type);

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void AddContendButton_Click(object sender, EventArgs e)
        {
            int InformationSource_id = db.ExecuteScalar<int>("SELECT Id FROM InformationSource WHERE Type=?", ContentType.Text);
            int ContentGenre_id = db.ExecuteScalar<int>("SELECT Id FROM Genre WHERE pGenre=?", ContentGenre.Text);
            int ContentAuthor_id = db.ExecuteScalar<int>("SELECT Id FROM Author WHERE Name=?", ContentAuthor.Text);
            Content bufferCont = new Content(ContentTitle.Text,InformationSource_id,ContentSource.Text,ContentDate.Text,ContentGenre_id,ContentAuthor_id,ContentAnnotation.Text);
            db.Insert(bufferCont);
            contents.Add(bufferCont);
            try
            {
                Source bufferSource = new Source(ContentSource.Text);
                db.Insert(bufferSource);
                sources.Add(bufferSource);
            }
            catch { }
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
            Source_Grid.DataSource = null;
            Source_Grid.DataSource = sources;
        }

        private void SourceButton_Click(object sender, EventArgs e)
        {   
        }

        private void GenreButton_Click(object sender, EventArgs e)
        {
            try
            {
                Genre bufferGenre = new Genre(GenreBox.Text);
                db.Insert(bufferGenre);
                genres.Add(bufferGenre);
                Genre_Grid.DataSource = null;
                Genre_Grid.DataSource = genres;
                ContentGenre.Items.Clear();
                foreach (Genre i in genres)
                    ContentGenre.Items.Add(i.pGenre);
            }
            catch
            { 
            
            }

        }

        private void AddAuthorButton_Click(object sender, EventArgs e)
        {
            try
            {
                AuthorProfession bufferProfession = new AuthorProfession(AuthorsProfession.Text);
                db.Insert(bufferProfession);
                authorProfessions.Add(bufferProfession);
                ProfessionGrid.DataSource = null;
                ProfessionGrid.DataSource = authorProfessions;
            }
            catch
            { }
            var Profession_id = db.ExecuteScalar<int>("SELECT Id FROM AuthorProfession WHERE ProfessionTitle=?", AuthorsProfession.Text);
            Author bufferAuthor= new Author(AuthorsName.Text,Profession_id);
            db.Insert(bufferAuthor);
            authors.Add(bufferAuthor);
            AuthorGrid.DataSource = null;
            AuthorGrid.DataSource = authors;
            ContentAuthor.Items.Clear();
            foreach (Author i in authors)
                ContentAuthor.Items.Add(i.Name);
        }

        private void SelectOnAuthor_Click(object sender, EventArgs e)
        {
            int ContentAuthor_id = db.ExecuteScalar<int>("SELECT Id FROM Author WHERE Name=?", ContentAuthor.Text);
            contents = db.Query<Content>("SELECT * FROM Content WHERE Author_Id=?", ContentAuthor_id);
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }

        private void SelectOnTag_Click(object sender, EventArgs e)
        {
            int ContentGenre_id = db.ExecuteScalar<int>("SELECT Id FROM Genre WHERE pGenre=?", ContentGenre.Text);
            contents = db.Query<Content>("SELECT * FROM Content WHERE Genre_Id=?", ContentGenre_id);
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }

        private void SelectOnPubType_Click(object sender, EventArgs e)
        {
            contents.Clear();
            contents = db.Query<Content>("SELECT * FROM Content WHERE Source=?", ContentSource.Text);
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }

        private void SelectOnSource_Click(object sender, EventArgs e)
        {
            int ContentInfSource_id = db.ExecuteScalar<int>("SELECT Id FROM InformationSource WHERE Type=?", ContentType.Text);
            contents = db.Query<Content>("SELECT * FROM Content WHERE InformationSource_id=?", ContentInfSource_id);
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            contents.Clear();
            var contentsi = db.Table<Content>();
            foreach (Content i in contentsi)
            { contents.Add(i); }
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }

        private void Delete_note_Click(object sender, EventArgs e)
        {
            db.Delete<Content>(Convert.ToInt32(delField.Text));
            contents.Clear();
            var contentsi=db.Table<Content>();
            foreach (Content i in contentsi)
            { contents.Add(i); }
            ContentGrid.DataSource = null;
            ContentGrid.DataSource = contents;
        }
    }
}
