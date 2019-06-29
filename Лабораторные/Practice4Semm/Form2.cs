using System;
using System.Windows.Forms;
using System.IO;

namespace Practice4Semm
{
    public partial class Form2 : Form
    {
        /// <summary>
        /// основные параметры для вычисления функции
        /// </summary>
        private float x1 = 0, x2 = 0, x3 = 0, p1 = 0, p2 = 0, a = 0, b = 0;
        /// <summary>
        /// Структура точки функции
        /// </summary>
        struct point
        {
            public double x;
            public double y;
        }
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Graphic_Click(object sender, EventArgs e)
        {

        }

        private void Graphic1_Click(object sender, EventArgs e)
        {

        }

        private void Task_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Graphic1_MouseMove(object sender, MouseEventArgs e)
        {
            System.Drawing.Point Mouse = new System.Drawing.Point(e.X, e.Y);
            //chart
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void FilePath_TextChanged(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Эквивалент основной функции
        /// </summary>
        private void Confirm_Click(object sender, EventArgs e)
        {
            //открытие файла в режиме чтения
            string filepath = FilePath.Text;
            FileStream file = new FileStream(filepath, FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(file);
            string num;
            //Далее происходит считывание исходных данных для вычисления функции
            num = reader.ReadLine();
            x1 = Convert.ToSingle(num);
            num = reader.ReadLine();
            x2 = Convert.ToSingle(num);
            num = reader.ReadLine();
            x3 = Convert.ToSingle(num);
            num = reader.ReadLine();
            p1 = Convert.ToSingle(num);
            num = reader.ReadLine();
            p2 = Convert.ToSingle(num);
            num = reader.ReadLine();
            a = Convert.ToSingle(num);
            num = reader.ReadLine();
            b = Convert.ToSingle(num);
            reader.Close();
            file.Close();
            //отображение исходных данных в окне
            X1.Text = $"X1={x1}";
            X2.Text = $"X2={x2}";
            X3.Text = $"X3={x3}";
            P1.Text = $"P1={p1}";
            P2.Text = $"P2={p2}";
            Aparam.Text = $"A={a}";
            B.Text = $"b={b}";
            //инициализация массива точек и их счетчика i
            int i = 0;
            point[] salvations = new point[Convert.ToInt32((x2 - x1) / x3) + 1];
            //Вычисление значений функции и отображение их на графике
            for (; x1 < p1; x1 += x3, i++)
            {
                salvations[i].y = FirstFunc();
                salvations[i].x = x1;
                Graphic1.Series[0].Points.AddXY(salvations[i].x, salvations[i].y);
            }
            for (; x1 <= p2; x1 += x3, i++)
            {
                salvations[i].y = Math.Cos(a * x1);
                salvations[i].x = x1;
                Graphic1.Series[0].Points.AddXY(salvations[i].x, salvations[i].y);
            }
            for (; x1 <= x2; x1 += x3, i++)
            {
                salvations[i].y = ThirdFunc();
                salvations[i].x = x1;
                Graphic1.Series[0].Points.AddXY(salvations[i].x, salvations[i].y);
            }
            //открытие файла на запись 
            filepath = textBox1.Text;
            FileStream outfile = new FileStream(filepath, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter write = new StreamWriter(outfile);
            write.WriteLine("X\tY");
            //запись значений функции в файл
            for (i = 0; i < salvations.Length; i++)
                write.WriteLine($"{salvations[i].x:f3}\t{salvations[i].y:f3}");
            write.Close();
            outfile.Close();
        }
        /// <summary>
        /// вычисляет значение функции в первом интервале
        /// </summary>
        private double FirstFunc()
        {
            return ((1 + x1 + Math.Pow(x1, 2) / Fact(2) + Math.Pow(x1, 3) / Fact(3) + Math.Pow(x1, 4) / Fact(4) + Math.Pow(x1, 5) / Fact(5) + Math.Pow(x1, 6) / Fact(6) +
                Math.Pow(x1, 7) / Fact(7) + Math.Pow(x1, 8) / Fact(8) + Math.Pow(x1, 9) / Fact(9) + Math.Pow(x1, 10) / Fact(10)) * Math.Sin(b * x1));
        }
        /// <summary>
        /// вычиляет значение функции в тертьем интервале
        /// </summary>
        /// <returns></returns>
        private double ThirdFunc()
        {
            return ((1 + x1 + Math.Pow(x1, 2) / Fact(2) + Math.Pow(x1, 3) / Fact(3) + Math.Pow(x1, 4) / Fact(4) + Math.Pow(x1, 5) / Fact(5) + Math.Pow(x1, 6) / Fact(6) +
                Math.Pow(x1, 7) / Fact(7) + Math.Pow(x1, 8) / Fact(8) + Math.Pow(x1, 9) / Fact(9) + Math.Pow(x1, 10) / Fact(10)) * Math.Cos(b * x1));
        }
        /// <summary>
        /// Вычисляет факториал числа. 
        /// </summary>
        /// <param name="num">Передаваемое число, от которого считается факториал</param>
        private int Fact(int num)
        {
            if (num <= 1)
                return 1;
            else
                return num * Fact(num - 1);
        }
    }
}
