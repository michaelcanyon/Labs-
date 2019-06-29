using System;
using System.Windows.Forms;

namespace Practice4Semm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 Form13 = new Form2();
            Form13.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 Form14 = new Form3();
            Form14.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form4 Form15 = new Form4();
            Form15.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form5 Form16 = new Form5();
            Form16.Show();
        }
    }

}
