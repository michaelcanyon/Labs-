using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
namespace Lab_2_OOP
{

    public partial class Geometry : Form
    {
        public Geometry()
        {
            InitializeComponent();
        }
        Thread current = Thread.CurrentThread;
        CancellationTokenSource end = new CancellationTokenSource();
        bool stopflag = false;
        private void Geometry_Click(object sender, EventArgs e)
        {
            Pen newFigure = new Pen(Color.Blue, 2);
            Form newForm = sender as Form;
            Graphics newGraph = newForm.CreateGraphics();
            Point newPoint = new Point(50, 50, newGraph, newForm, newFigure);
            Line newLine = new Line(50, 100, 50, 0, newGraph, newForm, newFigure);
            Parallelogram newParallelogram = new Parallelogram(50, 200, 20, 80, 10, 0, newGraph, newFigure, newForm);
            Pyramid newPyramid = new Pyramid(50, 400, 40, 300, 0, 100, 0, newGraph, newFigure, newForm);
            newPoint.Show();
            newLine.Show();
            newParallelogram.Show();
           newPyramid.Show();
            while (true)
            {
                // newThread.Resume();
                newPoint.Move(2);
                newLine.Rotate(0.1);
                newLine.Move(2);

                newParallelogram.Rotate(0.1);
                newParallelogram.Move(2);
                newPyramid.Rotate(0.1);
                newPyramid.Move(2);
                if (newPoint.X >= newForm.Width + 150)
                { newPoint.X = 0; }
                if (newLine.X >= newForm.Width + 150)
                { newLine.X = 0; }
                if (newParallelogram.X >= newForm.Width + 150)
                { newParallelogram.X = 0; }
                if (newPyramid.X >= newForm.Width + 150)
                { newPyramid.X = 0; }
            }
        }

        private void Geometry_Load(object sender, EventArgs e)
        {

        }
    }

}
