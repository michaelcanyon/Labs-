using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;
using System.Diagnostics;
using System.IO;

namespace MevLab
{
    public partial class Form4 : Form
    {
        const int SUPREMUM = 99999;
        public Form4()
        {
            InitializeComponent();
        }
        private void Form4_Load(object sender, EventArgs e)
        {
            if (!File.Exists(@"C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db"))
            {
                SQLiteConnection.CreateFile(@"C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db");
            }
            using (SQLiteConnection Connect = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;"))
            {
                string com1, com2, com3;
                com1 = " CREATE TABLE IF NOT EXISTS [Children] " +
                       "( [Id] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," +
                       "[Имя] TEXT," +
                       "[Дата рождения] TEXT," +
                       "[Дата распоряжения об отправке в дет.дом] TEXT," +
                       "[Жил.Площадь] TEXT," +
                       "[Id_отца] INTEGER," +
                       "[Id_матери] INTEGER," +
                       "[Id_медкарты] INTEGER)";

                com2 = " CREATE TABLE IF NOT EXISTS [Parents] " +
                      "( [Id] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," +
                      "[Имя] TEXT," +
                      "[Дата рождения] TEXT," +
                      "[Отбывает наказание] INTEGER," +
                      "[Место заключения] TEXT," +
                      "[Мёртв] INTEGER," +
                      "[Лишен род.прав] INTEGER)"
                      ;
                com3 = " CREATE TABLE IF NOT EXISTS [Medcard] " +
                      "( [Id] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," +
                      "[Перенесенные заболевания] TEXT," +
                      "[Прививки] TEXT," +
                      "[Последнее мед.освидетельствование] TEXT)"
                      ;
                SQLiteCommand command = new SQLiteCommand(com1, Connect);
                Connect.Open(); // открыть соединение
                command.ExecuteNonQuery(); // выполнить запрос
                command = new SQLiteCommand(com2, Connect);
                command.ExecuteNonQuery();
                command = new SQLiteCommand(com3, Connect);
                command.ExecuteNonQuery();
                Connect.Close();

                SQLiteCommand command5 = new SQLiteCommand("SELECT * FROM Children", Connect);
                Connect.Open();
                SQLiteDataReader dr3 = command5.ExecuteReader(CommandBehavior.CloseConnection);
                DataTable dt3 = new DataTable();
                dt3.Load(dr3);
                dataGridView1.DataSource = dt3;

                SQLiteConnection cnn = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;");
                SQLiteCommand cmd = new SQLiteCommand("SELECT * FROM Parents", cnn);
                cnn.Open();
                SQLiteDataReader dr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
                DataTable dt = new DataTable();
                dt.Load(dr);
                dataGridView2.DataSource = dt;
                biolFather.Items.Add("Неизвестен");
                biolMother.Items.Add("Неизвестна");
                for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
                {
                    biolFather.Items.Add(dataGridView2[1, i].Value);
                    biolMother.Items.Add(dataGridView2[1, i].Value);
                }
            }
        }
        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
        }
        private void label3_Click(object sender, EventArgs e)
        {
        }
        private void button1_Click(object sender, EventArgs e)
        {
            using (SQLiteConnection Connect = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;"))
            {
                string name, jailPlace, birthDate;
                int jail, dead, takenRights;
                name = BiolParentName.Text;
                birthDate = ParentBirth.Text;
                jail = Convert.ToInt32(Prison.Checked);
                if (jail != 0)
                    jailPlace = PrisonPlace.Text;
                else
                    jailPlace = "None";
                dead = Convert.ToInt32(ParentDead.Checked);
                takenRights = Convert.ToInt32(TakenParRights.Checked);
                string com1;
                com1 = " INSERT INTO [Parents] ([Имя], [Дата рождения], [Отбывает наказание],[Место заключения],[Мёртв],[Лишен род.прав]) " +
                      "VALUES (@name, @birthDate,@jail,@jailPlace,@dead,@takenRights)";
                SQLiteCommand Command = new SQLiteCommand(com1, Connect);
                Command.Parameters.AddWithValue("@name", name);
                Command.Parameters.AddWithValue("@birthDate", birthDate);
                Command.Parameters.AddWithValue("@jail", jail);
                Command.Parameters.AddWithValue("@jailPlace", jailPlace);
                Command.Parameters.AddWithValue("@dead", dead);
                Command.Parameters.AddWithValue("@takenRights", takenRights);
                Connect.Open();
                Command.ExecuteNonQuery();
                Connect.Close();
                biolFather.Items.Add(name);
                biolMother.Items.Add(name);
            }
            SQLiteConnection cnn = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;");
            SQLiteCommand cmd = new SQLiteCommand("SELECT * FROM Parents", cnn);
            cnn.Open();
            SQLiteDataReader dr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView2.DataSource = dt;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (Illnesses.Text == "" || Vaccined.Text == "" || medicalCheck.Text == "" || ChildName.Text == "" || ChildBirth.Text == ""
                || ReadEstate.Text == "" || biolMother.Text == "" || biolFather.Text == "")
            {
                MessageBox.Show("Пожалуйста, заполните все необходимые поля.");
                return;
            }
            using (SQLiteConnection Connect = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;"))
            {
                string name, birthDate, arrivalDate, propertyAdress;
                int bioMotherId, bioFatherID, MedCardID;
                ////mother\father IDs
                if (biolMother.Text == "Неизвестна")
                    bioMotherId = SUPREMUM;
                else
                {
                    string comForMother = "SELECT * FROM [Parents] WHERE [Имя] = @name";
                    SQLiteCommand Command1 = new SQLiteCommand(comForMother, Connect);
                    Command1.Parameters.AddWithValue("@name", biolMother.Text);
                    Connect.Open();
                    SQLiteDataReader dre = Command1.ExecuteReader(CommandBehavior.CloseConnection);
                    DataTable dt1 = new DataTable();
                    dt1.Load(dre);
                    bioMotherId = Convert.ToInt32(dt1.Rows[0][0]);
                    Connect.Close();
                }
                if (biolFather.Text == "Неизвестен")
                    bioFatherID = SUPREMUM;
                else
                {
                    string comForMother = "SELECT * FROM [Parents] WHERE [Имя] = @name";
                    SQLiteCommand Command1 = new SQLiteCommand(comForMother, Connect);
                    Command1.Parameters.AddWithValue("@name", biolFather.Text);
                    Connect.Open();
                    SQLiteDataReader dre = Command1.ExecuteReader(CommandBehavior.CloseConnection);
                    DataTable dt1 = new DataTable();
                    dt1.Load(dre);
                    bioFatherID = Convert.ToInt32(dt1.Rows[0][0]);
                    Connect.Close();
                }
                //////
                ///
                birthDate = ChildBirth.Text;
                arrivalDate = ShelterDate.Text;
                name = ChildName.Text;
                propertyAdress = ReadEstate.Text;
                if (propertyAdress == null)
                    propertyAdress = "None";

                /////MedcardID
                string comQua = "SELECT * FROM [Medcard]";
                SQLiteCommand Command2 = new SQLiteCommand(comQua, Connect);
                Connect.Open();
                SQLiteDataReader drqua = Command2.ExecuteReader(CommandBehavior.CloseConnection);
                DataTable dt2 = new DataTable();
                dt2.Load(drqua);
                MedCardID = dt2.Rows.Count + 1;
                Connect.Close();
                /////
                string com1;
                com1 = " INSERT INTO [Children] ([Имя], [Дата рождения], [Дата распоряжения об отправке в дет.дом],[Жил.Площадь],[Id_отца],[Id_матери],[Id_медкарты])" +
                      "VALUES (@name, @birthDate,@ArrivalDate,@Property,@FID,@MothId,@MedID)";
                SQLiteCommand Command = new SQLiteCommand(com1, Connect);
                Command.Parameters.AddWithValue("@name", name);
                Command.Parameters.AddWithValue("@birthDate", birthDate);
                Command.Parameters.AddWithValue("@ArrivalDate", arrivalDate);
                Command.Parameters.AddWithValue("@Property", propertyAdress);
                Command.Parameters.AddWithValue("@FID", bioFatherID);
                Command.Parameters.AddWithValue("@MothId", bioMotherId);
                Command.Parameters.AddWithValue("@MedID", MedCardID);
                Connect.Open();
                Command.ExecuteNonQuery();
                Connect.Close();
            }

            SQLiteConnection cnn = new SQLiteConnection(@"Data Source=C:\Users\Michael\Documents\GitHub\Labs-\MevLab\ShelterDb.db; Version=3;");
            SQLiteCommand cmd = new SQLiteCommand("SELECT * FROM Children", cnn);
            cnn.Open();
            SQLiteDataReader dr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView1.DataSource = dt;
            SQLiteCommand cmd2 = new SQLiteCommand("INSERT INTO [Medcard] ([Перенесенные заболевания],[Прививки],[Последнее мед.освидетельствование])" +
                " VALUES(@Illneses,@Vaccines,@MedInspection)", cnn);
            cmd2.Parameters.AddWithValue("@Illneses", Illnesses.Text);
            cmd2.Parameters.AddWithValue("@Vaccines", Vaccined.Text);
            cmd2.Parameters.AddWithValue("@MedInspection", medicalCheck.Text);
            cnn.Open();
            cmd2.ExecuteNonQuery();
            cnn.Close();
            cmd = new SQLiteCommand("SELECT * FROM [Medcard]", cnn);
            cnn.Open();
            dr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            dt = new DataTable();
            dt.Load(dr);
            dataGridView3.DataSource = dt;
        }

        private void biolFather_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void biolMother_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void ShelterDate_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
        }

        private void ChildBirth_TextChanged(object sender, EventArgs e)
        {
        }

        private void maskedTextBox3_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
        }

        private void ReadEstate_TextChanged(object sender, EventArgs e)
        {
        }
        private void dataGridView3_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }
    }
}
