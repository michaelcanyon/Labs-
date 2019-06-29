namespace Practice4Semm
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea8 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend8 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series8 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.StudName = new System.Windows.Forms.TextBox();
            this.Language = new System.Windows.Forms.TextBox();
            this.Avg = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Add = new System.Windows.Forms.Button();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.ReadList = new System.Windows.Forms.Button();
            this.Sort = new System.Windows.Forms.Button();
            this.Write = new System.Windows.Forms.Button();
            this.Birth = new System.Windows.Forms.MaskedTextBox();
            this.Doc = new System.Windows.Forms.MaskedTextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // StudName
            // 
            this.StudName.Location = new System.Drawing.Point(13, 45);
            this.StudName.Name = "StudName";
            this.StudName.Size = new System.Drawing.Size(100, 20);
            this.StudName.TabIndex = 0;
            this.StudName.Text = "Name";
            // 
            // Language
            // 
            this.Language.Location = new System.Drawing.Point(331, 45);
            this.Language.Name = "Language";
            this.Language.Size = new System.Drawing.Size(100, 20);
            this.Language.TabIndex = 3;
            this.Language.Text = "Language";
            // 
            // Avg
            // 
            this.Avg.Location = new System.Drawing.Point(437, 45);
            this.Avg.Name = "Avg";
            this.Avg.Size = new System.Drawing.Size(100, 20);
            this.Avg.TabIndex = 4;
            this.Avg.Text = "AvgGrade";
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5});
            this.dataGridView1.Location = new System.Drawing.Point(13, 74);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(544, 196);
            this.dataGridView1.TabIndex = 5;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // Column1
            // 
            this.Column1.HeaderText = "Name";
            this.Column1.Name = "Column1";
            // 
            // Column2
            // 
            this.Column2.HeaderText = "BirthDate";
            this.Column2.Name = "Column2";
            // 
            // Column3
            // 
            this.Column3.HeaderText = "DocNumber";
            this.Column3.Name = "Column3";
            // 
            // Column4
            // 
            this.Column4.HeaderText = "Language";
            this.Column4.Name = "Column4";
            // 
            // Column5
            // 
            this.Column5.HeaderText = "AvgGrade";
            this.Column5.Name = "Column5";
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(579, 12);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(75, 23);
            this.Add.TabIndex = 6;
            this.Add.Text = "Add";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.button1_Click);
            // 
            // chart1
            // 
            chartArea8.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea8);
            legend8.Name = "Legend1";
            this.chart1.Legends.Add(legend8);
            this.chart1.Location = new System.Drawing.Point(579, 45);
            this.chart1.Name = "chart1";
            this.chart1.Palette = System.Windows.Forms.DataVisualization.Charting.ChartColorPalette.Berry;
            series8.ChartArea = "ChartArea1";
            series8.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Pie;
            series8.Legend = "Legend1";
            series8.Name = "Series1";
            series8.YValuesPerPoint = 2;
            this.chart1.Series.Add(series8);
            this.chart1.Size = new System.Drawing.Size(300, 300);
            this.chart1.TabIndex = 7;
            this.chart1.Text = "chart1";
            this.chart1.Click += new System.EventHandler(this.chart1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(10, 293);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(544, 20);
            this.textBox1.TabIndex = 8;
            // 
            // ReadList
            // 
            this.ReadList.Location = new System.Drawing.Point(10, 341);
            this.ReadList.Name = "ReadList";
            this.ReadList.Size = new System.Drawing.Size(75, 23);
            this.ReadList.TabIndex = 9;
            this.ReadList.Text = "ReadList";
            this.ReadList.UseVisualStyleBackColor = true;
            this.ReadList.Click += new System.EventHandler(this.ReadList_Click);
            // 
            // Sort
            // 
            this.Sort.Location = new System.Drawing.Point(92, 341);
            this.Sort.Name = "Sort";
            this.Sort.Size = new System.Drawing.Size(75, 23);
            this.Sort.TabIndex = 10;
            this.Sort.Text = "Sort";
            this.Sort.UseVisualStyleBackColor = true;
            this.Sort.Click += new System.EventHandler(this.Sort_Click);
            // 
            // Write
            // 
            this.Write.Location = new System.Drawing.Point(173, 341);
            this.Write.Name = "Write";
            this.Write.Size = new System.Drawing.Size(75, 23);
            this.Write.TabIndex = 11;
            this.Write.Text = "Write";
            this.Write.UseVisualStyleBackColor = true;
            this.Write.Click += new System.EventHandler(this.button1_Click_3);
            // 
            // Birth
            // 
            this.Birth.Location = new System.Drawing.Point(119, 45);
            this.Birth.Mask = "00/00/0000";
            this.Birth.Name = "Birth";
            this.Birth.Size = new System.Drawing.Size(100, 20);
            this.Birth.TabIndex = 12;
            this.Birth.Tag = "";
            this.Birth.ValidatingType = typeof(System.DateTime);
            // 
            // Doc
            // 
            this.Doc.Location = new System.Drawing.Point(225, 45);
            this.Doc.Mask = "00/00-0000";
            this.Doc.Name = "Doc";
            this.Doc.Size = new System.Drawing.Size(100, 20);
            this.Doc.TabIndex = 13;
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox2.Enabled = false;
            this.textBox2.Location = new System.Drawing.Point(119, 26);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 13);
            this.textBox2.TabIndex = 14;
            this.textBox2.Text = "BirthDate:";
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // textBox3
            // 
            this.textBox3.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox3.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox3.Enabled = false;
            this.textBox3.Location = new System.Drawing.Point(225, 26);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 13);
            this.textBox3.TabIndex = 15;
            this.textBox3.Text = "Doc Number:";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(268, 341);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(286, 20);
            this.textBox4.TabIndex = 16;
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // textBox5
            // 
            this.textBox5.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox5.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox5.Location = new System.Drawing.Point(13, 277);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 13);
            this.textBox5.TabIndex = 17;
            this.textBox5.Text = "Read/Write Path:";
            this.textBox5.TextChanged += new System.EventHandler(this.textBox5_TextChanged);
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox6.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox6.Location = new System.Drawing.Point(268, 320);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(100, 13);
            this.textBox6.TabIndex = 18;
            this.textBox6.Text = "Diagram Write Path:";
            this.textBox6.TextChanged += new System.EventHandler(this.textBox6_TextChanged);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Английский",
            "Немецкий",
            "Французский",
            "Въетнамский",
            "Китайский",
            "Итальянский",
            "Любой язык"});
            this.comboBox1.Location = new System.Drawing.Point(127, 317);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 19;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // textBox7
            // 
            this.textBox7.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox7.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox7.Location = new System.Drawing.Point(13, 319);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(111, 13);
            this.textBox7.TabIndex = 20;
            this.textBox7.Text = "Language Fileprint:";
            // 
            // Form4
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(906, 376);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.Doc);
            this.Controls.Add(this.Birth);
            this.Controls.Add(this.Write);
            this.Controls.Add(this.Sort);
            this.Controls.Add(this.ReadList);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.chart1);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.Avg);
            this.Controls.Add(this.Language);
            this.Controls.Add(this.StudName);
            this.Name = "Form4";
            this.Text = "Form4";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox StudName;
        private System.Windows.Forms.TextBox Language;
        private System.Windows.Forms.TextBox Avg;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button ReadList;
        private System.Windows.Forms.Button Sort;
        private System.Windows.Forms.Button Write;
        private System.Windows.Forms.MaskedTextBox Birth;
        private System.Windows.Forms.MaskedTextBox Doc;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.TextBox textBox7;
    }
}