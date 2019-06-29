using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Practice4Semm
{
    public partial class Form4 : Form
    {
        /// <summary>
        /// Список студентов
        /// </summary>
        List<line> students = new List<line>();
        line person = new line();
        /// <summary>
        /// Строковое представление записи о студенте
        /// </summary>
        string[] str;
        /// <summary>
        /// Сумма языковых весов для рассчёта процентной статистики
        /// </summary>
        double summ=0;
        /// <summary>
        /// Доля студентов, изучающих язык в %
        /// </summary>
        double avgpercenr = 0;
        /// <summary>
        /// Массив языков, по которым ведется статистика
        /// </summary>
        string[] languages = new string[] { "Eng", "De", "Fr" };
        /// <summary>
        /// Доля каждого языка в количестве студентов
        /// </summary>
        double[] languageValues = new double[] { 0, 0, 0 };

        /// <summary>
        /// Описание студента
        /// </summary>
        struct line
        {
            /// <summary>
            /// Имя студента
            /// </summary>
            public string Name;
            /// <summary>
            /// Дата рождения
            /// </summary>
            public string birthDate;
            /// <summary>
            /// Номер зачетки
            /// </summary>
            public string docnum;
            /// <summary>
            /// Изучаемый иностранный язык
            /// </summary>
            public string language;
            /// <summary>
            /// средний балл
            /// </summary>
            public double avgGrade;
        };
        /// <summary>
        /// Инициализация окна
        /// </summary>
        public Form4()
        {
            InitializeComponent();
            chart1.Series[0].Points.DataBindXY(languages, languageValues);
            chart1.ChartAreas[0].Area3DStyle.Enable3D = true;

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        /// <summary>
        /// Добавляет информацию о студенте в список 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            //Считывание информации о студенте из окна
            try { person.Name = StudName.Text; }
            catch { return; }
            try { person.birthDate = Birth.Text; }
            catch { return; }
            try { person.language = Language.Text; }
            catch { return; }
            try { person.docnum = Doc.Text; }
            catch { return; }
            try { person.avgGrade = Convert.ToDouble(Avg.Text); }
            catch { return; }
            person.language = person.language.ToLower();
            students.Add(person);
            str = new string[] { person.Name, person.birthDate, Convert.ToString(person.docnum), person.language, Convert.ToString(person.avgGrade) };
            dataGridView1.Rows.Add(str);
            if (person.language == "английский")
                languageValues[0]++;
            else if (person.language == "немецкий")
                languageValues[1]++;
            else if (person.language == "французский")
                languageValues[2]++;

            //Рассчёт процентных соотношений для диаграммы
            summ = 0;
            languages = new string[] { "Eng", "De", "Fr" };
            for (int g = 0; g < languageValues.Length; g++)
                summ += languageValues[g];
            for (int i = 0; i < languages.Length; i++)
            {
                avgpercenr = languageValues[i] / summ * 100;
                avgpercenr = System.Math.Round(avgpercenr, 2);
                languages[i] = languages[i] + ": " + Convert.ToString(avgpercenr) + "%";
            }
            //Построение диаграммы
            chart1.Series[0].Points.DataBindXY(languages, languageValues);

        }

        private void button1_Click_1(object sender, EventArgs e)
        {

        }

        private void button1_Click_2(object sender, EventArgs e)
        {      
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Считывание входных данных, создание таблицы и диаграммы по ним
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ReadList_Click(object sender, EventArgs e)
        {
            //обнулить массив веса изучаемого языка
            for (int i = 0; i < languageValues.Length; i++)
               languageValues[i] = 0;
            //Очистить таблицу формы
            dataGridView1.Rows.Clear();
            students.Clear();
            string _name;
            string _birthDate;
            string docnum;
            string language;
            string avg;
            string filepath = textBox1.Text;
            //Считать записи списка студентов
            FileStream file = new FileStream(filepath, FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(file);
            while (true)
            {
                if ((_name = reader.ReadLine()) == null)
                    break;
                if ((_birthDate = reader.ReadLine()) == null)
                    break;
                if ((docnum = reader.ReadLine()) == null)
                    break;
                if ((language = reader.ReadLine()) == null)
                    break;
                if ((avg = reader.ReadLine()) == null)
                    break;
                language = language.ToLower();
                person.Name = _name;
                person.birthDate = _birthDate;
                person.docnum = docnum;
                person.language = language;
                person.avgGrade = Convert.ToDouble(avg);
                students.Add(person);
            }
            reader.Close();
            file.Close();
            //Занести языковую статистику в массивы
            foreach (line i in students)
            {
                str = new string[] { i.Name, i.birthDate, Convert.ToString(i.docnum), i.language, Convert.ToString(i.avgGrade) };
                dataGridView1.Rows.Add(str);
                if (i.language == "английский")
                    languageValues[0]++;
                else if (i.language == "немецкий")
                    languageValues[1]++;
                else if (i.language == "французский")
                    languageValues[2]++;
            }

            //Рассчёт процентных соотношений для диаграммы
            summ = 0;
            languages = new string[] { "Eng", "De", "Fr" };
            for (int g = 0; g < languageValues.Length; g++)
                summ += languageValues[g];
            for (int i = 0; i < languages.Length; i++)
            {
                avgpercenr = languageValues[i] / summ * 100;
                avgpercenr = System.Math.Round(avgpercenr, 2);
                languages[i] = languages[i] + ": " + Convert.ToString(avgpercenr) + "%";
            }
            //Построить диаграмму
            chart1.Series[0].Points.DataBindXY(languages, languageValues);
        }

        /// <summary>
        /// Записывает данные о студентах в файл, а также создает файл, в котором хранится диаграмма
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click_3(object sender, EventArgs e)
        {
            //Выбор языка, по которому будет вестись запись в файл
            string defal = "Все языки";
            if (comboBox1.Text == "Английский")
                defal = "английский";
            else if (comboBox1.Text == "Немецкий")
                defal = "немецкий";
            else if (comboBox1.Text == "Французский")
                defal = "французский";
            else if (comboBox1.Text == "Итальянский")
                defal = "итальянский";
            else if (comboBox1.Text == "Китайский")
                defal = "китайский";
            else if (comboBox1.Text == "Въетнамский")
                defal = "въетнамский";

            //Запись в файл
            string filepath = textBox1.Text;
            if (filepath == null || filepath == "")
                return;
            FileInfo file0 = new FileInfo(filepath);
            try { file0.Delete(); }
            catch { }
            FileStream file = new FileStream(filepath, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(file);
            if (defal != "Все языки")
            {
                foreach (line i in students)
                {
                    if (i.language == defal)
                    {
                        writer.WriteLine(i.Name);
                        writer.WriteLine(i.birthDate);
                        writer.WriteLine(Convert.ToString(i.docnum));
                        writer.WriteLine(i.language);
                        writer.WriteLine(Convert.ToString(i.avgGrade));
                    }
                }
            }
            else
            {
                foreach (line i in students)
                {
                    writer.WriteLine(i.Name);
                    writer.WriteLine(i.birthDate);
                    writer.WriteLine(Convert.ToString(i.docnum));
                    writer.WriteLine(i.language);
                    writer.WriteLine(Convert.ToString(i.avgGrade));
                }
            }
            writer.Close();
            file.Close();
            if (textBox4.Text == null || textBox4.Text == "")
                return;
            //Сохранение диаграммы
            chart1.SaveImage(textBox4.Text, System.Windows.Forms.DataVisualization.Charting.ChartImageFormat.Bmp);
        }

        /// <summary>
        /// Сортирует записи о студентах в порядке возрастания среднего балла и меняет их расстановку в таблице
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Sort_Click(object sender, EventArgs e)
        {
            students = students.OrderBy(x => x.avgGrade).ToList();
            dataGridView1.Rows.Clear();
            foreach (line i in students)
            {
                str = new string[] { i.Name, i.birthDate, Convert.ToString(i.docnum), i.language, Convert.ToString(i.avgGrade) };
                dataGridView1.Rows.Add(str);
            }

        }

        private void Birth_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void folderBrowserDialog1_HelpRequest(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
