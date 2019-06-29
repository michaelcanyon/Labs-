using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace СИАОДЛаба5
{
    

    class Program
    {
        static void Main(string[] args)
        {
            Tree newTree = new Tree();
            string filename = "C:\\Users\\hrani\\Documents\\Labs\\Лабораторные\\СИАОДЛаба5\\keys.txt";
            newTree.Create(filename);
            Console.WriteLine("Enter operation key: I-insert node, D - delete node, M - find node with greatest key, E - find node with preferable key, P - print tree, O - Exit");
            Switch:
            string Alpha = Console.ReadLine();
                switch (Alpha)
                {
                    case "I":
                        Console.WriteLine("enter key of the node you eant to insert: ");
                        int Ikey = Convert.ToInt32(Console.ReadLine());
                        Tree.Node current = newTree.root;
                        newTree.Insert(Ikey, ref newTree.root, ref current);
                        goto Switch;
                    case "D":
                    Console.WriteLine("enter key of the node you eant to delete: ");
                    int Dkey = Convert.ToInt32(Console.ReadLine());
                    newTree.DeleteNode(Dkey, ref newTree.root);
                    goto Switch;
                    case "M":
                        newTree.MaximalKey(newTree.root);
                        Console.WriteLine("Maximal node with key: {0} that is situated on {1} level", newTree.maximalKey, newTree.maximalKeyLevel);
                    goto Switch;
                case "E":
                        Console.WriteLine("Enter the key you want to find in current tree: ");
                        int Lkey = Convert.ToInt32(Console.ReadLine());
                        newTree.ElementSearch(newTree.root, Lkey);
                    goto Switch;
                case "P":
                        newTree.SymmetryMove(newTree.root);
                    goto Switch;
                case "O":
                        break;
                }
                Console.ReadLine();
                return;
            }
        }
    }
