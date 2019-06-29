#pragma once
#include <vector>
#include <list>
namespace Practice4SC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Описание студента
	/// </summary>
	struct line
	{
	public:
		/// <summary>
		/// Имя студента
		/// </summary>
		string Name;
		/// <summary>
		/// Дата рождения
		/// </summary>
		string birthDate;
		/// <summary>
		/// Номер зачетки
		/// </summary>
		string docnum;
		/// <summary>
		/// Изучаемый иностранный язык
		/// </summary>
		string language;
		/// <summary>
		/// средний балл
		/// </summary>
		double avgGrade;
	};
	/// <summary>
	   /// Список студентов
	   /// </summary>
	vector<line> students;
	line *person = new line();
	/// <summary>
	/// Строковое представление записи о студенте
	/// </summary>
	string *str;
	/// <summary>
	/// Сводка для MyForm3
	/// </summary>

	/// <summary>
		/// Сумма языковых весов для рассчёта процентной статистики
		/// </summary>
	double summ = 0;
	/// <summary>
	/// Доля студентов, изучающих язык в %
	/// </summary>
	double avgpercenr = 0;
	/// <summary>
	/// Массив языков, по которым ведется статистика
	/// </summary>
	string *languages = new string[3]{ "Eng", "De", "Fr" };
	/// <summary>
	/// Доля каждого языка в количестве студентов
	/// </summary>
	double *languageValues = new double[3]{ 0, 0, 0 };

	public ref class MyForm3 : public System::Windows::Forms::Form
	{
		/// <summary>
		/// Инициализация окна
		/// </summary>
	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  StudName;
	private: System::Windows::Forms::MaskedTextBox^  Birth;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::MaskedTextBox^  Doc;
	private: System::Windows::Forms::TextBox^  Language;
	private: System::Windows::Forms::TextBox^  Avg;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  ReadList;
	private: System::Windows::Forms::Button^  Sort;
	private: System::Windows::Forms::Button^  Write;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button1;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->StudName = (gcnew System::Windows::Forms::TextBox());
			this->Birth = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->Doc = (gcnew System::Windows::Forms::MaskedTextBox());
			this->Language = (gcnew System::Windows::Forms::TextBox());
			this->Avg = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->ReadList = (gcnew System::Windows::Forms::Button());
			this->Sort = (gcnew System::Windows::Forms::Button());
			this->Write = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// StudName
			// 
			this->StudName->Location = System::Drawing::Point(12, 32);
			this->StudName->Name = L"StudName";
			this->StudName->Size = System::Drawing::Size(100, 20);
			this->StudName->TabIndex = 1;
			this->StudName->Text = L"Name";
			// 
			// Birth
			// 
			this->Birth->Location = System::Drawing::Point(118, 32);
			this->Birth->Mask = L"00/00/0000";
			this->Birth->Name = L"Birth";
			this->Birth->Size = System::Drawing::Size(100, 20);
			this->Birth->TabIndex = 13;
			this->Birth->Tag = L"";
			this->Birth->ValidatingType = System::DateTime::typeid;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(118, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 13);
			this->textBox2->TabIndex = 15;
			this->textBox2->Text = L"BirthDate:";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(224, 12);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 13);
			this->textBox3->TabIndex = 16;
			this->textBox3->Text = L"Doc Number:";
			// 
			// Doc
			// 
			this->Doc->Location = System::Drawing::Point(224, 32);
			this->Doc->Mask = L"00/00-0000";
			this->Doc->Name = L"Doc";
			this->Doc->Size = System::Drawing::Size(100, 20);
			this->Doc->TabIndex = 17;
			// 
			// Language
			// 
			this->Language->Location = System::Drawing::Point(330, 32);
			this->Language->Name = L"Language";
			this->Language->Size = System::Drawing::Size(100, 20);
			this->Language->TabIndex = 18;
			this->Language->Text = L"Language";
			// 
			// Avg
			// 
			this->Avg->Location = System::Drawing::Point(436, 32);
			this->Avg->Name = L"Avg";
			this->Avg->Size = System::Drawing::Size(100, 20);
			this->Avg->TabIndex = 19;
			this->Avg->Text = L"AvgGrade";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(572, 80);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->YValuesPerPoint = 2;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 20;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm3::chart1_Click);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(572, 29);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(75, 23);
			this->Add->TabIndex = 21;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &MyForm3::Add_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 306);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(544, 20);
			this->textBox1->TabIndex = 22;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Location = System::Drawing::Point(12, 287);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 13);
			this->textBox5->TabIndex = 23;
			this->textBox5->Text = L"Read/Write Path:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Английский", L"Немецкий", L"Французский", L"Въетнамский",
					L"Китайский", L"Итальянский", L"Любой язык"
			});
			this->comboBox1->Location = System::Drawing::Point(129, 332);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 24;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Location = System::Drawing::Point(12, 335);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(111, 13);
			this->textBox7->TabIndex = 25;
			this->textBox7->Text = L"Language Fileprint:";
			// 
			// ReadList
			// 
			this->ReadList->Location = System::Drawing::Point(12, 357);
			this->ReadList->Name = L"ReadList";
			this->ReadList->Size = System::Drawing::Size(75, 23);
			this->ReadList->TabIndex = 26;
			this->ReadList->Text = L"ReadList";
			this->ReadList->UseVisualStyleBackColor = true;
			this->ReadList->Click += gcnew System::EventHandler(this, &MyForm3::ReadList_Click);
			// 
			// Sort
			// 
			this->Sort->Location = System::Drawing::Point(93, 357);
			this->Sort->Name = L"Sort";
			this->Sort->Size = System::Drawing::Size(75, 23);
			this->Sort->TabIndex = 27;
			this->Sort->Text = L"Sort";
			this->Sort->UseVisualStyleBackColor = true;
			this->Sort->Click += gcnew System::EventHandler(this, &MyForm3::Sort_Click);
			// 
			// Write
			// 
			this->Write->Location = System::Drawing::Point(175, 357);
			this->Write->Name = L"Write";
			this->Write->Size = System::Drawing::Size(75, 23);
			this->Write->TabIndex = 28;
			this->Write->Text = L"Write";
			this->Write->UseVisualStyleBackColor = true;
			this->Write->Click += gcnew System::EventHandler(this, &MyForm3::Write_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(256, 357);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(286, 20);
			this->textBox4->TabIndex = 29;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Location = System::Drawing::Point(256, 340);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 13);
			this->textBox6->TabIndex = 30;
			this->textBox6->Text = L"Diagram Write Path:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 69);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(524, 212);
			this->richTextBox1->TabIndex = 31;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(371, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 385);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->Write);
			this->Controls->Add(this->Sort);
			this->Controls->Add(this->ReadList);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->Avg);
			this->Controls->Add(this->Language);
			this->Controls->Add(this->Doc);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Birth);
			this->Controls->Add(this->StudName);
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm3_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	/// <summary>
	/// Добавляет информацию о студенте в вектор 
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void Add_Click(System::Object^  sender, System::EventArgs^  e) {
		//Считывание информации о студенте из окна
		string exple;
		try { MarshalString(StudName->Text, person->Name); }
		catch (const std::exception&)
		{
			return;
		}
		try { MarshalString(Birth->Text, person->birthDate); }
		catch (const std::exception&)
		{
			return;
		}
		try { MarshalString(Language->Text, person->language); }
		catch (const std::exception&)
		{
			return;
		}
		try { MarshalString(Doc->Text, person->docnum); }
		catch (const std::exception&)
		{
			return;
		}
		try {
			MarshalString(Avg->Text, exple);
			person->avgGrade = atof(exple.c_str());
		}
		catch (const std::exception&)
		{
			return;
		}
		students.push_back(*person);
		str = new string[5]{ person->Name, person->birthDate, person->docnum, person->language, to_string(person->avgGrade) };
		for (int i = 0; i < 5; i++)
		{
			richTextBox1->AppendText(gcnew String(str[i].c_str()));
			richTextBox1->AppendText(gcnew String("\t"));
		}
		richTextBox1->AppendText(gcnew String("\n"));


		if (str[3] == "английский" || str[3] == "Английский")
			languageValues[0]++;
		else if (str[3] == "немецкий" || str[3] == "Немецкий")
			languageValues[1]++;
		else if (str[3] == "французский" || str[3] == "Французский")
			languageValues[2]++;

		//Рассчёт процентных соотношений для диаграммы
		summ = 0;
		languages = new string[3]{ "Eng", "De", "Fr" };
		for (int g = 0; g < 3; g++)
			summ += languageValues[g];
		for (int i = 0; i < 3; i++)
		{
			avgpercenr = languageValues[i] / summ * 100;
			avgpercenr = System::Math::Round(avgpercenr, 2);
			languages[i] = languages[i] + ": " + to_string(avgpercenr) + "%";
		}

	}
	public:	void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Построение диаграммы
		chart1->Series->Clear();
		chart1->Series->Add(gcnew String(languages[0].c_str()));
		chart1->Series->Add(gcnew String(languages[1].c_str()));
		chart1->Series->Add(gcnew String(languages[2].c_str()));
		chart1->Series[0]->Points->AddXY(0, languageValues[0]);
		chart1->Series[1]->Points->AddXY(0, languageValues[1]);
		chart1->Series[2]->Points->AddXY(0, languageValues[2]);
	}
	/// <summary>
	/// Записывает данные о студентах в файл, а также создает файл, в котором хранится диаграмма
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void Write_Click(System::Object^  sender, System::EventArgs^  e) {
		string filepath;
		string defal = "Все языки";
		if (comboBox1->Text == "Английский")
			defal = "Английский";
		else if (comboBox1->Text == "Немецкий")
			defal = "Немецкий";
		else if (comboBox1->Text == "Французский")
			defal = "Французский";
		else if (comboBox1->Text == "Итальянский")
			defal = "Итальянский";
		else if (comboBox1->Text == "Китайский")
			defal = "Китайский";
		else if (comboBox1->Text == "Въетнамский")
			defal = "Въетнамский";
		MarshalString(textBox1->Text, filepath);
		ofstream file(filepath);
		if (defal == "Все языки")
			for (vector<int>::size_type i = 0; i != students.size(); i++) {
				file << students[i].Name << "\t" << students[i].birthDate << "\t" << students[i].docnum << "\t" << students[i].language << "\t" << students[i].avgGrade << "\n";
			}
		else
			for (vector<int>::size_type i = 0; i != students.size(); i++) {
				if (defal == students[i].language)
					file << students[i].Name << "\t" << students[i].birthDate << "\t" << students[i].docnum << "\t" << students[i].language << "\t" << students[i].avgGrade << "\n";
			}
			file.close();	
	}
	/// <summary>
	/// Считывание входных данных, создание таблицы и диаграммы по ним
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void ReadList_Click(System::Object^  sender, System::EventArgs^  e) {
		//обнулить массив веса изучаемого языка
		for (int i = 0; i < 3; i++)
			languageValues[i] = 0;
		//Очистить таблицу формы
		richTextBox1->Clear();
		students.clear();
		string _name;
		string surname;
		string _birthDate;
		string docnum;
		string language;
		string avg;
		string filepath;
		MarshalString(textBox1->Text, filepath);
		//Считать записи списка студентов
		ifstream file(filepath);
		while (!file.eof())
		{
			file >> _name;
			if (_name == "")
				break;
			file >> surname;
			_name = _name +" "+ surname;
			person->Name = _name;
			file >> person->birthDate;
			file >> person->docnum;
			file >> person->language;
			file >> person->avgGrade;
			students.push_back(*person);
			//Занести языковую статистику в массивы
			if (person->language == "английский" || person->language == "Английский")
				languageValues[0]++;
			else if (person->language == "немецкий" || person->language == "Немецкий")
				languageValues[1]++;
			else if (person->language == "французский" || person->language == "Французский")
				languageValues[2]++;
			str = new string[5]{ person->Name, person->birthDate, person->docnum, person->language, to_string(person->avgGrade) };
			for (int i = 0; i < 5; i++)
			{
				richTextBox1->AppendText(gcnew String(str[i].c_str()));
				richTextBox1->AppendText(gcnew String("\t"));
			}
			richTextBox1->AppendText(gcnew String("\n"));
			_name = "";
		}
		file.close();

		//Рассчёт процентных соотношений для диаграммы
		summ = 0;
		languages = new string[3]{ "Eng", "De", "Fr" };
		for (int g = 0; g < 3; g++)
			summ += languageValues[g];
		for (int i = 0; i < 3; i++)
		{
			avgpercenr = languageValues[i] / summ * 100;
			avgpercenr = System::Math::Round(avgpercenr, 2);
			languages[i] = languages[i] + ": " + to_string(avgpercenr) + "%";
		}
	}
	/// <summary>
	/// Сортирует записи о студентах в порядке возрастания среднего балла и меняет их расстановку в таблице
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void Sort_Click(System::Object^  sender, System::EventArgs^  e) {
		richTextBox1->Clear();
		string dbl;
		double min= students[0].avgGrade;
		int ind = 0;
		for (vector<int>::size_type i = 0; i < students.size(); i++) {

			for (vector<int>::size_type g = students.size() - 1; g >= i + 1; g--) {
				if (students[g].avgGrade < students[g-1].avgGrade)
					swap(students[g], students[g-1]);
			}
			
		}

		for (vector<int>::size_type i = 0; i != students.size(); i++) {
			richTextBox1->AppendText(gcnew String(students[i].Name.c_str()));
			richTextBox1->AppendText(gcnew String("\t"));
			richTextBox1->AppendText(gcnew String(students[i].birthDate.c_str()));
			richTextBox1->AppendText(gcnew String("\t"));
			richTextBox1->AppendText(gcnew String(students[i].docnum.c_str()));
			richTextBox1->AppendText(gcnew String("\t")); 
			richTextBox1->AppendText(gcnew String(students[i].language.c_str()));
			richTextBox1->AppendText(gcnew String("\t"));
			dbl = to_string(students[i].avgGrade);
			richTextBox1->AppendText(gcnew String(dbl.c_str()));
			richTextBox1->AppendText(gcnew String("\n"));
		}
	}
};
	}
