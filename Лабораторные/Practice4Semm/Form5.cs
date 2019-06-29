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
    public partial class Form5 : Form
    {
        /// <summary>
        /// Вектор X
        /// </summary>
        List<int> X = new List<int>();
        /// <summary>
        /// Вектор Y
        /// </summary>
        List<int> Y = new List<int>();
        /// <summary>
        /// Вектор Z
        /// </summary>
        List<int> Z = new List<int>();
        /// <summary>
        /// Среднее значение по столбцам 
        /// </summary>
        double avg = 0;
        /// <summary>
        /// Значение ячейки столбца
        /// </summary>
        int x = 0, y = 0, z = 0;
        /// <summary>
        /// Число столбцов
        /// </summary>
        int n;
        /// <summary>
        /// Инициализация окна
        /// </summary>
        public Form5()
        {
            InitializeComponent();
            chart1.ChartAreas[0].Area3DStyle.Enable3D = true;

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        /// <summary>
        /// Сортирует векторы в порядке возрастания, считает средние для сформированных столбцов и строит диаграмму
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            //Очистка поля диаграммы
            chart1.Series.Clear();
            chart1.Series.Add("dia");
            //Сортировка
            X.Sort();
            Y.Sort();
            Z.Sort();
            //Заполнить ячейки
            int h = 0;
            foreach (int i in X)
            {
                dataGridView1.Rows[0].Cells[h].Value = i;
                h++;
            }
            h = 0;
            foreach (int i in Y)
            {
                dataGridView1.Rows[1].Cells[h].Value = i;
                h++;
            }
            h = 0;
            foreach (int i in Z)
            {
                dataGridView1.Rows[2].Cells[h].Value = i;
                h++;
            }
            //Высчитать средние и заполнить диаграмму
            for (int i = 0; i < X.Count; i++)
            {
                x = Convert.ToInt32(dataGridView1.Rows[0].Cells[i].Value);
                y = Convert.ToInt32(dataGridView1.Rows[1].Cells[i].Value);
                z = Convert.ToInt32(dataGridView1.Rows[2].Cells[i].Value);
                avg = (x + y + z) / 3;
                dataGridView1.Rows[3].Cells[i].Value = avg;
                chart1.Series[0].Points.AddXY(i, avg);
            }
        }

        /// <summary>
        /// Читает файл данных, заполняет вектора и строит диаграмму
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button3_Click(object sender, EventArgs e)
        {
            //Очистка векторов и полей диаграммы от мусора 
            X.Clear();
            Y.Clear();
            Z.Clear();
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            chart1.Series.Clear();
            chart1.Series.Add("dia");
            maskedTextBox4.Enabled = true;
            string buff;
            string filepath = textBox5.Text;
            //разметка таблицы
            FileStream file;
            try { file = new FileStream(filepath, FileMode.OpenOrCreate, FileAccess.Read); }
            catch
            {
                MessageBox.Show("Ошибка открытия файла");
                return;
            }
            StreamReader reader = new StreamReader(file);
            buff = reader.ReadLine();
            n = Convert.ToInt32(buff);
            maskedTextBox4.Text = Convert.ToString(n);
            maskedTextBox4.Enabled = false;
            for (int i = 0; i < n; i++)
                dataGridView1.Columns.Add(Convert.ToString(i), Convert.ToString(i));
            for (int g = 0; g < 4; g++)
                dataGridView1.Rows.Add();
            //Чтение файла
            for (int i = 0; i < n; i++)
            {
                buff = reader.ReadLine();
                X.Add(Convert.ToInt32(buff));
            }
            for (int i = 0; i < n; i++)
            {
                buff = reader.ReadLine();
                Y.Add(Convert.ToInt32(buff));
            }
            for (int i = 0; i < n; i++)
            {
                buff = reader.ReadLine();
                Z.Add(Convert.ToInt32(buff));
            }
            reader.Close();
            file.Close();
            //Заполнение таблицы
            int h = 0;
            foreach (int i in X)
            {
                dataGridView1.Rows[0].Cells[h].Value = i;
                h++;
                
            }
            h = 0;
            foreach (int i in Y)
            {
                dataGridView1.Rows[1].Cells[h].Value = i;
                h++;
            }
            h = 0;
            foreach (int i in Z)
            {
                dataGridView1.Rows[2].Cells[h].Value = i;
                h++;
            }
            //Высчитать средние и заполнить диаграмму
            for (int i = 0; i < X.Count; i++)
            {
                x = Convert.ToInt32(dataGridView1.Rows[0].Cells[i].Value);
                y = Convert.ToInt32(dataGridView1.Rows[1].Cells[i].Value);
                z = Convert.ToInt32(dataGridView1.Rows[2].Cells[i].Value);
                avg = (x + y + z) / 3;
                dataGridView1.Rows[3].Cells[i].Value = avg;
                chart1.Series[0].Points.AddXY(i, avg);
            }

        }

        /// <summary>
        /// Запись данных в файл
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button4_Click(object sender, EventArgs e)
        {
           
            string filepath = textBox5.Text;
            FileInfo file0 = new FileInfo(filepath);
            try { file0.Delete(); }
            catch { }
            FileStream file;
            try { file = new FileStream(filepath, FileMode.OpenOrCreate, FileAccess.Write); }
            catch
            {
                MessageBox.Show("Ошибка открытия файла");
                return;
            }
            StreamWriter writer = new StreamWriter(file);
            writer.WriteLine(Convert.ToString(n));
            foreach (int i in X)
                writer.WriteLine(Convert.ToString(i));
            foreach (int i in Y)
                writer.WriteLine(Convert.ToString(i));
            foreach (int i in Z)
                writer.WriteLine(Convert.ToString(i));
            writer.Close();
            file.Close();
        }
        /// <summary>
        /// Формирует запись из данных полей окна и добавляет её в список
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            //Защита поля с числом столбцов в матрице
            if (maskedTextBox4.Enabled)
            {
                n = Convert.ToInt32(maskedTextBox4.Text);
                maskedTextBox4.Enabled = false;
                for (int i = 0; i < n; i++)
                    dataGridView1.Columns.Add(Convert.ToString(i), Convert.ToString(i));
                for (int g = 0; g < 4; g++)
                    dataGridView1.Rows.Add();
            }
            if (X.Count == n || Y.Count == n || Z.Count == n)
            {
                MessageBox.Show("Добавлено максимальное количество элементов в вектора.");
                return;
            }
            else
            {
                try { X.Add(Convert.ToInt32(maskedTextBox1.Text)); }
                catch
                {
                    MessageBox.Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
                    return;
                }
                try { Y.Add(Convert.ToInt32(maskedTextBox2.Text)); }
                catch
                {
                    MessageBox.Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
                    return;
                }
                try { Z.Add(Convert.ToInt32(maskedTextBox3.Text)); }
                catch
                {
                    MessageBox.Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
                    return;
                }

            }
            //Заполнение ячеек данными
            int h = 0;
            foreach (int i in X)
            {
                dataGridView1.Rows[0].Cells[h].Value = i;
                h++;
            }
            h = 0;
            foreach (int i in Y)
            {
                dataGridView1.Rows[1].Cells[h].Value = i;
                h++;
            }
            h = 0;
            foreach (int i in Z)
            {
                dataGridView1.Rows[2].Cells[h].Value = i;
                h++;
            }
            //Вычисление и заполнение ячеек со средними значениями столбцов и построение диаграммы
            for (int i = 0; i < X.Count; i++)
            {
                x = Convert.ToInt32(dataGridView1.Rows[0].Cells[i].Value);
                y = Convert.ToInt32(dataGridView1.Rows[1].Cells[i].Value);
                z = Convert.ToInt32(dataGridView1.Rows[2].Cells[i].Value);
                avg = (x + y + z) / 3;
                dataGridView1.Rows[3].Cells[i].Value = avg;
                chart1.Series[0].Points.AddXY(i, avg);
            }
            maskedTextBox1.Text = "";
            maskedTextBox2.Text = "";
            maskedTextBox3.Text = "";

        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
}
