#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "stdlib.h"
namespace Practice4SC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	struct point
	{
	public:
		double x;
		double y;
	};

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		/// <summary>
	   /// основные параметры для вычисления функции
	   /// </summary>
	private: float x1 = 0, x2 = 0, x3 = 0, p1 = 0, p2 = 0, a = 0, b = 0;
			 /// <summary>
			 /// Структура точки функции
			 /// </summary>
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  Task;
	private: System::Windows::Forms::TextBox^  X2;
	private: System::Windows::Forms::TextBox^  P1;
	private: System::Windows::Forms::TextBox^  X1;
	private: System::Windows::Forms::TextBox^  X3;
	private: System::Windows::Forms::TextBox^  B;
	private: System::Windows::Forms::TextBox^  P2;
	private: System::Windows::Forms::TextBox^  Aparam;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  FilePath;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  Confirm;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Task = (gcnew System::Windows::Forms::PictureBox());
			this->X2 = (gcnew System::Windows::Forms::TextBox());
			this->P1 = (gcnew System::Windows::Forms::TextBox());
			this->X1 = (gcnew System::Windows::Forms::TextBox());
			this->X3 = (gcnew System::Windows::Forms::TextBox());
			this->B = (gcnew System::Windows::Forms::TextBox());
			this->P2 = (gcnew System::Windows::Forms::TextBox());
			this->Aparam = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->FilePath = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Confirm = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Task))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// Task
			// 
			this->Task->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Task.Image")));
			this->Task->Location = System::Drawing::Point(0, 2);
			this->Task->Name = L"Task";
			this->Task->Size = System::Drawing::Size(211, 111);
			this->Task->TabIndex = 1;
			this->Task->TabStop = false;
			this->Task->Click += gcnew System::EventHandler(this, &MyForm1::Task_Click);
			// 
			// X2
			// 
			this->X2->Location = System::Drawing::Point(12, 128);
			this->X2->Name = L"X2";
			this->X2->Size = System::Drawing::Size(54, 20);
			this->X2->TabIndex = 4;
			// 
			// P1
			// 
			this->P1->Location = System::Drawing::Point(13, 154);
			this->P1->Name = L"P1";
			this->P1->Size = System::Drawing::Size(53, 20);
			this->P1->TabIndex = 8;
			// 
			// X1
			// 
			this->X1->Location = System::Drawing::Point(72, 128);
			this->X1->Name = L"X1";
			this->X1->Size = System::Drawing::Size(53, 20);
			this->X1->TabIndex = 9;
			// 
			// X3
			// 
			this->X3->Location = System::Drawing::Point(72, 154);
			this->X3->Name = L"X3";
			this->X3->Size = System::Drawing::Size(53, 20);
			this->X3->TabIndex = 10;
			// 
			// B
			// 
			this->B->Location = System::Drawing::Point(13, 180);
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(53, 20);
			this->B->TabIndex = 11;
			// 
			// P2
			// 
			this->P2->Location = System::Drawing::Point(72, 180);
			this->P2->Name = L"P2";
			this->P2->Size = System::Drawing::Size(54, 20);
			this->P2->TabIndex = 12;
			// 
			// Aparam
			// 
			this->Aparam->Location = System::Drawing::Point(13, 206);
			this->Aparam->Name = L"Aparam";
			this->Aparam->Size = System::Drawing::Size(53, 20);
			this->Aparam->TabIndex = 13;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(217, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(660, 448);
			this->chart1->TabIndex = 14;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm1::chart1_Click);
			// 
			// FilePath
			// 
			this->FilePath->Location = System::Drawing::Point(12, 474);
			this->FilePath->Name = L"FilePath";
			this->FilePath->Size = System::Drawing::Size(776, 20);
			this->FilePath->TabIndex = 15;
			this->FilePath->Text = L"Enter the file path";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 499);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(776, 20);
			this->textBox1->TabIndex = 16;
			this->textBox1->Text = L"Enter output filepath";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// Confirm
			// 
			this->Confirm->Location = System::Drawing::Point(802, 496);
			this->Confirm->Name = L"Confirm";
			this->Confirm->Size = System::Drawing::Size(75, 23);
			this->Confirm->TabIndex = 17;
			this->Confirm->Text = L"Confirm";
			this->Confirm->UseVisualStyleBackColor = true;
			this->Confirm->Click += gcnew System::EventHandler(this, &MyForm1::Confirm_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 531);
			this->Controls->Add(this->Confirm);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->FilePath);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->Aparam);
			this->Controls->Add(this->P2);
			this->Controls->Add(this->B);
			this->Controls->Add(this->X3);
			this->Controls->Add(this->X1);
			this->Controls->Add(this->P1);
			this->Controls->Add(this->X2);
			this->Controls->Add(this->Task);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Task))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Task_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Confirm_Click(System::Object^  sender, System::EventArgs^  e) {

		chart1->Series->Clear();
		chart1->Series->Add("Gr");
		chart1->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		//открытие файла в режиме чтения
		String ^filepath =FilePath->Text;
		string file;
		MarshalString(FilePath->Text, file);
		ifstream fin(file);
		string num;
		fin >> num;
		//Далее происходит считывание исходных данных для вычисления функции
		x1 =atof(num.c_str());
		fin >> num;
		x2 = atof(num.c_str());
		fin >> num;
		x3 = atof(num.c_str());
		fin >> num;
		p1 = atof(num.c_str());
		fin >> num;
		p2 = atof(num.c_str());
		fin >> num;
		a = atof(num.c_str());
		fin >> num;
		b = atof(num.c_str());
		fin.close();
		//отображение исходных данных в окне
		num = "X1=" + to_string(x1);
		X1->Text = gcnew String(num.c_str());
		num = "X2=" + to_string(x2);
		X2->Text = gcnew String(num.c_str());
		num = "X3=" + to_string(x3);
		X3->Text = gcnew String(num.c_str());
		num = "P1=" + to_string(p1);
		P1->Text = gcnew String(num.c_str());
		num = "P2=" + to_string(p2);
		P2->Text = gcnew String(num.c_str());
		num = "A=" + to_string(a);
		Aparam->Text = gcnew String(num.c_str());
		num = "B=" + to_string(b);
		B->Text = gcnew String(num.c_str());
		//инициализация массива точек и их счетчика i
		int i = 0;
		int size = int((x2 - x1) / x3) + 1;
		point *salvations = new point[size];
		//Вычисление значений функции и отображение их на графике
		for (; x1 < p1; x1 += x3, i++)
		{
			salvations[i].y = FirstFunc();
			salvations[i].x = x1;
			chart1->Series[0]->Points->AddXY(salvations[i].x, salvations[i].y);
		}
		for (; x1 <= p2; x1 += x3, i++)
		{
			salvations[i].y = Math::Cos(a * x1);
			salvations[i].x = x1;
			chart1->Series[0]->Points->AddXY(salvations[i].x, salvations[i].y);
		}
		for (; x1 <= x2; x1 += x3, i++)
		{
			salvations[i].y = ThirdFunc();
			salvations[i].x = x1;
			chart1->Series[0]->Points->AddXY(salvations[i].x, salvations[i].y);
		}
		//открытие файла на запись 
		filepath = textBox1->Text;
		MarshalString(filepath, file);
		ofstream fout(file);
		fout<< "X\tY\n";
		//запись значений функции в файл
		fout.precision(2);
		for (i = 0; i <size; i++)
			fout<<salvations[i].x<<"\t"<<salvations[i].y<<"\n";
		fout.close();
		delete salvations;
		
	}
			 /// <summary>
		/// вычисляет значение функции в первом интервале
		/// </summary>
	private: double FirstFunc()
	{
		return ((1 + x1 + Math::Pow(x1, 2) / Fact(2) + Math::Pow(x1, 3) / Fact(3) + Math::Pow(x1, 4) / Fact(4) + Math::Pow(x1, 5) / Fact(5) + Math::Pow(x1, 6) / Fact(6) +
			Math::Pow(x1, 7) / Fact(7) + Math::Pow(x1, 8) / Fact(8) + Math::Pow(x1, 9) / Fact(9) + Math::Pow(x1, 10) / Fact(10)) * Math::Sin(b * x1));
	}
			 /// <summary>
			 /// вычиляет значение функции в тертьем интервале
			 /// </summary>
			 /// <returns></returns>
	private: double ThirdFunc()
	{
		return ((1 + x1 + Math::Pow(x1, 2) / Fact(2) + Math::Pow(x1, 3) / Fact(3) + Math::Pow(x1, 4) / Fact(4) + Math::Pow(x1, 5) / Fact(5) + Math::Pow(x1, 6) / Fact(6) +
			Math::Pow(x1, 7) / Fact(7) + Math::Pow(x1, 8) / Fact(8) + Math::Pow(x1, 9) / Fact(9) + Math::Pow(x1, 10) / Fact(10)) * Math::Cos(b * x1));
	}
			 /// <summary>
			 /// Вычисляет факториал числа. 
			 /// </summary>
			 /// <param name="num">Передаваемое число, от которого считается факториал</param>
	private: int Fact(int num)
	{
		if (num <= 1)
			return 1;
		else
			return num * Fact(num - 1);
	}
			 
	/// <summary>
	/// преобразует System::String to std::string
	/// </summary>
	public:	void MarshalString(String ^ s, string& os) {
				 using namespace Runtime::InteropServices;
				 const char* chars =
					 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
