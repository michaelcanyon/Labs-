#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
namespace Practice4SC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	   /// Вектор X
	   /// </summary>
	vector<int> X;
	/// <summary>
	/// Вектор Y
	/// </summary>
	vector<int> Y;
	/// <summary>
	/// Вектор Z
	/// </summary>
	vector<int>Z;
	/// <summary>
	/// Среднее значение по столбцам 
	/// </summary>
	int avg = 0;
	/// <summary>
	/// Значение ячейки столбца
	/// </summary>
	int x = 0, y = 0, z = 0;
	/// <summary>
	/// Число столбцов
	/// </summary>
	int n;
	/// <summary>
	/// Инициализация окна
	/// </summary>
	/// <summary>
	/// Сводка для MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(void)
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
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

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
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(28, 183);
			this->maskedTextBox1->Mask = L"0000000000";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(67, 20);
			this->maskedTextBox1->TabIndex = 1;
			this->maskedTextBox1->ValidatingType = System::Int32::typeid;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(12, 186);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(10, 13);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"X:";
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(28, 209);
			this->maskedTextBox2->Mask = L"0000000000";
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(67, 20);
			this->maskedTextBox2->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(12, 212);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(10, 13);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"Y:";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(28, 235);
			this->maskedTextBox3->Mask = L"0000000000";
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(67, 20);
			this->maskedTextBox3->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(12, 238);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(10, 13);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"Z:";
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(28, 157);
			this->maskedTextBox4->Mask = L"0";
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(20, 20);
			this->maskedTextBox4->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Location = System::Drawing::Point(12, 157);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(10, 13);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"n:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 273);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm4::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(93, 273);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Write";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm4::button4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 302);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Sort";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(93, 302);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Read";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm4::button3_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(174, 305);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(606, 20);
			this->textBox5->TabIndex = 17;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(451, 21);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(323, 250);
			this->chart1->TabIndex = 18;
			this->chart1->Text = L"chart1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 21);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(433, 130);
			this->richTextBox1->TabIndex = 19;
			this->richTextBox1->Text = L"";
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 340);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->maskedTextBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->maskedTextBox1);
			this->Name = L"MyForm4";
			this->Text = L"MyForm4";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm4_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	/// <summary>
	/// Формирует запись из данных полей окна и добавляет её в список
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		string examp;
		//Защита поля с числом столбцов в матрице
		if (maskedTextBox4->Enabled);
		{
			MarshalString(maskedTextBox4->Text, examp);
			n = atoi(examp.c_str());
			maskedTextBox4->Enabled = false;
		}
		if (X.size() == n || Y.size() == n || Z.size() == n)
		{
			MessageBox::Show("Добавлено максимальное количество элементов в вектора.");
			return;
		}
		else
		{
			try {
				MarshalString(maskedTextBox1->Text, examp);
				X.push_back(atoi(examp.c_str()));
			}
			catch (const std::exception&)
			{
				MessageBox::Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
				return;
			}
			try {
				MarshalString(maskedTextBox2->Text, examp);
				Y.push_back(atoi(examp.c_str()));
			}
			catch (const std::exception&)
			{
				MessageBox::Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
				return;
			}
			try {
				MarshalString(maskedTextBox3->Text, examp);
				Z.push_back(atoi(examp.c_str()));
			}
			catch (const std::exception&)
			{
				MessageBox::Show("Неверный формат вводимого элемента или пустое поле. Введите корректные данные");
				return;
			}

		}
		//Заполнение ячеек данными
		richTextBox1->Clear();
		for (vector<int>::size_type i = 0; i < X.size(); i++) {

			examp = to_string(X[i]);
			richTextBox1->AppendText(gcnew String(examp.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Y.size(); i++) {

			examp = to_string(Y[i]);
			richTextBox1->AppendText(gcnew String(examp.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Z.size(); i++) {

			examp = to_string(Z[i]);
			richTextBox1->AppendText(gcnew String(examp.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		//Вычисление и заполнение ячеек со средними значениями столбцов и построение диаграммы
		for (int i = 0; i < X.size(); i++)
		{
			x = X[i];
			y = Y[i];
			z = Z[i];
			avg = (x + y + z) / 3;
			examp = to_string(avg);
			richTextBox1->AppendText(gcnew String(examp.c_str()));
			richTextBox1->AppendText("  ");
			chart1->Series[0]->Points->AddXY(i, avg);
		}
		maskedTextBox1->Text = "";
		maskedTextBox2->Text = "";
		maskedTextBox3->Text = "";
	}
	public:	void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	/// <summary>
	/// Читает файл данных, заполняет вектора и строит диаграмму
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//Очистка векторов и полей диаграммы от мусора 
		X.clear();
		Y.clear();
		Z.clear();
		richTextBox1->Clear();
		chart1->Series->Clear();
		chart1->Series->Add("dia");
		maskedTextBox4->Enabled = true;
		string buff;
		MarshalString(textBox5->Text, buff);

		ifstream reader(buff);
		reader >> buff;
		n = atoi(buff.c_str());
		maskedTextBox4->Text = gcnew String(buff.c_str());
		maskedTextBox4->Enabled = false;
		//Чтение файла
		for (int i = 0; i < n; i++)
		{
			reader >> buff;
			X.push_back(atoi(buff.c_str()));
		}
		for (int i = 0; i < n; i++)
		{
			reader >> buff;
			Y.push_back(atoi(buff.c_str()));
		}
		for (int i = 0; i < n; i++)
		{
			reader >> buff;
			Z.push_back(atoi(buff.c_str()));
		}
		reader.close();
		//Заполнение таблицы
		richTextBox1->Clear();
		for (vector<int>::size_type i = 0; i < X.size(); i++) {

			buff = to_string(X[i]);
			richTextBox1->AppendText(gcnew String(buff.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Y.size(); i++) {

			buff = to_string(Y[i]);
			richTextBox1->AppendText(gcnew String(buff.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Z.size(); i++) {

			buff = to_string(Z[i]);
			richTextBox1->AppendText(gcnew String(buff.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		//Высчитать средние и заполнить диаграмму
		for (int i = 0; i < X.size(); i++)
		{
			x = X[i];
			y = Y[i];
			z = Z[i];
			avg = (x + y + z) / 3;
			buff = to_string(avg);
			richTextBox1->AppendText(gcnew String(buff.c_str()));
			richTextBox1->AppendText("  ");
			chart1->Series[0]->Points->AddXY(i, avg);
		}
	}
	/// <summary>
	/// Запись данных в файл
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		string buff;
		MarshalString(textBox5->Text, buff);

		ofstream writer(buff);
		writer << n;
		writer << "\n";
		for (vector<int>::size_type i = 0; i < X.size(); i++) {

			writer << X[i];
			writer << "  ";
		}
		writer << "\n";
		for (vector<int>::size_type i = 0; i < Y.size(); i++) {

			writer << Y[i];
			writer << "  ";
		}
		writer << "\n";
		for (vector<int>::size_type i = 0; i < Z.size(); i++) {

			writer << Z[i];
			writer << "  ";
		}
		writer.close();
	}

	/// <summary>
	/// Сортирует векторы в порядке возрастания, считает средние для сформированных столбцов и строит диаграмму
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		richTextBox1->Clear();
		chart1->Series->Clear();
		chart1->Series->Add("dia");
		string dbl;
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		sort(Z.begin(), Z.end());
		for (vector<int>::size_type i = 0; i < X.size(); i++) {

			dbl = to_string(X[i]);
			richTextBox1->AppendText(gcnew String(dbl.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Y.size(); i++) {

			dbl = to_string(Y[i]);
			richTextBox1->AppendText(gcnew String(dbl.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (vector<int>::size_type i = 0; i < Z.size(); i++) {

			dbl = to_string(Z[i]);
			richTextBox1->AppendText(gcnew String(dbl.c_str()));
			richTextBox1->AppendText("  ");
		}
		richTextBox1->AppendText("\n");
		for (int i = 0; i < X.size(); i++)
		{
			x = X[i];
			y = Y[i];
			z = Z[i];
			avg = (x + y + z) / 3;
			dbl = to_string(avg);
			richTextBox1->AppendText(gcnew String(dbl.c_str()));
			richTextBox1->AppendText("  ");
			chart1->Series[0]->Points->AddXY(i, avg);
		}
	}
};
}
