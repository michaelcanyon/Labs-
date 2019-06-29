using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace СиАОДЛаба6
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "C:\\Users\\hrani\\Documents\\Labs\\Лабораторные\\СиАОДЛаба6\\NumsToSort.txt";
            FileStream newStream = new FileStream(filename, FileMode.Open, FileAccess.Read);
            StreamReader read = new StreamReader(newStream);
            int NumQuantity = Convert.ToInt32(read.ReadLine());
            Sorts newNums = new Sorts(NumQuantity);
            string dupl;
            int key;
            int i = 0;
            while ((dupl = read.ReadLine()) != null)
            {
                key = Convert.ToInt32(dupl);
                newNums.example[i] = key;
                i++;
            }

            //newNums.ChoosingSort();
            newNums.binaryInsertSort();
            newNums.PrintList();
            Console.ReadLine();
            return;
        }
    }
    class Sorts
    {
        public int[] example;
        public void PrintList()
        {
            int i = 0;
            //Console.WriteLine("Current list: ");
            while (i < example.Length)
            {
                Console.Write( " {0}",example[i]);
                i++;
            }
            Console.WriteLine();
        }
        public void ChoosingSort()
        {
            Stopwatch elaps = new Stopwatch();
            int iterationscounter = 0;
            int examplelength = example.Length;
            int maxel = example[0];
            int maxelI = 0;
            int temp;
            elaps.Start();
            for (int i = 0; i < examplelength; i++)
            {
                maxel = example[i];
                maxelI = i;
                for (int j = i; j < examplelength; j++)
                {
                    if (example[j] > maxel)
                    {
                        maxel = example[j];
                        maxelI = j;
                    }
                    iterationscounter++;
                }
                temp = example[i];
                example[i] = maxel;
                example[maxelI] = temp;
                PrintList();
               
            }
            elaps.Stop();
            Console.WriteLine("Elapsed comliting time {0} ms", elaps.ElapsedMilliseconds);
            Console.WriteLine("Iterations quantity: {0}", iterationscounter);
        }
        public void binaryInsertSort()
        {
            Stopwatch elaps = new Stopwatch();
            int inf;
            int iterationsCounter = 0;
            int sup;
            int middle = 0;
            int current;
            elaps.Start();
            for (int i = 1; i < example.Length; i++)
            {
                   // current = example[i];
                    sup = i;
                    inf = 0;
                    current = example[i];
                    while (inf < sup)
                    {
                        middle =(sup + inf) / 2;//?
                        if (current > example[middle])
                            sup = middle;
                        else
                            inf = middle + 1;
                    }
                    int temp;
                    for (int j = i; j > inf; j--)
                    {
                        temp = example[j-1];
                        example[j-1] = example[j];
                        example[j] = temp;
                    iterationsCounter++;
                    }
                PrintList();
             }
            elaps.Stop();
            Console.WriteLine("Elapsed comliting time {0} ms", elaps.ElapsedMilliseconds);
            Console.WriteLine("Iterations quantity: {0} ", iterationsCounter);
        }
        public Sorts(int numsQua)
        {
            example = new int[numsQua];
        }
    }
}
