using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using System.Linq;

namespace MevLab
{
    public partial class Form3 : Form
    {
        string tempAuthorName;
        List<Book> buff = new List<Book>();
        List<Book> books = new List<Book>();
        Book rempBook = new Book();
        Dictionary<string, Author> authors = new Dictionary<string, Author>();
        string Ename, Eemail, Etitle, Eauthor;
        int Eprice, EqtyinStock;
        char gender;
        public Form3()
        {
            InitializeComponent();

        }

        private void Button4_Click(object sender, EventArgs e)
        {
            try
            {
                comboBox1.Items.Clear();
                comboBox2.Items.Clear();
                books.Clear();
                authors.Clear();
                FileStream file = new FileStream("source.txt", FileMode.Open);
                StreamReader read = new StreamReader(file);
                string str = "";
                int num = Convert.ToInt32(read.ReadLine());
                for (int i = 0; i < num; i++)
                {
                    str = read.ReadLine();
                    authors.Add(str,new Author(str,read.ReadLine(),Convert.ToChar(read.ReadLine())));
                }
                num = Convert.ToInt32(read.ReadLine());
                for (int i = 0; i < num; i++)
                {
                    books.Add(new Book(read.ReadLine(),authors[read.ReadLine()],Convert.ToDouble(read.ReadLine()),Convert.ToInt32(read.ReadLine())));
                }
                read.Close();
                file.Close();
                foreach (KeyValuePair<string, Author> keyValue in authors)
                {
                    comboBox1.Items.Add(keyValue.Key);
                    comboBox2.Items.Add(keyValue.Key);
                }
                foreach (Book b in books)
                {
                    listBox2.Items.Add(b.title);
                }
            }
            catch
            {
                MessageBox.Show("Файл не был создан");
            }
        }

        private void ComboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void RichTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void RichTextBox2_TextChanged(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Добавление книги
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Button2_Click(object sender, EventArgs e)
        {
            try
            {
                books.Add(new Book(textBox5.Text, authors[comboBox2.Text], Convert.ToDouble(maskedTextBox1.Text), Convert.ToInt32(maskedTextBox2.Text)));
                listBox2.Items.Add(textBox5.Text);
            }
            catch
            {
                MessageBox.Show("Одно из полей пустое");
            }
        }

        private void TextBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void MaskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox2_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }
        /// <summary>
        /// Добавление автора
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                authors.Add(maskedTextBox4.Text, new Author(maskedTextBox4.Text, textBox2.Text, Convert.ToChar(maskedTextBox3.Text)));
                comboBox1.Items.Add(maskedTextBox4.Text);
                comboBox2.Items.Add(maskedTextBox4.Text);

            }
            catch
            {
                MessageBox.Show("Одно из полей пустое");
            }
        }

        private void MaskedTextBox4_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void MaskedTextBox3_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void RichTextBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void ListBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                richTextBox1.Clear();
                richTextBox2.Clear();
                buff.Clear();
                buff.AddRange(from b in books
                              where b.title == listBox2.Text
                              select b);
                if (buff.Count() > 0)
                {
                    richTextBox2.AppendText("Title:" + buff[0].title + "\n");
                    richTextBox2.AppendText("Author:" + buff[0].author.name + "\n");
                    richTextBox2.AppendText("Quantity in stock:" + buff[0].qtyInStock + "\n");
                    richTextBox2.AppendText("Price:" + buff[0].price + "\n");
                    if (authors[tempAuthorName] == null)
                    {
                        authors.Add(tempAuthorName, new Author(tempAuthorName, "Unknown", 'U'));
                        return;
                    }
                    tempAuthorName = buff[0].author.name;
                    richTextBox1.AppendText("Имя автора:" + authors[tempAuthorName].name + "\n");
                    richTextBox1.AppendText("Email:" + authors[tempAuthorName].email + "\n");
                    richTextBox1.AppendText("Gender:" + authors[tempAuthorName].gender + "\n");
                }
                buff.Clear();
            }
            catch
            {
            }
        }

        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            buff.Clear();
            richTextBox1.Clear();
            listBox2.Items.Clear();
            richTextBox1.AppendText("Имя автора:" + authors[comboBox1.Text].name + "\n");
            richTextBox1.AppendText("Email:" + authors[comboBox1.Text].email + "\n");
            richTextBox1.AppendText("Gender:"+authors[comboBox1.Text].gender + "\n");
            buff.AddRange(from b in books
                          where b.author.name == comboBox1.Text
                          select b);
            foreach (var i in buff)
            {
                listBox2.Items.Add(i.title);
            }
            buff.Clear();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void Button5_Click(object sender, EventArgs e)
        {
            FileStream file = new FileStream("source.txt", FileMode.OpenOrCreate);
            StreamWriter write = new StreamWriter(file);
            write.WriteLine(authors.Count);
            foreach (KeyValuePair<string, Author> keyValue in authors)
            {
                write.WriteLine(keyValue.Value.name);
                write.WriteLine(keyValue.Value.email);
                write.WriteLine(keyValue.Value.gender);
            }
            write.WriteLine(books.Count);
            foreach (var i in books)
            {
                write.WriteLine(i.title);
                write.WriteLine(i.author.name);
                write.WriteLine(i.price);
                write.WriteLine(i.qtyInStock);
            }
            write.Close();
            file.Close();
        }
    }
}
