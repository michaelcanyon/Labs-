using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MevLab
{
    class Book
    {
        public string title { get; set; }
        public Author author { get; set; }
        public double price { get; set; }
        public int qtyInStock { get; set; }
        public Book(string title, Author author, double price, int qtyInStock)
        {
            this.title = title;
            this.author = author;
            this.price = price;
            this.qtyInStock = qtyInStock;
        }
    }
}
