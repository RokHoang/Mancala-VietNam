#pragma once
#include "Gameplay.h"

Gameplay myGame;
int tempPos = 1, tempDir = -1;
queue<int> history;
namespace Mancala {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		static int second = 0;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:
		delegate void SetTextDelegate(String^ text, Label^ label);
		void SetText(String^ text, Label^ label){
			// InvokeRequired required compares the thread ID of the
			// calling thread to the thread ID of the creating thread.
			// If these threads are different, it returns true.
			if (label->InvokeRequired)
			{
				SetTextDelegate^ d =
					gcnew SetTextDelegate(this, &MyForm::SetText);
				this->Invoke(d, gcnew array<Object^> { text, label });
			}
			else
			{
				label->Text = text;
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  Start;
	private: System::Windows::Forms::Button^  CCWDir;
	private: System::Windows::Forms::Button^  CWDir;





	protected:

	private:
		array<Button^> ^myButton;
	private: System::Windows::Forms::Label^  Score1;
	private: System::Windows::Forms::Label^  Score2;
	private: System::Windows::Forms::Button^  Run;
	private: System::Windows::Forms::Label^  Log_label;
	private: System::Windows::Forms::Label^  ClockCount;
	private: System::Windows::Forms::TextBox^  TxLog;
	private: System::Windows::Forms::Label^  LbTick;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;





			 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->CCWDir = (gcnew System::Windows::Forms::Button());
			this->CWDir = (gcnew System::Windows::Forms::Button());
			this->Score1 = (gcnew System::Windows::Forms::Label());
			this->Score2 = (gcnew System::Windows::Forms::Label());
			this->Run = (gcnew System::Windows::Forms::Button());
			this->Log_label = (gcnew System::Windows::Forms::Label());
			this->ClockCount = (gcnew System::Windows::Forms::Label());
			this->TxLog = (gcnew System::Windows::Forms::TextBox());
			this->LbTick = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(442, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 29);
			this->label1->TabIndex = 0;
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button0->Location = System::Drawing::Point(28, 176);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(97, 79);
			this->button0->TabIndex = 1;
			this->button0->Text = L"button0";
			this->button0->UseVisualStyleBackColor = false;
			this->button0->Click += gcnew System::EventHandler(this, &MyForm::button0_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button1->Location = System::Drawing::Point(138, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 79);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button3->Location = System::Drawing::Point(344, 86);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 79);
			this->button3->TabIndex = 3;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button4->Location = System::Drawing::Point(447, 86);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(97, 79);
			this->button4->TabIndex = 4;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button5->Location = System::Drawing::Point(550, 86);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(97, 79);
			this->button5->TabIndex = 5;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button6->Location = System::Drawing::Point(654, 176);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(97, 79);
			this->button6->TabIndex = 6;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button7->Location = System::Drawing::Point(550, 264);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(97, 79);
			this->button7->TabIndex = 7;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button8->Location = System::Drawing::Point(447, 264);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(97, 79);
			this->button8->TabIndex = 8;
			this->button8->Text = L"button8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button9->Location = System::Drawing::Point(344, 264);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(97, 79);
			this->button9->TabIndex = 9;
			this->button9->Text = L"button9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button10->Location = System::Drawing::Point(241, 264);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(97, 79);
			this->button10->TabIndex = 10;
			this->button10->Text = L"button10";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button11->Location = System::Drawing::Point(138, 264);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(97, 79);
			this->button11->TabIndex = 11;
			this->button11->Text = L"button11";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(197)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->button2->Location = System::Drawing::Point(241, 86);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 79);
			this->button2->TabIndex = 12;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(3, 9);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(115, 47);
			this->Start->TabIndex = 13;
			this->Start->Text = L"Chơi với máy";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Start_MouseDown);
			// 
			// CCWDir
			// 
			this->CCWDir->BackColor = System::Drawing::Color::Transparent;
			this->CCWDir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CCWDir.BackgroundImage")));
			this->CCWDir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CCWDir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CCWDir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CCWDir.Image")));
			this->CCWDir->Location = System::Drawing::Point(241, 366);
			this->CCWDir->Name = L"CCWDir";
			this->CCWDir->Size = System::Drawing::Size(81, 79);
			this->CCWDir->TabIndex = 14;
			this->CCWDir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->CCWDir->UseVisualStyleBackColor = false;
			this->CCWDir->Click += gcnew System::EventHandler(this, &MyForm::CCWDir_Click);
			// 
			// CWDir
			// 
			this->CWDir->BackColor = System::Drawing::Color::Transparent;
			this->CWDir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CWDir.BackgroundImage")));
			this->CWDir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->CWDir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CWDir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CWDir.Image")));
			this->CWDir->Location = System::Drawing::Point(463, 366);
			this->CWDir->Name = L"CWDir";
			this->CWDir->Size = System::Drawing::Size(81, 79);
			this->CWDir->TabIndex = 14;
			this->CWDir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->CWDir->UseVisualStyleBackColor = false;
			this->CWDir->Click += gcnew System::EventHandler(this, &MyForm::CWDir_Click);
			// 
			// Score1
			// 
			this->Score1->AutoSize = true;
			this->Score1->BackColor = System::Drawing::Color::Linen;
			this->Score1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Score1->Location = System::Drawing::Point(372, 21);
			this->Score1->Name = L"Score1";
			this->Score1->Size = System::Drawing::Size(36, 39);
			this->Score1->TabIndex = 16;
			this->Score1->Text = L"0";
			this->Score1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Score2
			// 
			this->Score2->AutoSize = true;
			this->Score2->BackColor = System::Drawing::Color::Linen;
			this->Score2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Score2->Location = System::Drawing::Point(372, 346);
			this->Score2->Name = L"Score2";
			this->Score2->Size = System::Drawing::Size(36, 39);
			this->Score2->TabIndex = 17;
			this->Score2->Text = L"0";
			this->Score2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Run
			// 
			this->Run->BackColor = System::Drawing::Color::FloralWhite;
			this->Run->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Run->ForeColor = System::Drawing::Color::Goldenrod;
			this->Run->Location = System::Drawing::Point(636, 395);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(140, 50);
			this->Run->TabIndex = 18;
			this->Run->Text = L"Go";
			this->Run->UseVisualStyleBackColor = false;
			this->Run->Click += gcnew System::EventHandler(this, &MyForm::Run_Click);
			// 
			// Log_label
			// 
			this->Log_label->AutoSize = true;
			this->Log_label->Location = System::Drawing::Point(779, 1);
			this->Log_label->Name = L"Log_label";
			this->Log_label->Size = System::Drawing::Size(56, 17);
			this->Log_label->TabIndex = 19;
			this->Log_label->Text = L"Nhật ký";
			// 
			// ClockCount
			// 
			this->ClockCount->AutoSize = true;
			this->ClockCount->Location = System::Drawing::Point(139, 9);
			this->ClockCount->Name = L"ClockCount";
			this->ClockCount->Size = System::Drawing::Size(66, 17);
			this->ClockCount->TabIndex = 20;
			this->ClockCount->Text = L"ThoiGian";
			this->ClockCount->Visible = false;
			// 
			// TxLog
			// 
			this->TxLog->BackColor = System::Drawing::Color::LightGray;
			this->TxLog->Location = System::Drawing::Point(782, 21);
			this->TxLog->Multiline = true;
			this->TxLog->Name = L"TxLog";
			this->TxLog->ReadOnly = true;
			this->TxLog->Size = System::Drawing::Size(141, 466);
			this->TxLog->TabIndex = 22;
			// 
			// LbTick
			// 
			this->LbTick->AutoSize = true;
			this->LbTick->Location = System::Drawing::Point(211, 9);
			this->LbTick->Name = L"LbTick";
			this->LbTick->Size = System::Drawing::Size(0, 17);
			this->LbTick->TabIndex = 23;
			this->LbTick->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(921, 486);
			this->Controls->Add(this->LbTick);
			this->Controls->Add(this->TxLog);
			this->Controls->Add(this->ClockCount);
			this->Controls->Add(this->Log_label);
			this->Controls->Add(this->Run);
			this->Controls->Add(this->Score2);
			this->Controls->Add(this->Score1);
			this->Controls->Add(this->CWDir);
			this->Controls->Add(this->CCWDir);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Ô ăn quan";
			this->ResumeLayout(false);
			this->PerformLayout();
			myButton = gcnew array<Button^> {button0, button1, button2, button3, button4, button5, button6, button7, button8, button9, button10, button11};
		}
