#include <iostream>
#include <cmath>
#include <fstream>

#include <algorithm>
#include <sstream>

#include "ClassesTP_visual/LibIHMBandit.h"
#include "ClassesTP_visual/conversion.h"
#include "Form_parametrage.h"


#pragma once

namespace TPIHM {

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



	public:
		MyForm(void) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			form2 = gcnew Form_parametrage();
			form2->ShowDialog();

			// s'abonner à l'événement pour exécuter la méthode Modifier_fichiers_jeu
			form2->ParametresModifies += gcnew Form_parametrage::ParametresModifiesEventHandler(this, &MyForm::Modifier_fichiers_jeu);
			// remarque : on s'abonne à l'event aprés avoir fait le ShowDialog car sinon on aurait eu un problème au moment de fermer
			// le formulaire de paramétrage car ça fait appel à une méthode qui utilise l'objet bandit alors qu'il n'est pas encore initialisé

			// initialisation du jeu
			bandit = new LibIHMbandit::BanditIHM("./FichiersOutput/symb_output.smb","./FichiersOutput/comb_output.cmb");
		}




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm(){
			if (components){
				delete components;
			}
		}

	private:
		LibIHMbandit::BanditIHM* bandit;
		const int* tableau_symboles;
		int Gain_cumul = 0;
		Form_parametrage^ form2;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ changerLesFichiersDuJeuToolStripMenuItem;


	private: System::ComponentModel::IContainer^ components;







	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->changerLesFichiersDuJeuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 83);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"GO !!!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Mise :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(370, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Gains (ou pertes) cumulés";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(373, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"0";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(35, 55);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 6;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"Schtroumpfs1.gif");
			this->imageList1->Images->SetKeyName(1, L"Schtroumpfs2.gif");
			this->imageList1->Images->SetKeyName(2, L"Schtroumpfs3.gif");
			this->imageList1->Images->SetKeyName(3, L"Schtroumpfs4.gif");
			this->imageList1->Images->SetKeyName(4, L"Schtroumpfs5.gif");
			this->imageList1->Images->SetKeyName(5, L"Schtroumpfs6.gif");
			this->imageList1->Images->SetKeyName(6, L"Schtroumpfs7.gif");
			this->imageList1->Images->SetKeyName(7, L"Schtroumpfs8.gif");
			this->imageList1->Images->SetKeyName(8, L"Schtroumpfs9.gif");
			this->imageList1->Images->SetKeyName(9, L"Schtroumpfs10.gif");
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(30, 147);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(226, 248);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(265, 147);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(226, 248);
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(497, 147);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(226, 248);
			this->pictureBox3->TabIndex = 9;
			this->pictureBox3->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 361);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(262, 361);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(497, 361);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"label7";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(370, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Rapport";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(474, 104);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"label8";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->changerLesFichiersDuJeuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(756, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// changerLesFichiersDuJeuToolStripMenuItem
			// 
			this->changerLesFichiersDuJeuToolStripMenuItem->Name = L"changerLesFichiersDuJeuToolStripMenuItem";
			this->changerLesFichiersDuJeuToolStripMenuItem->Size = System::Drawing::Size(179, 20);
			this->changerLesFichiersDuJeuToolStripMenuItem->Text = L"Changer les paramètres du jeu";
			this->changerLesFichiersDuJeuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::changerLesFichiersDuJeuToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(756, 407);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion





	

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Jouer
		LibIHMbandit::Combinaison* Cnew = new LibIHMbandit::Combinaison();
		int mise = int(numericUpDown1->Value);
		int gain = bandit->jouer(mise, *Cnew);

		//Lecture des élements de la combinaison obtenue et AFFICHAGE
		Modification_pictureBox(Cnew); // code en dessous
		Modification_gain_cumul(gain, mise);
	}
	

	private: System::Void changerLesFichiersDuJeuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		form2->Show();
	}





	
	public: void MyForm::Modification_pictureBox(LibIHMbandit::Combinaison* Cnew) {
		//Lecture des élements de la combinaison obtenue et AFFICHAGE
		unsigned int M; // nb de symboles de la combinaison
		const int* tab_elem = Cnew->lireElts(M);
		
		label5->Text = tab_elem[0].ToString();
		pictureBox1->Image = imageList1->Images[tab_elem[0]];
		label6->Text = tab_elem[1].ToString();
		pictureBox2->Image = imageList1->Images[tab_elem[1]];
		label7->Text = tab_elem[2].ToString();
		pictureBox3->Image = imageList1->Images[tab_elem[2]];
		
		unsigned int rapport = Cnew->lireRapport();
		label8->Text = rapport.ToString();
	}


	public: void MyForm::Modification_gain_cumul(int gain, int mise){
		//Modification du gain cumulé
		if (gain > 0) {
			Gain_cumul += gain;
			MessageBox::Show(gain.ToString() + " €", "Vous avez gagné!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			Gain_cumul -= mise;
		}
		label3->Text = Gain_cumul.ToString() + " €";
	}
	


	
	public: void Modifier_fichiers_jeu(){
		// Méthode déclanché par l'événement au moment de cacher le formulaire de paramétrage
		bandit->charger("./FichiersOutput/symb_output.smb","./FichiersOutput/comb_output.cmb"); //modifie les fichiers du jeu
	}
	
	
};
}
