namespace MevLab
{
    partial class Form4
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.ChildName = new System.Windows.Forms.TextBox();
            this.ReadEstate = new System.Windows.Forms.TextBox();
            this.biolFather = new System.Windows.Forms.ComboBox();
            this.BiolParentName = new System.Windows.Forms.TextBox();
            this.Prison = new System.Windows.Forms.CheckBox();
            this.PrisonPlace = new System.Windows.Forms.TextBox();
            this.TakenParRights = new System.Windows.Forms.CheckBox();
            this.ParentDead = new System.Windows.Forms.CheckBox();
            this.Illnesses = new System.Windows.Forms.RichTextBox();
            this.Vaccined = new System.Windows.Forms.RichTextBox();
            this.medicalCheck = new System.Windows.Forms.MaskedTextBox();
            this.ParentBirth = new System.Windows.Forms.MaskedTextBox();
            this.ChildBirth = new System.Windows.Forms.MaskedTextBox();
            this.ShelterDate = new System.Windows.Forms.MaskedTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.biolMother = new System.Windows.Forms.ComboBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(568, 192);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(12, 210);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(568, 160);
            this.dataGridView2.TabIndex = 1;
            // 
            // dataGridView3
            // 
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Location = new System.Drawing.Point(12, 376);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.RowHeadersWidth = 51;
            this.dataGridView3.RowTemplate.Height = 24;
            this.dataGridView3.Size = new System.Drawing.Size(568, 180);
            this.dataGridView3.TabIndex = 2;
            this.dataGridView3.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView3_CellContentClick);
            // 
            // ChildName
            // 
            this.ChildName.Location = new System.Drawing.Point(918, 33);
            this.ChildName.Name = "ChildName";
            this.ChildName.Size = new System.Drawing.Size(148, 22);
            this.ChildName.TabIndex = 3;
            this.ChildName.TextChanged += new System.EventHandler(this.ChildBirth_TextChanged);
            // 
            // ReadEstate
            // 
            this.ReadEstate.Location = new System.Drawing.Point(918, 185);
            this.ReadEstate.Name = "ReadEstate";
            this.ReadEstate.Size = new System.Drawing.Size(148, 22);
            this.ReadEstate.TabIndex = 6;
            this.ReadEstate.TextChanged += new System.EventHandler(this.ReadEstate_TextChanged);
            // 
            // biolFather
            // 
            this.biolFather.FormattingEnabled = true;
            this.biolFather.Location = new System.Drawing.Point(918, 281);
            this.biolFather.Name = "biolFather";
            this.biolFather.Size = new System.Drawing.Size(148, 24);
            this.biolFather.TabIndex = 7;
            this.biolFather.SelectedIndexChanged += new System.EventHandler(this.biolFather_SelectedIndexChanged);
            // 
            // BiolParentName
            // 
            this.BiolParentName.Location = new System.Drawing.Point(922, 329);
            this.BiolParentName.Name = "BiolParentName";
            this.BiolParentName.Size = new System.Drawing.Size(155, 22);
            this.BiolParentName.TabIndex = 10;
            // 
            // Prison
            // 
            this.Prison.AutoSize = true;
            this.Prison.Location = new System.Drawing.Point(922, 424);
            this.Prison.Name = "Prison";
            this.Prison.Size = new System.Drawing.Size(170, 21);
            this.Prison.TabIndex = 11;
            this.Prison.Text = "Отбывает наказание";
            this.Prison.UseVisualStyleBackColor = true;
            // 
            // PrisonPlace
            // 
            this.PrisonPlace.Location = new System.Drawing.Point(922, 526);
            this.PrisonPlace.Name = "PrisonPlace";
            this.PrisonPlace.Size = new System.Drawing.Size(155, 22);
            this.PrisonPlace.TabIndex = 12;
            // 
            // TakenParRights
            // 
            this.TakenParRights.AutoSize = true;
            this.TakenParRights.Location = new System.Drawing.Point(922, 451);
            this.TakenParRights.Name = "TakenParRights";
            this.TakenParRights.Size = new System.Drawing.Size(138, 21);
            this.TakenParRights.TabIndex = 13;
            this.TakenParRights.Text = "Лишен род.прав";
            this.TakenParRights.UseVisualStyleBackColor = true;
            this.TakenParRights.CheckedChanged += new System.EventHandler(this.checkBox2_CheckedChanged);
            // 
            // ParentDead
            // 
            this.ParentDead.AutoSize = true;
            this.ParentDead.Location = new System.Drawing.Point(922, 478);
            this.ParentDead.Name = "ParentDead";
            this.ParentDead.Size = new System.Drawing.Size(71, 21);
            this.ParentDead.TabIndex = 14;
            this.ParentDead.Text = "Мертв";
            this.ParentDead.UseVisualStyleBackColor = true;
            // 
            // Illnesses
            // 
            this.Illnesses.Location = new System.Drawing.Point(600, 30);
            this.Illnesses.Name = "Illnesses";
            this.Illnesses.Size = new System.Drawing.Size(258, 93);
            this.Illnesses.TabIndex = 15;
            this.Illnesses.Text = "";
            // 
            // Vaccined
            // 
            this.Vaccined.Location = new System.Drawing.Point(600, 151);
            this.Vaccined.Name = "Vaccined";
            this.Vaccined.Size = new System.Drawing.Size(258, 98);
            this.Vaccined.TabIndex = 16;
            this.Vaccined.Text = "";
            // 
            // medicalCheck
            // 
            this.medicalCheck.Location = new System.Drawing.Point(600, 286);
            this.medicalCheck.Mask = "00/00/0000";
            this.medicalCheck.Name = "medicalCheck";
            this.medicalCheck.Size = new System.Drawing.Size(100, 22);
            this.medicalCheck.TabIndex = 17;
            this.medicalCheck.ValidatingType = typeof(System.DateTime);
            // 
            // ParentBirth
            // 
            this.ParentBirth.Location = new System.Drawing.Point(922, 373);
            this.ParentBirth.Mask = "00/00/0000";
            this.ParentBirth.Name = "ParentBirth";
            this.ParentBirth.Size = new System.Drawing.Size(155, 22);
            this.ParentBirth.TabIndex = 18;
            this.ParentBirth.ValidatingType = typeof(System.DateTime);
            // 
            // ChildBirth
            // 
            this.ChildBirth.Location = new System.Drawing.Point(918, 77);
            this.ChildBirth.Mask = "00/00/0000";
            this.ChildBirth.Name = "ChildBirth";
            this.ChildBirth.Size = new System.Drawing.Size(148, 22);
            this.ChildBirth.TabIndex = 19;
            this.ChildBirth.ValidatingType = typeof(System.DateTime);
            this.ChildBirth.MaskInputRejected += new System.Windows.Forms.MaskInputRejectedEventHandler(this.maskedTextBox3_MaskInputRejected);
            // 
            // ShelterDate
            // 
            this.ShelterDate.Location = new System.Drawing.Point(918, 132);
            this.ShelterDate.Mask = "00/00/0000";
            this.ShelterDate.Name = "ShelterDate";
            this.ShelterDate.Size = new System.Drawing.Size(148, 22);
            this.ShelterDate.TabIndex = 20;
            this.ShelterDate.ValidatingType = typeof(System.DateTime);
            this.ShelterDate.MaskInputRejected += new System.Windows.Forms.MaskInputRejectedEventHandler(this.ShelterDate_MaskInputRejected);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(597, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(197, 17);
            this.label1.TabIndex = 21;
            this.label1.Text = "Перенесенные заболевания";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(597, 129);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 17);
            this.label2.TabIndex = 22;
            this.label2.Text = "Прививки";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(597, 266);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(303, 17);
            this.label3.TabIndex = 23;
            this.label3.Text = "Дата последнего мед. освидетельствования";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(919, 308);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(110, 17);
            this.label4.TabIndex = 24;
            this.label4.Text = "Родитель. Имя:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(919, 353);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 17);
            this.label5.TabIndex = 25;
            this.label5.Text = "Дата рождения:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(919, 502);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(137, 17);
            this.label6.TabIndex = 26;
            this.label6.Text = "Место заключения:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(915, 12);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(103, 17);
            this.label7.TabIndex = 27;
            this.label7.Text = "Ребёнок. Имя:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(915, 57);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(115, 17);
            this.label8.TabIndex = 28;
            this.label8.Text = "Дата рождения:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(919, 112);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(187, 17);
            this.label9.TabIndex = 29;
            this.label9.Text = "Дата поступления в приют";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(915, 164);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(165, 17);
            this.label10.TabIndex = 30;
            this.label10.Text = "Данные о жил.площади";
            // 
            // biolMother
            // 
            this.biolMother.FormattingEnabled = true;
            this.biolMother.Location = new System.Drawing.Point(918, 230);
            this.biolMother.Name = "biolMother";
            this.biolMother.Size = new System.Drawing.Size(148, 24);
            this.biolMother.TabIndex = 31;
            this.biolMother.SelectedIndexChanged += new System.EventHandler(this.biolMother_SelectedIndexChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(918, 210);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(81, 17);
            this.label11.TabIndex = 32;
            this.label11.Text = "биол. Мать";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(918, 257);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(82, 17);
            this.label12.TabIndex = 33;
            this.label12.Text = "биол. Отец";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1104, 525);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(163, 23);
            this.button1.TabIndex = 34;
            this.button1.Text = "Добавить родителя";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(1114, 281);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(163, 23);
            this.button2.TabIndex = 35;
            this.button2.Text = "Добавить запись";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form4
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1322, 568);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.biolMother);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ShelterDate);
            this.Controls.Add(this.ChildBirth);
            this.Controls.Add(this.ParentBirth);
            this.Controls.Add(this.medicalCheck);
            this.Controls.Add(this.Vaccined);
            this.Controls.Add(this.Illnesses);
            this.Controls.Add(this.ParentDead);
            this.Controls.Add(this.TakenParRights);
            this.Controls.Add(this.PrisonPlace);
            this.Controls.Add(this.Prison);
            this.Controls.Add(this.BiolParentName);
            this.Controls.Add(this.biolFather);
            this.Controls.Add(this.ReadEstate);
            this.Controls.Add(this.ChildName);
            this.Controls.Add(this.dataGridView3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form4";
            this.Text = "Form4";
            this.Load += new System.EventHandler(this.Form4_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.DataGridView dataGridView3;
        private System.Windows.Forms.TextBox ChildName;
        private System.Windows.Forms.TextBox ReadEstate;
        private System.Windows.Forms.ComboBox biolFather;
        private System.Windows.Forms.TextBox BiolParentName;
        private System.Windows.Forms.CheckBox Prison;
        private System.Windows.Forms.TextBox PrisonPlace;
        private System.Windows.Forms.CheckBox TakenParRights;
        private System.Windows.Forms.CheckBox ParentDead;
        private System.Windows.Forms.RichTextBox Illnesses;
        private System.Windows.Forms.RichTextBox Vaccined;
        private System.Windows.Forms.MaskedTextBox medicalCheck;
        private System.Windows.Forms.MaskedTextBox ParentBirth;
        private System.Windows.Forms.MaskedTextBox ChildBirth;
        private System.Windows.Forms.MaskedTextBox ShelterDate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox biolMother;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}