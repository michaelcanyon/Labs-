#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "stdlib.h"
#include "iostream"

namespace Practice4SC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm1 ^F1;
		MyForm2 ^F2;
		MyForm3 ^F3;
		MyForm4 ^F4;
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(740, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Вычисление значения функции и построение графика";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1, 53);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(740, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Шифрование текста";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1, 106);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(740, 47);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Составление списка группы студентов";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1, 159);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(740, 47);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Построение матриц и диаграмм";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 220);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		F1 = gcnew MyForm1();
		F1->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	F2 = gcnew MyForm2();
		F2->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	 F3 = gcnew MyForm3();
		F3->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		F4 = gcnew MyForm4();
		F4->Show();
	}
};
}
