#include <iostream>
#include <cmath>
#include <fstream>

#include <algorithm>
#include <sstream>

#include "ClassesTP_visual/LibIHMBandit.h"
#include "ClassesTP_visual/conversion.h"
//#include "MyForm.h" 


#pragma once

namespace TPIHM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;


	/// <summary>
	/// Summary for Form_parametrage
	/// </summary>
	public ref class Form_parametrage : public System::Windows::Forms::Form
	{


	public:
		Form_parametrage(Void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		// déclaraton du délégué qui répresente la méthode à appeler (MyForm::Modifier_fichiers_jeu)
		// et création de l'événement basé sur le délégué
		delegate void ParametresModifiesEventHandler();
		event ParametresModifiesEventHandler^ ParametresModifies;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_parametrage()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ choixCombinaisonToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ combinaisonToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ symbolesToolStripMenuItem;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;









#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->choixCombinaisonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->combinaisonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->symbolesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(39, 64);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox1->Size = System::Drawing::Size(92, 277);
			this->listBox1->TabIndex = 0;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(182, 64);
			this->listBox2->Name = L"listBox2";
			this->listBox2->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBox2->Size = System::Drawing::Size(205, 277);
			this->listBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Liste des symboles";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(179, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Liste des combinaisons gagnantes";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(144, 417);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 34);
			this->button1->TabIndex = 5;
			this->button1->Text = L">> Fermer le formulaire pour procéder au jeu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_parametrage::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->RestoreDirectory = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->choixCombinaisonToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(415, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// choixCombinaisonToolStripMenuItem
			// 
			this->choixCombinaisonToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->combinaisonToolStripMenuItem,
					this->symbolesToolStripMenuItem
			});
			this->choixCombinaisonToolStripMenuItem->Name = L"choixCombinaisonToolStripMenuItem";
			this->choixCombinaisonToolStripMenuItem->Size = System::Drawing::Size(123, 20);
			this->choixCombinaisonToolStripMenuItem->Text = L"Charger des fichiers";
			// 
			// combinaisonToolStripMenuItem
			// 
			this->combinaisonToolStripMenuItem->Name = L"combinaisonToolStripMenuItem";
			this->combinaisonToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->combinaisonToolStripMenuItem->Text = L"Combinaisons";
			this->combinaisonToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form_parametrage::combiToolStripMenuItem_Click);
			// 
			// symbolesToolStripMenuItem
			// 
			this->symbolesToolStripMenuItem->Name = L"symbolesToolStripMenuItem";
			this->symbolesToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->symbolesToolStripMenuItem->Text = L"Symboles";
			this->symbolesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form_parametrage::symbolesToolStripMenuItem_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 360);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(278, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Sélectionnez les combinaisons gagnantes avant de jouer.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 373);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(265, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Les symboles sont automatiquement tous sélectionnés.";
			// 
			// Form_parametrage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 463);
			this->ControlBox = false;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form_parametrage";
			this->Text = L"Formulaire de paramètrage";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion









	private: System::Void symbolesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//Initialisation du openFileDialog1
		String^ relativePath = "./FichiersInit";
		openFileDialog1->InitialDirectory = Path::GetFullPath(relativePath);


		openFileDialog1->Filter = "Fichiers texte (*.smb)|*.smb|Tous les fichiers (*.*)|*.*";



		Stream^ myStream_symb;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream_symb = openFileDialog1->OpenFile()) != nullptr) {
				// Explication :
				// Effacer les éléments de la listBox avant de rajouter les nouveaux éléments
				// lire les bytes dans le Stream
				// les ajouter à listBox directement en les convertissant en char puis en string

				listBox1->Items->Clear();
				listBox1->BeginUpdate();
				Int32 byteRead; //ou int aurait pu marcher aussi
				while ((byteRead = myStream_symb->ReadByte()) != -1) // Read bytes until end-of-file
				{
					//textBox4->AppendText(String::Format("{0:X2} ", byteRead)); // Display in hexadecimal
					if (byteRead != 10) // vérifie que c'est pas un saut de ligne
					{
						//listBox1->Items->Add(String::Format("Item {0}", byteRead));
						listBox1->Items->Add(Convert::ToString(Convert::ToChar(byteRead)));
					}
				}
				listBox1->EndUpdate();

				myStream_symb->Close();
			}
		}
	}




	private: System::Void combiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Initialisation du openFileDialog1
		String^ relativePath = "./FichiersInit";
		openFileDialog1->InitialDirectory = Path::GetFullPath(relativePath);
		openFileDialog1->Filter = "Fichiers texte (*.cmb)|*.cmb|Tous les fichiers (*.*)|*.*";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			StreamReader^ sr = gcnew StreamReader(openFileDialog1->FileName);

			// Explication :
			// Effacer les éléments de la listBox avant de rajouter les nouveaux éléments
			// Lire les octets dans le Stream et les mettre dans un objet String
			// ajouter les objets String à listBox

			listBox2->Items->Clear();
			listBox2->BeginUpdate();
			String^ line;
			while ((line = sr->ReadLine()) != nullptr) {
				array<String^>^ parts = line->Split(' ');

				//cas de 6 symboles  
				if (parts->Length >= 7) {
					String^ formattedLine = String::Format("{0},{1},{2},{3},{4},{5} -> gain : {6}", parts[1], parts[2], parts[3], parts[4], parts[5], parts[6], parts[7]);
					listBox2->Items->Add(formattedLine);
				}

				//cas de 3 symboles  
				else if (parts->Length >= 4) {
					String^ formattedLine = String::Format("{0},{1},{2} -> gain : {3}",parts[1], parts[2], parts[3], parts[4]);
					listBox2->Items->Add(formattedLine);
				}
				
			}
			listBox2->EndUpdate();
		}
	}






	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
   		// Explication
		// Doit récupérer les objets dans la listBox et les mettre dans un fichier
		// Déclanche l'évévenement basé sur le délégué qui réprésente la méthode Modifier_fichiers_jeu pour charger les fichiers du jeu
		// cacher le formulaire de paramètrage

		std::ofstream file_symb("./FichiersOutput/symb_output.smb");
		std::ofstream file_comb("./FichiersOutput/comb_output.cmb");

		// récuperer les objets séléctionnés dans les listBox
		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			String^ SelectedItem = listBox1->Items[i]->ToString();
			char* chaine = string2char(SelectedItem);
			file_symb << chaine << std::endl;
		}

		for (int j = 0; j < listBox2->SelectedItems->Count; j++) {
			String^ selectedItem = listBox2->SelectedItems[j]->ToString();
			std::string item = String2StdString(selectedItem);

			//Enlever le "-> gain :"
			size_t pos = item.find("-> gain :");
			std::string gain = "";
			if (pos != std::string::npos) {
				gain = item.substr(pos + 9);
				item.erase(pos, 10);
			}

			//Remplacer les ',' par des espaces
			std::replace(item.begin(), item.end(), ',', ' ');

			int count = 0;
			std::istringstream iss(item);
			std::string word;
			while (iss >> word) {
				count++; // Count each number in the combination
			}

			// Write to file with the count at the beginning
			file_comb << count-1 << " " << item << std::endl;
		}


		file_symb.close();
		file_comb.close();

	




		// Vérifier si les fichiers sont vides
		bool fichiersVides_comb = false;
		bool fichiersVides_symb = false;

		// Vérification fichier des symboles
		std::ifstream symbFile("./FichiersOutput/symb_output.smb");
		if (symbFile.get() == EOF) {
			fichiersVides_symb = true;
		}
		symbFile.close();

		// Vérification fichier des combinaison
		std::ifstream combFile("./FichiersOutput/comb_output.cmb");
		if (combFile.get() == EOF) {
			fichiersVides_comb = true;
		}
		combFile.close();



		if (!fichiersVides_comb && !fichiersVides_symb) {
			MessageBox::Show("Le paramétrage du jeu réalisé avec succès !");
			ParametresModifies(); // Déclanche l'évenement basé sur le délégué qui réprésente la méthode Modifier_fichiers_jeu
			Hide();
		}
		else if (fichiersVides_comb || fichiersVides_symb) {
			if (fichiersVides_comb) {
				MessageBox::Show("Erreur : Vous n'avez séléctionné aucune combinaison gagnante.\nVeuillez en choisir parmi ceux de la liste.");
			}
			if (fichiersVides_symb) {
				MessageBox::Show("Erreur : Vous n'avez pas chargé les fichiers des symboles.");
			}
		}
		else {
			MessageBox::Show("Erreur inconnu, vérifiez bien que vous avez suivi toutes les instructions.");
		}
	}

};
}