using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MevLab
{
    public partial class Form2 : Form
    {
        public Random rndnum = new Random();
        public int[] Arr1;
        public int[] Arr2;
        public int[] Arr3;
        public int[] Arr4;
        public int[] Arr5;
        public Form2()
        {
            InitializeComponent();
            button2.Enabled = false;

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            int dim, s1, s11, s2, s22, s3, s33, s4, s44;

            try
            {
                dim = Convert.ToInt32(maskedTextBox9.Text);
                s1 = Convert.ToInt32(maskedTextBox1.Text);
                s11 = Convert.ToInt32(maskedTextBox2.Text);
                s2 = Convert.ToInt32(maskedTextBox3.Text);
                s22 = Convert.ToInt32(maskedTextBox4.Text);
                s3 = Convert.ToInt32(maskedTextBox5.Text);
                s33 = Convert.ToInt32(maskedTextBox6.Text);
                s4 = Convert.ToInt32(maskedTextBox7.Text);
                s44 = Convert.ToInt32(maskedTextBox8.Text);
            }
            catch
            {
                MessageBox.Show("Ошибка заполнения входных данных.");
                maskedTextBox1.Clear();
                maskedTextBox2.Clear();
                maskedTextBox3.Clear();
                maskedTextBox4.Clear();
                maskedTextBox5.Clear();
                maskedTextBox6.Clear();
                maskedTextBox7.Clear();
                maskedTextBox8.Clear();
                maskedTextBox9.Clear();
                return;
            }
            button2.Enabled = true;
            //отключить поля, доступные для заполнения
            maskedTextBox1.Enabled = false;
            maskedTextBox2.Enabled = false;
            maskedTextBox3.Enabled = false;
            maskedTextBox4.Enabled = false;
            maskedTextBox5.Enabled = false;
            maskedTextBox6.Enabled = false;
            maskedTextBox7.Enabled = false;
            maskedTextBox8.Enabled = false;
            maskedTextBox9.Enabled = false;
            //заполнить массивы
            Arr1 = new int[dim];
            Arr2 = new int[dim];
            Arr3 = new int[dim];
            Arr4 = new int[dim];
            for (int i = 0; i < dim; i++)
            {
                Arr1[i] = rndnum.Next(s1, s11);
                richTextBox1.AppendText(Convert.ToString(Arr1[i]) + "\n");
                Arr2[i] = rndnum.Next(s2, s22);
                richTextBox2.AppendText(Convert.ToString(Arr2[i]) + "\n");
                Arr3[i] = rndnum.Next(s3, s33);
                richTextBox3.AppendText(Convert.ToString(Arr3[i]) + "\n");
                Arr4[i] = rndnum.Next(s4, s44);
                richTextBox4.AppendText(Convert.ToString(Arr4[i]) + "\n");

            }
            Arr5 = new int[dim * 4];
            int o = 0;
            for (; o < dim; o++)
            {
                Arr5[o] = Arr1[o];
                richTextBox5.AppendText(Convert.ToString(Arr5[o]) + "\n");

            }
            for (int k = 0; k < dim; o++, k++)
            {
                Arr5[o] = Arr2[k];
                richTextBox5.AppendText(Convert.ToString(Arr5[o]) + "\n");

            }
            for (int n = 0; n < dim; o++, n++)
            {
                Arr5[o] = Arr3[n];
                richTextBox5.AppendText(Convert.ToString(Arr5[o]) + "\n");
            }
            for (int m = 0; m < dim; o++, m++)
            {
                Arr5[o] = Arr4[m];
                richTextBox5.AppendText(Convert.ToString(Arr5[o]) + "\n");

            }
        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void Label3_Click(object sender, EventArgs e)
        {

        }

        private void ListView4_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void MaskedTextBox9_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox2_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox3_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox4_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox5_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox6_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox7_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void MaskedTextBox8_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void ListView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void RichTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            richTextBox5.Clear();
            HeapSort.sort(Arr5);
            for (int i = 0; i < Arr5.Length; i++)
                richTextBox5.AppendText(Convert.ToString(Arr5[i]) + "\n");
        }
    }
}
