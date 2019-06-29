using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            EquationsSalvationsMethods newEquation = new EquationsSalvationsMethods(1, 2, 0.01);
            newEquation.Dykhotomy();
            Console.ReadLine();
            return;
        }
    }
    class EquationsSalvationsMethods
    {
        private double Equation(double X) => (Math.Pow(X, 3) + 2 * X -7);
        private double FirstDerivate(double X) => (4 * Math.Pow(X, 3) - 2);
        private double SecondDerivate(double X) => (12 * Math.Pow(X, 2));
        private double a { get; set; }
        private double b { get; set; }
        private double precision { get; set; }
        private double x1 { get; set; }
        private double x2 { get; set; }
        public EquationsSalvationsMethods(double a, double b, double precision)
        {
            this.a = a;
            this.b = b;
            this.precision = precision;
        }
        public void HordMethod()
        {
            x1 = a;
            while (x1 < b)
            {
                x1 = x1 - (((b - x1) * Equation(x1)) / (Equation(b) - Equation(x1)));
                if (Math.Abs(Equation(x1)) <= precision)
                {
                    Console.WriteLine("Equation Root has been found: {0} with the precision {1}", x1, precision);
                    return;
                }
                Console.WriteLine("Current root: {0}", x1);
            }
        }
        public void NewTonsMethod()
        {
            double Buffer = a;
            bool flag = false;
            while (Buffer < b)
            {
                if (Equation(Buffer) * SecondDerivate(Buffer) > 0)
                {
                    x1 = Buffer;
                    flag = true;
                    break;
                }
                Buffer += precision;
            }
            if (!flag)
            {
                Console.WriteLine("Written interval doesn't contains equation root");
                return;
            }
            while (x1 < b)
            {
                x1 = x1 - (Equation(x1) / FirstDerivate(x1));
                if (Math.Abs(Equation(x1)) <= precision)
                {
                    Console.WriteLine("Equation Root has been found: {0} with the precision {1}", x1, precision);
                    return;
                }
                Console.WriteLine("Current root: {0}", x1);
            }
        }
        public void MixedHordsNewtons()
        {
            x1 = a;
            x2 = b;
            double Buffer = a;
            bool flag = false;
            while (Buffer < b)
            {
                if (Equation(Buffer) * SecondDerivate(Buffer) > 0)
                {
                    x1 = Buffer;
                    flag = true;
                    break;
                }
                Buffer += precision;
            }
            if (!flag)
            {
                Console.WriteLine("Written interval doesn't contains equation root");
                return;
            }
            while (x1 < x2)
            {
                x1 = x1 - (Equation(x1) / FirstDerivate(x1));
                if (Math.Abs(Equation(x1)) <= precision)
                {
                    Console.WriteLine("Equation Root has been found: {0} with the precision {1}", x1, precision);
                    return;
                }
                Console.WriteLine("Current right root: {0}", x1);
                x2 = x2 - (((b - x2) * Equation(x2)) / (Equation(b) - Equation(x2)));
                if (Math.Abs(Equation(x2)) <= precision)
                {
                    Console.WriteLine("Equation Root has been found: {0} with the precision {1}", x1, precision);
                    return;
                }
                Console.WriteLine("Current left root: {0}", x1);
            }
        }
        public void Dykhotomy()
        {
            double currentFunc;
            // bool salvation=false;
            double temp = (a + b) / 2;
            a = (a + b) / 2;
            currentFunc = Equation(a);
            while (Math.Abs(currentFunc) > precision)
            {
                if (currentFunc * Equation(a) < 0)
                    b = temp;
                else
                    a = temp;
               temp = (a + b) / 2;
                //salvation = true;
                currentFunc = (Equation(temp));
            }
            Console.WriteLine($"Equation Root has been found: {temp} with the precision {precision}");
        }
    }
}