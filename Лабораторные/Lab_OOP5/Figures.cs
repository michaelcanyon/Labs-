using System;
using System.Drawing;
using System.Windows.Forms;

namespace Lab_OOP5
{
    abstract class PrototypeFig
    {
        protected Graphics graph;
        protected Pen newFigure;
        protected Form window;
        public int X { get; set; }
        public int Y { get; set; }
        protected void Hide()
        {
            Color tempcolor = newFigure.Color;
            newFigure.Color = window.BackColor;
            Show();
            newFigure.Color = tempcolor;
        }
        public abstract void Show();
        public void Move(int DX)
        {
            Hide();
            X += DX;
            Show();
        }
    }
    class Point:PrototypeFig
    {     
         public override void Show() { graph.DrawLine(newFigure,X, Y, X + 1, Y); } 
        public Point(int x, int y, Graphics NewGraph, Form window, Pen defaultPen)
        {
            X = x;
            Y = y;
            graph = NewGraph;
            this.window = window;
            newFigure = defaultPen;
        }
       // protected Point() { }
    }
    class Line : Point
    {
        protected int Length { get; set; }
        public double Angle { get; set; }
        public void Rotate(double DX)
        {
            Hide();
            Angle += DX;
            Show();
        }
        public override void Show() { graph.DrawLine(newFigure, Convert.ToSingle(X + Length / 2 * System.Math.Sin(Angle)), Convert.ToSingle(Y - Length / 2 * System.Math.Cos(Angle)), Convert.ToSingle(X + Length / 2 * System.Math.Sin(Angle + System.Math.PI)), Convert.ToSingle(Y - Length / 2 * System.Math.Cos(Angle + System.Math.PI))); }
        public Line(int x, int y, int length, double angle, Graphics NewGraph, Form window, Pen defaultPen) : base(x, y, NewGraph, window, defaultPen)
        {
            Length = length;
            Angle = angle;
        }
        //protected Line() { }
    }
    class Parallelogram : Line
    {
        public int h { get; set; }
        public int sharpness { get; set; }
        public override void Show()
        {

            graph.DrawLine(newFigure, Convert.ToSingle(X + (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle)), Convert.ToSingle(X + (Length / 2 - sharpness) * Math.Sin(Angle + (Math.PI/2 ))), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle + Math.PI/2 )));
            graph.DrawLine(newFigure, Convert.ToSingle(X - (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle)), Convert.ToSingle(X - (Length / 2 - sharpness) * Math.Sin(Angle + Math.PI/2 )), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle + Math.PI/2 )));
            graph.DrawLine(newFigure, Convert.ToSingle(X + (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle)), Convert.ToSingle(X - (Length / 2 - sharpness) * Math.Sin(Angle + Math.PI/2 )), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle + Math.PI/2 )));
            graph.DrawLine(newFigure, Convert.ToSingle(X + (Length / 2 - sharpness) * Math.Sin(Angle + Math.PI/2)), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle + Math.PI/2)), Convert.ToSingle(X - (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle)));
        }
        public Parallelogram(int x, int y, int h, int baselngth, int sharpness, double angle, Graphics NewGraph, Pen defaultPen, Form window)
            : base(x, y, baselngth, angle, NewGraph, window, defaultPen)
        {
            this.h = h;
            this.sharpness = sharpness;
        }
        //protected Parallelogram() { }
    }
    class Pyramid : Parallelogram
    {
        public int pyramidHeight { get; set; }
        public override void Show()
        {
            base.Show();
            graph.DrawLine(newFigure, Convert.ToSingle(X + (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle)), Convert.ToSingle(X), Convert.ToSingle(Y - pyramidHeight));
            graph.DrawLine(newFigure, Convert.ToSingle(X + (Length / 2 - sharpness) * Math.Sin(Angle + Math.PI / 2)), Convert.ToSingle(Y + (h / 2) * Math.Cos(Angle + Math.PI / 2)), Convert.ToSingle(X), Convert.ToSingle(Y - pyramidHeight));
            graph.DrawLine(newFigure, Convert.ToSingle(X - (Length / 2 + sharpness) * Math.Sin(Angle)), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle)), Convert.ToSingle(X), Convert.ToSingle(Y - pyramidHeight));
            graph.DrawLine(newFigure, Convert.ToSingle(X - (Length / 2 - sharpness) * Math.Sin(Angle + Math.PI / 2)), Convert.ToSingle(Y - (h / 2) * Math.Cos(Angle + Math.PI / 2)), Convert.ToSingle(X), Convert.ToSingle(Y - pyramidHeight));
        }
        public Pyramid(int x, int y, int h, int baseLength, int sharpness, int pyramidHeight, double angle, Graphics NewGraph, Pen defaultPen, Form window)
            : base(x, y, h, baseLength, sharpness, angle, NewGraph, defaultPen, window)
        { this.pyramidHeight = pyramidHeight; }
       // protected Pyramid() { }
    }
}
