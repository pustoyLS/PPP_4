#pragma once
#include "Source.h"
#include <string>
#include "MyForm2.h"
namespace Project2 {

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
	private: System::Windows::Forms::Label^ label3;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(148, 133);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Direction";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(197, 127);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 26;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(211, 151);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 19);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(197, 104);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(102, 20);
			this->textBox2->TabIndex = 24;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(109, 109);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Passport Number";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(197, 81);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(102, 20);
			this->textBox1->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(160, 86);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Name";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(211, 174);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Show";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(542, 337);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	
		TicketOffice* ticketOffice = new TicketOffice;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->Items->Add("MUCHOSRANSK");
		comboBox1->Items->Add("SYBERIA");
		comboBox1->Items->Add("PUTINKA");
		comboBox1->SelectedIndex = 0;

	}
		   string SystemToStl(String^ s)
		   {
			   using namespace Runtime::InteropServices;
			   const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			   return string(ptr);
		   }
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		String^ nametemp = textBox1->Text;
		String^ passportNumberTemp = textBox2->Text;
		string name = SystemToStl(nametemp);
		string passportNumber = SystemToStl(passportNumberTemp);
		if (!isValidName(name)) {
			MessageBox::Show("Имя должно содержать только буквы и не превышать 50 символов.");
			return;
		}
		if (!isValidPassport(passportNumber)) {
			MessageBox::Show("Номер паспорта должен содержать только цифры и не превышать 10 символов.");
			return;
		}
		ticketOffice->addFare(Fare(Direction::MUCHOSRANSK, 150.0));
		ticketOffice->addFare(Fare(Direction::SYBERIA, 200.0));
		ticketOffice->addFare(Fare(Direction::PUTINKA, 100.0));
		if (name.length() != 0) {
			if (passportNumber.length() != 0) {

				if (comboBox1->SelectedItem->ToString() == "MUCHOSRANSK") {
					Passenger passenger(name, passportNumber);
					ticketOffice->sellTicket(passenger, Direction::MUCHOSRANSK);
				}
				else if (comboBox1->SelectedItem->ToString() == "PUTINKA") {
					Passenger passenger(name, passportNumber);
					ticketOffice->sellTicket(passenger, Direction::PUTINKA);
				}
				else if (comboBox1->SelectedItem->ToString() == "SYBERIA") {
					Passenger passenger(name, passportNumber);
					ticketOffice->sellTicket(passenger, Direction::SYBERIA);
				}
			}
		}
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ form2 = gcnew MyForm2();
		form2->SetVal(ticketOffice);
		form2->ShowDialog();
	}
	};
}