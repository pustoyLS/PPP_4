#pragma once
#include "Source.h"
#include <msclr/marshal_cppstd.h>

namespace Project2 {

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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:

	protected:
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(437, 484);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(539, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(539, 204);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"load";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 524);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		TicketOffice* off;
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public:
		void SetVal(TicketOffice* ticketOffice) {
			listBox1->Items->Clear();
			double totalSales = ticketOffice->calculateTotal();
			listBox1->Items->Add("Total sales: $" + totalSales.ToString());
			off = ticketOffice;
			std::vector<std::pair<std::string, Direction>> directions = {
				{"List of passengers for Muchosransk:", Direction::MUCHOSRANSK},
				{"List of passengers for Syberia:", Direction::SYBERIA},
				{"List of passengers for Putinka:", Direction::PUTINKA}
			};

			for (const auto& directionInfo : directions) {
				listBox1->Items->Add(gcnew String(directionInfo.first.c_str()));
				for (const auto& passengerInfo : ticketOffice->listPassengers(directionInfo.second)) {
					listBox1->Items->Add(gcnew String(passengerInfo.c_str()));
				}
			}
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			std::string filename = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
			off->saveToFile(filename);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			std::string filename = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			off->loadFromFile(filename);
			SetVal(off);
		}
	}
	};
}