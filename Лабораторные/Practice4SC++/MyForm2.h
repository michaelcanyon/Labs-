#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "stdlib.h"
#include < Windows.h >
#include < stdio.h >
#include < conio.h >
#include <locale.h>
namespace Practice4SC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Encrypt;
	private: System::Windows::Forms::Button^  Decrypt;
	private: System::Windows::Forms::TextBox^  Key;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  Read;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Encrypt = (gcnew System::Windows::Forms::Button());
			this->Decrypt = (gcnew System::Windows::Forms::Button());
			this->Key = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Read = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// Encrypt
			// 
			this->Encrypt->Location = System::Drawing::Point(12, 12);
			this->Encrypt->Name = L"Encrypt";
			this->Encrypt->Size = System::Drawing::Size(75, 23);
			this->Encrypt->TabIndex = 3;
			this->Encrypt->Text = L"Encrypt";
			this->Encrypt->UseVisualStyleBackColor = true;
			this->Encrypt->Click += gcnew System::EventHandler(this, &MyForm2::Encrypt_Click);
			// 
			// Decrypt
			// 
			this->Decrypt->Location = System::Drawing::Point(12, 41);
			this->Decrypt->Name = L"Decrypt";
			this->Decrypt->Size = System::Drawing::Size(75, 23);
			this->Decrypt->TabIndex = 4;
			this->Decrypt->Text = L"Decrypt";
			this->Decrypt->UseVisualStyleBackColor = true;
			this->Decrypt->Click += gcnew System::EventHandler(this, &MyForm2::Decrypt_Click);
			// 
			// Key
			// 
			this->Key->Location = System::Drawing::Point(12, 350);
			this->Key->Name = L"Key";
			this->Key->Size = System::Drawing::Size(100, 20);
			this->Key->TabIndex = 7;
			this->Key->Text = L"Key";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Write";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// Read
			// 
			this->Read->Location = System::Drawing::Point(12, 408);
			this->Read->Name = L"Read";
			this->Read->Size = System::Drawing::Size(75, 23);
			this->Read->TabIndex = 10;
			this->Read->Text = L"Read";
			this->Read->UseVisualStyleBackColor = true;
			this->Read->Click += gcnew System::EventHandler(this, &MyForm2::Read_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(122, 408);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(648, 20);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"Filepath";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(122, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(648, 387);
			this->richTextBox1->TabIndex = 12;
			this->richTextBox1->Text = L"";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 441);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Read);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Key);
			this->Controls->Add(this->Decrypt);
			this->Controls->Add(this->Encrypt);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Encrypt_Click(System::Object^  sender, System::EventArgs^  e) {
		
		std::locale::global(std::locale(""));
		setlocale(LC_ALL, "RUS");
		string buffer;
		string _filepath;
		string pattern = "1234567890-!@#$%^&*()_<>?}{'\";:,./?=`~ ";
		string bk;
		int m;
		wchar_t symbol;
		int alphaNum, div, bufm;
		// считывание и вычисление ключа сдвига
		try
		{
			MarshalString(Key->Text, bk);
			m = atoi(bk.c_str());
		}
		catch (const std::exception&)
		{
			MessageBox::Show("Key Error");
			return;
		}
		m -= 1;
		m %= 66;
		//MarshalString(richTextBox1->Text, buffer);
		int textlength = richTextBox1->TextLength;
		MarshalString(richTextBox1->Text, buffer);
		buffer = buffer.c_str();
		symbol = buffer[0];
		System::Text::Encoding::GetEncoding(1251);
		ofstream file("temp.txt");
		string exp = to_string(symbol);
		int sc=0;
		//сам сдвиг ключа символа
		for (int i = 0; i < textlength; i++)
		{
			symbol =buffer[i];
			if (strchr(pattern.c_str(), symbol) != NULL)
			{
				file << symbol;
				continue;
			}
			alphaNum = symbol - 1040;
			if (alphaNum + m > 66)
			{
				bufm = m - (66 - alphaNum);
				alphaNum = 0;
				div = alphaNum + bufm;
			}
			else
			{
				div = alphaNum + m;
			}

			div += 1040;
			//вставка сдвинутого символа
			buffer.erase(i, 1);//??
			buffer.insert(i, to_string(div));
			file <<char(div);

		}
		//file << "Ёто конец!";
		file.close();
		richTextBox1->Text = gcnew String(buffer.c_str());
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
	private: System::Void Decrypt_Click(System::Object^  sender, System::EventArgs^  e) {
		string buffer;
		string _filepath;
		string pattern = "1234567890-!@#$%^&*()_<>?}{'\";:,./?=`~ ";
		string bk;
		int m;
		char symbol;
		int alphaNum, div, bufm;
		// считывание и вычисление ключа сдвига
		try
		{
			MarshalString(Key->Text, bk);
			m = atoi(bk.c_str());
		}
		catch (const std::exception&)
		{
			MessageBox::Show("Key Error");
			return;
		}
		m -= 1;
		m %= 66;
		MarshalString(richTextBox1->Text, buffer);
		int textlength = buffer.length();
		//сам сдвиг ключа символа
		for (int i = 0; i < textlength; i++)
		{

			symbol = buffer[i];
			alphaNum = symbol - 1040;

			if (m > alphaNum)
			{
				bufm = m - alphaNum;
				alphaNum = 66;
				div = alphaNum - bufm;
			}
			else
			{
				div = alphaNum - m;
			}

			div += 1040;
			if (strchr(pattern.c_str(), symbol) != NULL)
				continue;
			//вставка сдвинутого символа
			buffer.erase(i, 1);//??
			buffer.insert(i, to_string(div));
		}
		richTextBox1->Text = gcnew String(buffer.c_str());
	}
	private: System::Void Read_Click(System::Object^  sender, System::EventArgs^  e) {
		string _filepath;
		string buffer;
		MarshalString(textBox1->Text, _filepath);
		ifstream file(_filepath);
		while (!file.eof())
		{
			file >> buffer;
			richTextBox1->AppendText(gcnew String(buffer.c_str()));
		}
		file.close();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		string _filepath;
		string buffer;

		MarshalString(textBox1->Text, _filepath);
		MarshalString(richTextBox1->Text, buffer);
		ofstream file(_filepath);
		file << buffer;
		file.close();
	}
	};
}
