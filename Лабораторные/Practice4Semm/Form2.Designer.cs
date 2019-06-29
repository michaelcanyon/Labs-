namespace Practice4Semm
{
    partial class Form2
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.Task = new System.Windows.Forms.PictureBox();
            this.FilePath = new System.Windows.Forms.TextBox();
            this.X1 = new System.Windows.Forms.TextBox();
            this.X2 = new System.Windows.Forms.TextBox();
            this.X3 = new System.Windows.Forms.TextBox();
            this.B = new System.Windows.Forms.TextBox();
            this.P2 = new System.Windows.Forms.TextBox();
            this.P1 = new System.Windows.Forms.TextBox();
            this.Confirm = new System.Windows.Forms.Button();
            this.Graphic1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.Aparam = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.Task)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Graphic1)).BeginInit();
            this.SuspendLayout();
            // 
            // Task
            // 
            this.Task.Image = ((System.Drawing.Image)(resources.GetObject("Task.Image")));
            this.Task.Location = new System.Drawing.Point(0, 0);
            this.Task.Name = "Task";
            this.Task.Size = new System.Drawing.Size(211, 111);
            this.Task.TabIndex = 0;
            this.Task.TabStop = false;
            this.Task.Click += new System.EventHandler(this.Task_Click);
            // 
            // FilePath
            // 
            this.FilePath.Location = new System.Drawing.Point(0, 473);
            this.FilePath.Name = "FilePath";
            this.FilePath.Size = new System.Drawing.Size(776, 20);
            this.FilePath.TabIndex = 1;
            this.FilePath.Text = "Enter the file path";
            this.FilePath.TextChanged += new System.EventHandler(this.FilePath_TextChanged);
            // 
            // X1
            // 
            this.X1.Location = new System.Drawing.Point(72, 117);
            this.X1.Name = "X1";
            this.X1.Size = new System.Drawing.Size(53, 20);
            this.X1.TabIndex = 2;
            // 
            // X2
            // 
            this.X2.Location = new System.Drawing.Point(12, 117);
            this.X2.Name = "X2";
            this.X2.Size = new System.Drawing.Size(54, 20);
            this.X2.TabIndex = 3;
            // 
            // X3
            // 
            this.X3.Location = new System.Drawing.Point(71, 143);
            this.X3.Name = "X3";
            this.X3.Size = new System.Drawing.Size(53, 20);
            this.X3.TabIndex = 4;
            this.X3.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // B
            // 
            this.B.Location = new System.Drawing.Point(12, 169);
            this.B.Name = "B";
            this.B.Size = new System.Drawing.Size(53, 20);
            this.B.TabIndex = 5;
            // 
            // P2
            // 
            this.P2.Location = new System.Drawing.Point(70, 169);
            this.P2.Name = "P2";
            this.P2.Size = new System.Drawing.Size(54, 20);
            this.P2.TabIndex = 6;
            // 
            // P1
            // 
            this.P1.Location = new System.Drawing.Point(13, 143);
            this.P1.Name = "P1";
            this.P1.Size = new System.Drawing.Size(53, 20);
            this.P1.TabIndex = 7;
            // 
            // Confirm
            // 
            this.Confirm.Location = new System.Drawing.Point(883, 499);
            this.Confirm.Name = "Confirm";
            this.Confirm.Size = new System.Drawing.Size(75, 23);
            this.Confirm.TabIndex = 8;
            this.Confirm.Text = "Confirm";
            this.Confirm.UseVisualStyleBackColor = true;
            this.Confirm.Click += new System.EventHandler(this.Confirm_Click);
            // 
            // Graphic1
            // 
            chartArea1.Name = "ChartArea1";
            this.Graphic1.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.Graphic1.Legends.Add(legend1);
            this.Graphic1.Location = new System.Drawing.Point(217, 0);
            this.Graphic1.Name = "Graphic1";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series1.Color = System.Drawing.Color.SteelBlue;
            series1.Legend = "Legend1";
            series1.Name = "Func";
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series2.Legend = "Legend1";
            series2.Name = "Series2";
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series3.Legend = "Legend1";
            series3.Name = "Series3";
            this.Graphic1.Series.Add(series1);
            this.Graphic1.Series.Add(series2);
            this.Graphic1.Series.Add(series3);
            this.Graphic1.Size = new System.Drawing.Size(741, 467);
            this.Graphic1.TabIndex = 10;
            this.Graphic1.Text = "chart1";
            title1.Name = "Title1";
            title1.Text = "Графическое представление функции";
            this.Graphic1.Titles.Add(title1);
            this.Graphic1.Click += new System.EventHandler(this.Graphic1_Click);
            this.Graphic1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Graphic1_MouseMove);
            // 
            // Aparam
            // 
            this.Aparam.Location = new System.Drawing.Point(12, 195);
            this.Aparam.Name = "Aparam";
            this.Aparam.Size = new System.Drawing.Size(53, 20);
            this.Aparam.TabIndex = 11;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(0, 499);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(776, 20);
            this.textBox1.TabIndex = 12;
            this.textBox1.Text = "Enter output filepath";
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(970, 534);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.Aparam);
            this.Controls.Add(this.Graphic1);
            this.Controls.Add(this.Confirm);
            this.Controls.Add(this.P1);
            this.Controls.Add(this.P2);
            this.Controls.Add(this.B);
            this.Controls.Add(this.X3);
            this.Controls.Add(this.X2);
            this.Controls.Add(this.X1);
            this.Controls.Add(this.FilePath);
            this.Controls.Add(this.Task);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.Task)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Graphic1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox Task;
        private System.Windows.Forms.TextBox FilePath;
        private System.Windows.Forms.TextBox X1;
        private System.Windows.Forms.TextBox X2;
        private System.Windows.Forms.TextBox X3;
        private System.Windows.Forms.TextBox B;
        private System.Windows.Forms.TextBox P2;
        private System.Windows.Forms.TextBox P1;
        private System.Windows.Forms.Button Confirm;
        private System.Windows.Forms.DataVisualization.Charting.Chart Graphic1;
        private System.Windows.Forms.TextBox Aparam;
        private System.Windows.Forms.TextBox textBox1;
    }
}