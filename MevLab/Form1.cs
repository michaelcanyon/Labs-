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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Form2 sorts = new Form2();
            sorts.Show();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Form3 DB =new Form3();
            DB.Show();
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            Form4 PS = new Form4();
            PS.Show();
        }
    }
}