#pragma endregion
	private: System::Void Start_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (myGame.count % 2 == 0)
					 label1->Text = L"Lượt người chơi";
				 else
					 label1->Text = L"Lượt của máy";
				 timer1->Enabled = true;
				 if (myGame.getTurn() == 1){
					 for (int i = 1; i <= 5; i++){
						 myButton[i]->Enabled = false;
					 }
					 for (int i = 7; i <= 11; i++)
						 myButton[i]->Enabled = true;
				 }
				 else{
					 for (int i = 1; i <= 5; i++){
						 myButton[i]->Enabled = true;
					 }
					 for (int i = 7; i <= 11; i++)
						 myButton[i]->Enabled = false;
				 }
				 myButton[0]->Enabled = false;
				 myButton[6]->Enabled = false;
				 for (int i = 0; i < 12; i++){
					 myButton[i]->Text = myGame.myBoard.tile[i].ToString();
				 }
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 2;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 1;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 3;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 4;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 5;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 6;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 7;
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 8;
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 10;
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 9;
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 11;
}
private: System::Void button0_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempPos = 0;
}
private: System::Void CCWDir_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempDir = -1;
}
private: System::Void CWDir_Click(System::Object^  sender, System::EventArgs^  e) {
			 tempDir = 1;
}
	private: System::Void Run_Click(System::Object^  sender, System::EventArgs^  e) {
				 second = 0;
				 //my suy nghi
				 if (myGame.getTurn() == 1){
					 myGame.BotThink(tempPos, tempDir);
				 }
				 int tempScore = myGame.myBoard.run(tempPos, tempDir, history);
				 //in log
				 TxLog->Text += tempPos.ToString() + " " + tempDir.ToString() + "\r\n";
				 myGame.myBoard.score[myGame.getTurn()] += tempScore;
				 int tempQueue, posSplit, valueSplit;
				 while(!history.empty()){
					 tempQueue = history.front();
					 history.pop();
					 //tach temp
					 posSplit = tempQueue / 100;
					 valueSplit = tempQueue % 100;
					 myButton[posSplit]->Text = valueSplit.ToString();
					 if (valueSplit == 0)
						 myButton[posSplit]->BackColor = Color::YellowGreen;
					 else
						myButton[posSplit]->BackColor = Color::FromArgb(48, 63, 159);
					 Application::DoEvents();
					 System::Threading::Thread::Sleep(300);
					 myButton[posSplit]->BackColor = Color::FromArgb(197, 202, 233);
					 Application::DoEvents();
					 System::Threading::Thread::Sleep(300);
				 }
				 myGame.swapTurn();
				 Score1->Text = myGame.myBoard.score[0].ToString();
				 Score2->Text = myGame.myBoard.score[1].ToString();
				 myGame.count++;
				 //label1->Text = myGame.count.ToString();
				 second = 0;
				 if (myGame.getTurn() == 1){
					 for (int i = 1; i <= 5; i++){
						 myButton[i]->Enabled = false;
					 }
					 for (int i = 7; i <= 11; i++)
						 myButton[i]->Enabled = true;
				 }
				 else{
					for (int i = 1; i <= 5; i++){
						 myButton[i]->Enabled = true;
					 }
					for (int i = 7; i <= 11; i++)
						 myButton[i]->Enabled = false;
				 }
				 for (int i = 0; i < 12; i++){
					 myButton[i]->Text = myGame.myBoard.tile[i].ToString();
				 }
				 if (!myGame.myBoard.checkMancala()){
					 String^ ketqua = (myGame.myBoard.score[0] > myGame.myBoard.score[1]) ? L"Player win" : L"Computer win";
					 for (int i = 1; i < 6; i++){
						 if (myGame.myBoard.tile[i] != 0){
							 myButton[i]->Text = L"0";
							 myButton[i]->BackColor = Color::YellowGreen;
							 Application::DoEvents();
							 System::Threading::Thread::Sleep(300);
							 myButton[posSplit]->BackColor = Color::FromArgb(197, 202, 233);
							 Application::DoEvents();
							 System::Threading::Thread::Sleep(300);
							 myGame.myBoard.score[0] += myGame.myBoard.tile[i];
							 Score1->Text = myGame.myBoard.score[0].ToString();
							 Score1->ForeColor = Color::Crimson;
						 }
					 }
					 for (int i = 7; i < 12; i++){
						 if (myGame.myBoard.tile[i] != 0){
							 myButton[i]->Text = L"0";
							 myButton[i]->BackColor = Color::YellowGreen;
							 Application::DoEvents();
							 System::Threading::Thread::Sleep(300);
							 myButton[posSplit]->BackColor = Color::FromArgb(197, 202, 233);
							 Application::DoEvents();
							 System::Threading::Thread::Sleep(300);
							 myGame.myBoard.score[1] += myGame.myBoard.tile[i];
							 Score2->Text = myGame.myBoard.score[1].ToString();
							 Score2->ForeColor = Color::Crimson;
						 }
					 }
					 label1->Text = ketqua;
					 Run->Enabled = false;
				 }
				 else{
					 if (myGame.count % 2 == 0)
						 label1->Text = L"Lượt người chơi";
					 else{
						 label1->Text = L"Máy đang suy nghĩ";
						 Application::DoEvents();
						 Run->PerformClick();
					 }
					 
					 
				 }
				 
				 

	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 second++;
			 SetText(second.ToString(), LbTick);
}
};
}