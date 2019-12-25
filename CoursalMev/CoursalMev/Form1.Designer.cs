namespace CoursalMev
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.ContentGrid = new System.Windows.Forms.DataGridView();
            this.Infrom_SourceGrid = new System.Windows.Forms.DataGridView();
            this.Source_Grid = new System.Windows.Forms.DataGridView();
            this.Genre_Grid = new System.Windows.Forms.DataGridView();
            this.AuthorGrid = new System.Windows.Forms.DataGridView();
            this.ProfessionGrid = new System.Windows.Forms.DataGridView();
            this.AddContendButton = new System.Windows.Forms.Button();
            this.GenreButton = new System.Windows.Forms.Button();
            this.AddAuthorButton = new System.Windows.Forms.Button();
            this.ContentTitle = new System.Windows.Forms.TextBox();
            this.ContentType = new System.Windows.Forms.ComboBox();
            this.ContentSource = new System.Windows.Forms.TextBox();
            this.ContentGenre = new System.Windows.Forms.ComboBox();
            this.ContentAuthor = new System.Windows.Forms.ComboBox();
            this.ContentAnnotation = new System.Windows.Forms.RichTextBox();
            this.AuthorsName = new System.Windows.Forms.MaskedTextBox();
            this.AuthorsProfession = new System.Windows.Forms.TextBox();
            this.ContentDate = new System.Windows.Forms.MaskedTextBox();
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
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.GenreBox = new System.Windows.Forms.TextBox();
            this.SelectOnPubType = new System.Windows.Forms.Button();
            this.SelectOnSource = new System.Windows.Forms.Button();
            this.SelectOnTag = new System.Windows.Forms.Button();
            this.SelectOnAuthor = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.delField = new System.Windows.Forms.MaskedTextBox();
            this.Delete_note = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ContentGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Infrom_SourceGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Source_Grid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Genre_Grid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.AuthorGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ProfessionGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // ContentGrid
            // 
            this.ContentGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ContentGrid.Location = new System.Drawing.Point(12, 12);
            this.ContentGrid.Name = "ContentGrid";
            this.ContentGrid.RowHeadersWidth = 51;
            this.ContentGrid.RowTemplate.Height = 24;
            this.ContentGrid.Size = new System.Drawing.Size(1152, 307);
            this.ContentGrid.TabIndex = 0;
            // 
            // Infrom_SourceGrid
            // 
            this.Infrom_SourceGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Infrom_SourceGrid.Location = new System.Drawing.Point(12, 343);
            this.Infrom_SourceGrid.Name = "Infrom_SourceGrid";
            this.Infrom_SourceGrid.RowHeadersWidth = 51;
            this.Infrom_SourceGrid.RowTemplate.Height = 24;
            this.Infrom_SourceGrid.Size = new System.Drawing.Size(287, 123);
            this.Infrom_SourceGrid.TabIndex = 1;
            // 
            // Source_Grid
            // 
            this.Source_Grid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Source_Grid.Location = new System.Drawing.Point(12, 501);
            this.Source_Grid.Name = "Source_Grid";
            this.Source_Grid.RowHeadersWidth = 51;
            this.Source_Grid.RowTemplate.Height = 24;
            this.Source_Grid.Size = new System.Drawing.Size(287, 116);
            this.Source_Grid.TabIndex = 2;
            // 
            // Genre_Grid
            // 
            this.Genre_Grid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Genre_Grid.Location = new System.Drawing.Point(320, 343);
            this.Genre_Grid.Name = "Genre_Grid";
            this.Genre_Grid.RowHeadersWidth = 51;
            this.Genre_Grid.RowTemplate.Height = 24;
            this.Genre_Grid.Size = new System.Drawing.Size(281, 123);
            this.Genre_Grid.TabIndex = 3;
            // 
            // AuthorGrid
            // 
            this.AuthorGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.AuthorGrid.Location = new System.Drawing.Point(320, 501);
            this.AuthorGrid.Name = "AuthorGrid";
            this.AuthorGrid.RowHeadersWidth = 51;
            this.AuthorGrid.RowTemplate.Height = 24;
            this.AuthorGrid.Size = new System.Drawing.Size(281, 116);
            this.AuthorGrid.TabIndex = 4;
            // 
            // ProfessionGrid
            // 
            this.ProfessionGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ProfessionGrid.Location = new System.Drawing.Point(620, 343);
            this.ProfessionGrid.Name = "ProfessionGrid";
            this.ProfessionGrid.RowHeadersWidth = 51;
            this.ProfessionGrid.RowTemplate.Height = 24;
            this.ProfessionGrid.Size = new System.Drawing.Size(272, 123);
            this.ProfessionGrid.TabIndex = 5;
            // 
            // AddContendButton
            // 
            this.AddContendButton.Location = new System.Drawing.Point(921, 343);
            this.AddContendButton.Name = "AddContendButton";
            this.AddContendButton.Size = new System.Drawing.Size(243, 40);
            this.AddContendButton.TabIndex = 6;
            this.AddContendButton.Text = "Добавить программу\\публикацию";
            this.AddContendButton.UseVisualStyleBackColor = true;
            this.AddContendButton.Click += new System.EventHandler(this.AddContendButton_Click);
            // 
            // GenreButton
            // 
            this.GenreButton.Location = new System.Drawing.Point(1199, 420);
            this.GenreButton.Name = "GenreButton";
            this.GenreButton.Size = new System.Drawing.Size(243, 23);
            this.GenreButton.TabIndex = 8;
            this.GenreButton.Text = "Добавить тег";
            this.GenreButton.UseVisualStyleBackColor = true;
            this.GenreButton.Click += new System.EventHandler(this.GenreButton_Click);
            // 
            // AddAuthorButton
            // 
            this.AddAuthorButton.Location = new System.Drawing.Point(921, 390);
            this.AddAuthorButton.Name = "AddAuthorButton";
            this.AddAuthorButton.Size = new System.Drawing.Size(243, 23);
            this.AddAuthorButton.TabIndex = 10;
            this.AddAuthorButton.Text = "Добавить автора";
            this.AddAuthorButton.UseVisualStyleBackColor = true;
            this.AddAuthorButton.Click += new System.EventHandler(this.AddAuthorButton_Click);
            // 
            // ContentTitle
            // 
            this.ContentTitle.Location = new System.Drawing.Point(1187, 21);
            this.ContentTitle.Name = "ContentTitle";
            this.ContentTitle.Size = new System.Drawing.Size(255, 22);
            this.ContentTitle.TabIndex = 11;
            // 
            // ContentType
            // 
            this.ContentType.FormattingEnabled = true;
            this.ContentType.Location = new System.Drawing.Point(1187, 63);
            this.ContentType.Name = "ContentType";
            this.ContentType.Size = new System.Drawing.Size(149, 24);
            this.ContentType.TabIndex = 12;
            // 
            // ContentSource
            // 
            this.ContentSource.Location = new System.Drawing.Point(1187, 109);
            this.ContentSource.Name = "ContentSource";
            this.ContentSource.Size = new System.Drawing.Size(149, 22);
            this.ContentSource.TabIndex = 13;
            // 
            // ContentGenre
            // 
            this.ContentGenre.FormattingEnabled = true;
            this.ContentGenre.Location = new System.Drawing.Point(1187, 152);
            this.ContentGenre.Name = "ContentGenre";
            this.ContentGenre.Size = new System.Drawing.Size(149, 24);
            this.ContentGenre.TabIndex = 15;
            // 
            // ContentAuthor
            // 
            this.ContentAuthor.FormattingEnabled = true;
            this.ContentAuthor.Location = new System.Drawing.Point(1186, 247);
            this.ContentAuthor.Name = "ContentAuthor";
            this.ContentAuthor.Size = new System.Drawing.Size(149, 24);
            this.ContentAuthor.TabIndex = 16;
            // 
            // ContentAnnotation
            // 
            this.ContentAnnotation.Location = new System.Drawing.Point(1187, 294);
            this.ContentAnnotation.Name = "ContentAnnotation";
            this.ContentAnnotation.Size = new System.Drawing.Size(255, 119);
            this.ContentAnnotation.TabIndex = 17;
            this.ContentAnnotation.Text = "";
            // 
            // AuthorsName
            // 
            this.AuthorsName.Location = new System.Drawing.Point(620, 547);
            this.AuthorsName.Name = "AuthorsName";
            this.AuthorsName.Size = new System.Drawing.Size(153, 22);
            this.AuthorsName.TabIndex = 18;
            // 
            // AuthorsProfession
            // 
            this.AuthorsProfession.Location = new System.Drawing.Point(620, 595);
            this.AuthorsProfession.Name = "AuthorsProfession";
            this.AuthorsProfession.Size = new System.Drawing.Size(153, 22);
            this.AuthorsProfession.TabIndex = 19;
            // 
            // ContentDate
            // 
            this.ContentDate.Location = new System.Drawing.Point(1187, 202);
            this.ContentDate.Mask = "00/00/0000 90:00";
            this.ContentDate.Name = "ContentDate";
            this.ContentDate.Size = new System.Drawing.Size(149, 22);
            this.ContentDate.TabIndex = 20;
            this.ContentDate.ValidatingType = typeof(System.DateTime);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(1184, 1);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(235, 17);
            this.label1.TabIndex = 21;
            this.label1.Text = "Название программы\\публикации:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1184, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(110, 17);
            this.label2.TabIndex = 22;
            this.label2.Text = "Тип источника:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(1184, 89);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 17);
            this.label3.TabIndex = 23;
            this.label3.Text = "Источник:";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(1184, 132);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(28, 17);
            this.label4.TabIndex = 24;
            this.label4.Text = "тег";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(1183, 182);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(90, 17);
            this.label5.TabIndex = 25;
            this.label5.Text = "Дата.время:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(1184, 227);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(51, 17);
            this.label6.TabIndex = 26;
            this.label6.Text = "Атвор:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(1184, 274);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(84, 17);
            this.label7.TabIndex = 27;
            this.label7.Text = "Аннотация:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(617, 527);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(89, 17);
            this.label8.TabIndex = 28;
            this.label8.Text = "Имя автора:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(617, 572);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(129, 17);
            this.label9.TabIndex = 29;
            this.label9.Text = "Род деятельности";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(12, 322);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(106, 17);
            this.label10.TabIndex = 30;
            this.label10.Text = "Тип источника";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(317, 323);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(38, 17);
            this.label11.TabIndex = 31;
            this.label11.Text = "Теги";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(12, 481);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(71, 17);
            this.label12.TabIndex = 32;
            this.label12.Text = "Источник";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(328, 481);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(57, 17);
            this.label13.TabIndex = 33;
            this.label13.Text = "Авторы";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(617, 323);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(83, 17);
            this.label14.TabIndex = 34;
            this.label14.Text = "Профессии";
            // 
            // GenreBox
            // 
            this.GenreBox.Location = new System.Drawing.Point(1244, 449);
            this.GenreBox.Name = "GenreBox";
            this.GenreBox.Size = new System.Drawing.Size(198, 22);
            this.GenreBox.TabIndex = 35;
            // 
            // SelectOnPubType
            // 
            this.SelectOnPubType.Location = new System.Drawing.Point(1240, 556);
            this.SelectOnPubType.Name = "SelectOnPubType";
            this.SelectOnPubType.Size = new System.Drawing.Size(179, 23);
            this.SelectOnPubType.TabIndex = 36;
            this.SelectOnPubType.Text = "Выборка по источнику";
            this.SelectOnPubType.UseVisualStyleBackColor = true;
            this.SelectOnPubType.Click += new System.EventHandler(this.SelectOnPubType_Click);
            // 
            // SelectOnSource
            // 
            this.SelectOnSource.Location = new System.Drawing.Point(1024, 556);
            this.SelectOnSource.Name = "SelectOnSource";
            this.SelectOnSource.Size = new System.Drawing.Size(210, 23);
            this.SelectOnSource.TabIndex = 37;
            this.SelectOnSource.Text = "Выборка по каналу инф-ии";
            this.SelectOnSource.UseVisualStyleBackColor = true;
            this.SelectOnSource.Click += new System.EventHandler(this.SelectOnSource_Click);
            // 
            // SelectOnTag
            // 
            this.SelectOnTag.Location = new System.Drawing.Point(1240, 527);
            this.SelectOnTag.Name = "SelectOnTag";
            this.SelectOnTag.Size = new System.Drawing.Size(179, 23);
            this.SelectOnTag.TabIndex = 38;
            this.SelectOnTag.Text = "Выборка по тегу";
            this.SelectOnTag.UseVisualStyleBackColor = true;
            this.SelectOnTag.Click += new System.EventHandler(this.SelectOnTag_Click);
            // 
            // SelectOnAuthor
            // 
            this.SelectOnAuthor.Location = new System.Drawing.Point(1240, 498);
            this.SelectOnAuthor.Name = "SelectOnAuthor";
            this.SelectOnAuthor.Size = new System.Drawing.Size(179, 23);
            this.SelectOnAuthor.TabIndex = 39;
            this.SelectOnAuthor.Text = "Выборка по автору";
            this.SelectOnAuthor.UseVisualStyleBackColor = true;
            this.SelectOnAuthor.Click += new System.EventHandler(this.SelectOnAuthor_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1024, 524);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(210, 23);
            this.button1.TabIndex = 40;
            this.button1.Text = "Отобразить всё";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // delField
            // 
            this.delField.Location = new System.Drawing.Point(880, 556);
            this.delField.Mask = "00000";
            this.delField.Name = "delField";
            this.delField.Size = new System.Drawing.Size(35, 22);
            this.delField.TabIndex = 41;
            this.delField.ValidatingType = typeof(int);
            // 
            // Delete_note
            // 
            this.Delete_note.Location = new System.Drawing.Point(921, 556);
            this.Delete_note.Name = "Delete_note";
            this.Delete_note.Size = new System.Drawing.Size(75, 23);
            this.Delete_note.TabIndex = 42;
            this.Delete_note.Text = "Удалить запись";
            this.Delete_note.TextImageRelation = System.Windows.Forms.TextImageRelation.TextAboveImage;
            this.Delete_note.UseVisualStyleBackColor = true;
            this.Delete_note.Click += new System.EventHandler(this.Delete_note_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1454, 629);
            this.Controls.Add(this.Delete_note);
            this.Controls.Add(this.delField);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.SelectOnAuthor);
            this.Controls.Add(this.SelectOnTag);
            this.Controls.Add(this.SelectOnSource);
            this.Controls.Add(this.SelectOnPubType);
            this.Controls.Add(this.GenreBox);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
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
            this.Controls.Add(this.ContentDate);
            this.Controls.Add(this.AuthorsProfession);
            this.Controls.Add(this.AuthorsName);
            this.Controls.Add(this.ContentAnnotation);
            this.Controls.Add(this.ContentAuthor);
            this.Controls.Add(this.ContentGenre);
            this.Controls.Add(this.ContentSource);
            this.Controls.Add(this.ContentType);
            this.Controls.Add(this.ContentTitle);
            this.Controls.Add(this.AddAuthorButton);
            this.Controls.Add(this.GenreButton);
            this.Controls.Add(this.AddContendButton);
            this.Controls.Add(this.ProfessionGrid);
            this.Controls.Add(this.AuthorGrid);
            this.Controls.Add(this.Genre_Grid);
            this.Controls.Add(this.Source_Grid);
            this.Controls.Add(this.Infrom_SourceGrid);
            this.Controls.Add(this.ContentGrid);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ContentGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Infrom_SourceGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Source_Grid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Genre_Grid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.AuthorGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ProfessionGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView ContentGrid;
        private System.Windows.Forms.DataGridView Infrom_SourceGrid;
        private System.Windows.Forms.DataGridView Source_Grid;
        private System.Windows.Forms.DataGridView Genre_Grid;
        private System.Windows.Forms.DataGridView AuthorGrid;
        private System.Windows.Forms.DataGridView ProfessionGrid;
        private System.Windows.Forms.Button AddContendButton;
        private System.Windows.Forms.Button GenreButton;
        private System.Windows.Forms.Button AddAuthorButton;
        private System.Windows.Forms.TextBox ContentTitle;
        private System.Windows.Forms.ComboBox ContentType;
        private System.Windows.Forms.TextBox ContentSource;
        private System.Windows.Forms.ComboBox ContentGenre;
        private System.Windows.Forms.ComboBox ContentAuthor;
        private System.Windows.Forms.RichTextBox ContentAnnotation;
        private System.Windows.Forms.MaskedTextBox AuthorsName;
        private System.Windows.Forms.TextBox AuthorsProfession;
        private System.Windows.Forms.MaskedTextBox ContentDate;
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
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox GenreBox;
        private System.Windows.Forms.Button SelectOnPubType;
        private System.Windows.Forms.Button SelectOnSource;
        private System.Windows.Forms.Button SelectOnTag;
        private System.Windows.Forms.Button SelectOnAuthor;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.MaskedTextBox delField;
        private System.Windows.Forms.Button Delete_note;
    }
}

