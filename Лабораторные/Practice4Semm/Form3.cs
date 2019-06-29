using System;
using System.Windows.Forms;
using System.IO;
using System.Text;

namespace Practice4Semm
{
    public partial class Form3 : Form
    {
        private string buffer;
        private string _filepath;
        public Form3()
        {
            InitializeComponent();

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Метод расшифровывает зашифрованный текст с помощью ключа шифрования
        /// </summary>
        private void Decrypt_click(object sender, EventArgs e)
        {
            string pattern = "1234567890-!@#$%^&*()_<>?}{'\";:,./?=`~ ";
            int m;
            char symbol;
            int alphaNum, div, bufm;
            // считывание и вычисление ключа сдвига
            try
            { m = Convert.ToInt32(Key.Text); }
            catch
            {
                MessageBox.Show("Key error!");
                return;
            }
            m -= 1;
            m %= 66;
            buffer = richTextBox1.Text;
            int textlength = buffer.Length;
            //сам сдвиг ключа символа
            for (int i = 0; i < textlength; i++)
            {

                symbol = buffer[i];
                alphaNum = symbol - 1040;

                if (m > alphaNum)
                {
                    bufm = m - alphaNum;
                    alphaNum = 66;
                    div = alphaNum - bufm;
                }
                else
                { div = alphaNum - m; }

                div += 1040;
                if (pattern.Contains(Convert.ToString(symbol)))
                    continue;
                //вставка сдвинутого символа
                buffer = buffer.Remove(i, 1);
                buffer = buffer.Insert(i, Convert.ToString((char)div));
            }
            richTextBox1.Text = buffer;
        }
        /// <summary>
        /// метод считывает в текстовое поле текст из файла
        /// </summary>
        private void Read_click(object sender, EventArgs e)
        {
            _filepath = textBox1.Text;
            FileStream stream = new FileStream(_filepath, FileMode.Open, FileAccess.Read);
            StreamReader rstream = new StreamReader(stream, Encoding.GetEncoding(1251));
            while ((buffer = rstream.ReadLine()) != null)
                richTextBox1.AppendText(buffer);
            rstream.Close();
            stream.Close();
        }
        /// <summary>
        /// метод зашифровывает текст из текстового поля
        /// </summary>
        private void Encrypt_Click(object sender, EventArgs e)
        {
            string pattern = "1234567890-!@#$%^&*()_<>?}{'\";:,./?=`~ "; ;
            int m;
            char symbol;
            int alphaNum, div, bufm;
            // считывание и вычисление ключа сдвига
            try
            { m = Convert.ToInt32(Key.Text); }
            catch
            {
                MessageBox.Show("Key error!");
                return;
            }
            m -= 1;
            m %= 66;
            buffer = richTextBox1.Text;
            int textlength = buffer.Length;
            //сам сдвиг ключа символа
            for (int i = 0; i < textlength; i++)
            {

                symbol = buffer[i];
                alphaNum = symbol - 1040;
                if (alphaNum + m > 66)
                {
                    bufm = m - (66 - alphaNum);
                    alphaNum = 0;
                    div = alphaNum + bufm;
                }
                else
                { div = alphaNum + m; }

                div += 1040;
                if (pattern.Contains(Convert.ToString(symbol)))
                    continue;
                //вставка сдвинутого символа
                buffer = buffer.Remove(i, 1);
                buffer = buffer.Insert(i, Convert.ToString((char)div));
            }
            richTextBox1.Text = buffer;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Метод записывает текст из текстового поля в файл, путь к которому указан в текстовом поле пути
        /// </summary>
        private void button1_Click(object sender, EventArgs e)
        {
            FileStream stream = new FileStream(_filepath, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter wstream = new StreamWriter(stream, Encoding.GetEncoding(1251));
            wstream.WriteLine(buffer);
            wstream.Close();
            stream.Close();
        }
    }
}