class Tree
{
    public class Node
    {
        public int Key;
        public Node PtrnodeL = null;
        public Node PtrnodeR = null;
    }
    public void Create(string filename)
    {
        FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);
        StreamReader reader = new StreamReader(file);
        string dupl;
        int key;
        ref Node Current = ref root;
        while ((dupl = reader.ReadLine()) != null)
        {
            key = Convert.ToInt32(dupl);
            Insert(key, ref root, ref Current);
        }
    }
    public void Insert(int key, ref Node root, ref Node current)
    {
        if (root == null)
        {
            root = new Node();
            root.Key = key;
            return;
        }
        if (current == null)
        {
            current = new Node();
            current.Key = key;
            return;
        }
        if (key < current.Key)
            Insert(key, ref root, ref current.PtrnodeL);
        else if (key > current.Key)
            Insert(key, ref root, ref current.PtrnodeR);
        else if (key == current.Key)
            Console.WriteLine("Tree has already contained node with such key {0} ", key);
        else
            return;
    }
    public void SymmetryMove(Node node)
    {
        if (node == null)
            return;
        SymmetryMove(node.PtrnodeL);
        Console.WriteLine("Current node with key: {0}", node.Key);
        SymmetryMove(node.PtrnodeR);
    }
    public void MaximalKey(Node node)
    {
        if (node == null)
            return;
        levelCounter++;
        MaximalKey(node.PtrnodeL);
        if (maximalKey < node.Key)
        {
            maximalKey = node.Key;
            maximalKeyLevel = levelCounter;
        }
        MaximalKey(node.PtrnodeR);
        levelCounter--;
    }

    public void ElementSearch(Node node, int key)
    {
        bool flag = false;
        levelCounter = 0;
        ElementSearchBrunch(node, key, ref flag);
        if (!flag)
        {
            Console.WriteLine("This tree doesn't contain node with such key");
        }
        else
        {
            flag = false;
            levelCounter = 0;
        }
    }
    private void ElementSearchBrunch(Node node, int key, ref bool flag)
    {
        if (node == null)
            return;
        levelCounter++;
        ElementSearchBrunch(node.PtrnodeL, key, ref flag);
        if (key == node.Key)
        {
            Console.WriteLine("Key has been found! It's level: {0}", levelCounter);
            flag = true;
            maximalKeyLevel = levelCounter;
            return;
        }
        ElementSearchBrunch(node.PtrnodeR, key, ref flag);
        levelCounter--;
    }
    public void DeleteNode(int key, ref Node node)
    {
        Node buffer = null;
        Node del = null;
        bool exist = false;
        DeleteNodeSearch(key, ref buffer, ref node, ref del, exist);
        if (del != null && buffer == null)
            Console.WriteLine("Deletable Element: {0} and it's root", del.Key);
        else if (del == null && buffer == null)
        {
            Console.WriteLine("This tree doesn't contain node with such key");
            return;
        }
        else
            Console.WriteLine("Deletable Element: {0} and it's ancestor {1}", del.Key, buffer.Key);
        if (del.PtrnodeL == null && del.PtrnodeR == null)
        {
            if (buffer.PtrnodeL == del)
            {
                del = null;
                buffer.PtrnodeL = null;
            }
            else if (buffer.PtrnodeR == del)
            {
                del = null;
                buffer.PtrnodeR = null;
            }
            else
            {
                Console.WriteLine("Tree contained only one node! Tree has been deleted!");
                del = null;
            }
        }
        else if (del.PtrnodeL == null && del.PtrnodeR != null)
        {
            if (buffer.PtrnodeL == del)
            {
                buffer.PtrnodeL = del.PtrnodeR;
                del = null;
            }
            else if (buffer.PtrnodeR == del)
            {
                buffer.PtrnodeR = del.PtrnodeR;
                del = null;
            }
            else
            {
                root = del.PtrnodeR;
                del = null;
            }
        }
        else if (del.PtrnodeR == null && del.PtrnodeL != null)
        {
            if (buffer.PtrnodeL == del)
            {
                buffer.PtrnodeL = del.PtrnodeL;
                del = null;
            }
            else if (buffer.PtrnodeR == del)
            {
                buffer.PtrnodeR = del.PtrnodeL;
                del = null;
            }
            else
            {
                root = del.PtrnodeL;
                del = null;
            }
        }
        else if (del.PtrnodeL != null && del.PtrnodeR != null)
        {
            bool cycleFlag = false;
            Node nodeReplacer;
            Node nodePrev = del;
            nodeReplacer = del.PtrnodeL;
            while (nodeReplacer.PtrnodeR != null)
            {
                nodePrev = nodeReplacer;
                nodeReplacer = nodeReplacer.PtrnodeR;
                cycleFlag = true;
            }
            del.Key = nodeReplacer.Key;
            if (!cycleFlag)
            {
                if (nodeReplacer.PtrnodeL != null)
                {
                    nodePrev.PtrnodeL = nodeReplacer.PtrnodeL;
                    return;
                }
                else
                {
                    nodePrev.PtrnodeL = null;
                    return;
                }
            }
            if (nodeReplacer.PtrnodeL != null)
            {
                nodePrev.PtrnodeR = nodeReplacer.PtrnodeL;
            }
            else
            {
                nodePrev.PtrnodeR = null;
            }
        }
        del = null;
    }
    private void DeleteNodeSearch(int key, ref Node buffer, ref Node current, ref Node del, bool exist)
    {

        if (current == null)
        {
            return;
        }

        if (current.Key == key)
        {
            del = current;
            exist = true;
            return;
        }

        if (del == null)
            buffer = current;
        DeleteNodeSearch(key, ref buffer, ref current.PtrnodeL, ref del, exist);
        if (del == null)
            buffer = current;
        DeleteNodeSearch(key, ref buffer, ref current.PtrnodeR, ref del, exist);

    }
    public Node root = null;
    public int maximalKey { get; set; }
    public int maximalKeyLevel;
    public int levelCounter { get; set; }
    public Tree()
    {
        root = null;
        levelCounter = 0;
    }
}