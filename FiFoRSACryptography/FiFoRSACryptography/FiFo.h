#pragma once
#include "RSA.h"
namespace FiFoRSACryptography {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for FiFo
	/// </summary>
	public ref class FiFo : public Form {
	private: 
		RSA* rsa = new RSA();
		List<ull> PrimeList;
		Random r;
		System::Windows::Forms::Label^ LBTitle;
		System::Windows::Forms::Label^ LBPrimes;
		System::Windows::Forms::Label^ LBP;
		System::Windows::Forms::Label^ LBQ;
		System::Windows::Forms::Label^ LBText;
		System::Windows::Forms::Label^ LBClavePública;
		System::Windows::Forms::Label^ LBClavePrivada;
		System::Windows::Forms::Label^ LBPU;
		System::Windows::Forms::Label^ LBPR;
		System::Windows::Forms::Label^ LBEncrypt;
		System::Windows::Forms::TextBox^ TB1;
		System::Windows::Forms::TextBox^ TB2;
		System::Windows::Forms::ComboBox^ CBP;
		System::Windows::Forms::ComboBox^ CBQ;
		System::Windows::Forms::Button^ BEncryption;
		System::Windows::Forms::Button^ BDecryption;
		System::Windows::Forms::Button^ BGenerarLlave;
	public:
		FiFo(void) {
			InitializeComponent();
			GeneratePrimesNumber();
			FullCombobox();
			GenerateKeys();
		}
	protected:
		~FiFo() {
			if (components)
				delete components;	
		}
	private:
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->LBTitle = (gcnew System::Windows::Forms::Label());
			this->LBPrimes = (gcnew System::Windows::Forms::Label());
			this->LBP = (gcnew System::Windows::Forms::Label());
			this->LBQ = (gcnew System::Windows::Forms::Label());
			this->LBText = (gcnew System::Windows::Forms::Label());
			this->LBClavePública = (gcnew System::Windows::Forms::Label());
			this->LBClavePrivada = (gcnew System::Windows::Forms::Label());
			this->LBPU = (gcnew System::Windows::Forms::Label());
			this->LBPR = (gcnew System::Windows::Forms::Label());
			this->LBEncrypt = (gcnew System::Windows::Forms::Label());
			this->TB1 = (gcnew System::Windows::Forms::TextBox());
			this->TB2 = (gcnew System::Windows::Forms::TextBox());
			this->CBP = (gcnew System::Windows::Forms::ComboBox());
			this->CBQ = (gcnew System::Windows::Forms::ComboBox());
			this->BEncryption = (gcnew System::Windows::Forms::Button());
			this->BDecryption = (gcnew System::Windows::Forms::Button());
			this->BGenerarLlave = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LBTitle
			// 
			this->LBTitle->AutoSize = true;
			this->LBTitle->Font = (gcnew System::Drawing::Font(L"Sitka Text", 45, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBTitle->Location = System::Drawing::Point(195, 10);
			this->LBTitle->Name = L"LBTitle";
			this->LBTitle->Size = System::Drawing::Size(551, 87);
			this->LBTitle->TabIndex = 0;
			this->LBTitle->Text = L"Encriptación RSA";
			// 
			// LBPrimes
			// 
			this->LBPrimes->AutoSize = true;
			this->LBPrimes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBPrimes->Location = System::Drawing::Point(539, 145);
			this->LBPrimes->Name = L"LBPrimes";
			this->LBPrimes->Size = System::Drawing::Size(160, 25);
			this->LBPrimes->TabIndex = 1;
			this->LBPrimes->Text = L"Números primos:";
			// 
			// LBP
			// 
			this->LBP->AutoSize = true;
			this->LBP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBP->Location = System::Drawing::Point(540, 190);
			this->LBP->Name = L"LBP";
			this->LBP->Size = System::Drawing::Size(23, 20);
			this->LBP->TabIndex = 2;
			this->LBP->Text = L"P:";
			// 
			// LBQ
			// 
			this->LBQ->AutoSize = true;
			this->LBQ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBQ->Location = System::Drawing::Point(674, 190);
			this->LBQ->Name = L"LBQ";
			this->LBQ->Size = System::Drawing::Size(25, 20);
			this->LBQ->TabIndex = 3;
			this->LBQ->Text = L"Q:";
			// 
			// LBText
			// 
			this->LBText->AutoSize = true;
			this->LBText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBText->Location = System::Drawing::Point(20, 106);
			this->LBText->Name = L"LBText";
			this->LBText->Size = System::Drawing::Size(74, 25);
			this->LBText->TabIndex = 4;
			this->LBText->Text = L"Texto:";
			// 
			// LBClavePública
			// 
			this->LBClavePública->AutoSize = true;
			this->LBClavePública->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBClavePública->Location = System::Drawing::Point(20, 430);
			this->LBClavePública->Name = L"LBClavePública";
			this->LBClavePública->Size = System::Drawing::Size(182, 25);
			this->LBClavePública->TabIndex = 5;
			this->LBClavePública->Text = L"Clave pública(n, e):";
			// 
			// LBClavePrivada
			// 
			this->LBClavePrivada->AutoSize = true;
			this->LBClavePrivada->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBClavePrivada->Location = System::Drawing::Point(240, 430);
			this->LBClavePrivada->Name = L"LBClavePrivada";
			this->LBClavePrivada->Size = System::Drawing::Size(184, 25);
			this->LBClavePrivada->TabIndex = 6;
			this->LBClavePrivada->Text = L"Clave privada(n, d):";
			// 
			// LBPU
			// 
			this->LBPU->AutoSize = true;
			this->LBPU->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBPU->Location = System::Drawing::Point(30, 470);
			this->LBPU->Name = L"LBPU";
			this->LBPU->Size = System::Drawing::Size(0, 20);
			this->LBPU->TabIndex = 7;
			// 
			// LBPR
			// 
			this->LBPR->AutoSize = true;
			this->LBPR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBPR->Location = System::Drawing::Point(240, 470);
			this->LBPR->Name = L"LBPR";
			this->LBPR->Size = System::Drawing::Size(0, 20);
			this->LBPR->TabIndex = 8;
			// 
			// LBEncrypt
			// 
			this->LBEncrypt->AutoSize = true;
			this->LBEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBEncrypt->Location = System::Drawing::Point(450, 380);
			this->LBEncrypt->Name = L"LBEncrypt";
			this->LBEncrypt->Size = System::Drawing::Size(138, 25);
			this->LBEncrypt->TabIndex = 9;
			this->LBEncrypt->Text = L"Encriptación:";
			// 
			// TB1
			// 
			this->TB1->Location = System::Drawing::Point(25, 145);
			this->TB1->Multiline = true;
			this->TB1->Name = L"TB1";
			this->TB1->Size = System::Drawing::Size(410, 280);
			this->TB1->TabIndex = 10;
			// 
			// TB2
			// 
			this->TB2->Location = System::Drawing::Point(450, 430);
			this->TB2->Multiline = true;
			this->TB2->Name = L"TB2";
			this->TB2->Size = System::Drawing::Size(470, 250);
			this->TB2->TabIndex = 11;
			// 
			// CBP
			// 
			this->CBP->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CBP->FormattingEnabled = true;
			this->CBP->Location = System::Drawing::Point(490, 220);
			this->CBP->Name = L"CBP";
			this->CBP->Size = System::Drawing::Size(121, 21);
			this->CBP->TabIndex = 12;
			// 
			// CBQ
			// 
			this->CBQ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CBQ->FormattingEnabled = true;
			this->CBQ->Location = System::Drawing::Point(625, 220);
			this->CBQ->Name = L"CBQ";
			this->CBQ->Size = System::Drawing::Size(121, 21);
			this->CBQ->TabIndex = 13;
			// 
			// BEncryption
			// 
			this->BEncryption->Location = System::Drawing::Point(100, 106);
			this->BEncryption->Name = L"BEncryption";
			this->BEncryption->Size = System::Drawing::Size(90, 30);
			this->BEncryption->TabIndex = 14;
			this->BEncryption->Text = L"Encryption";
			this->BEncryption->UseVisualStyleBackColor = true;
			this->BEncryption->Click += gcnew System::EventHandler(this, &FiFo::BEncryption_Click);
			// 
			// BDecryption
			// 
			this->BDecryption->Location = System::Drawing::Point(594, 378);
			this->BDecryption->Name = L"BDecryption";
			this->BDecryption->Size = System::Drawing::Size(90, 30);
			this->BDecryption->TabIndex = 15;
			this->BDecryption->Text = L"Decryption";
			this->BDecryption->UseVisualStyleBackColor = true;
			this->BDecryption->Click += gcnew System::EventHandler(this, &FiFo::BDecryption_Click);
			// 
			// BGenerarLlave
			// 
			this->BGenerarLlave->Location = System::Drawing::Point(567, 287);
			this->BGenerarLlave->Name = L"BGenerarLlave";
			this->BGenerarLlave->Size = System::Drawing::Size(90, 30);
			this->BGenerarLlave->TabIndex = 16;
			this->BGenerarLlave->Text = L"Generar Llaves";
			this->BGenerarLlave->UseVisualStyleBackColor = true;
			this->BGenerarLlave->Click += gcnew System::EventHandler(this, &FiFo::BGenerarLlave_Click);
			// 
			// FiFo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 706);
			this->Controls->Add(this->BGenerarLlave);
			this->Controls->Add(this->BDecryption);
			this->Controls->Add(this->BEncryption);
			this->Controls->Add(this->CBQ);
			this->Controls->Add(this->CBP);
			this->Controls->Add(this->TB2);
			this->Controls->Add(this->TB1);
			this->Controls->Add(this->LBEncrypt);
			this->Controls->Add(this->LBPR);
			this->Controls->Add(this->LBPU);
			this->Controls->Add(this->LBClavePrivada);
			this->Controls->Add(this->LBClavePública);
			this->Controls->Add(this->LBText);
			this->Controls->Add(this->LBQ);
			this->Controls->Add(this->LBP);
			this->Controls->Add(this->LBPrimes);
			this->Controls->Add(this->LBTitle);
			this->Name = L"FiFo";
			this->Text = L"RSA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		private: vector<string> split(const string& s, char delim) {
			stringstream ss(s);
			string item;
			vector<string> elems;
			while (getline(ss, item, delim))
				elems.push_back(item);
			return elems;
		}
		private: void GeneratePrimesNumber() {
			bool* primo = new bool[N];
			for (unsigned i = 0; i < N; i++)
				primo[i] = true;
			for (unsigned i = 2; i < N; i++) {
				for (unsigned j = 2; i * j < N; j++)
					primo[i * j] = false;
			}
			for (unsigned i = 0; i < N; i++) {
				if (primo[i])
					PrimeList.Add(i);
			}
			delete primo;
		}
		private: void FullCombobox() {
			for (int i = 2;i < PrimeList.Count;i++) {
				CBP->Items->Add(PrimeList[i]);
				CBQ->Items->Add(PrimeList[i]);
			}
			int indexR, indexR2;
			do {
				indexR = r.Next(0, PrimeList.Count - 100);
				indexR2 = r.Next(0, PrimeList.Count - 100);
			} while (indexR == indexR2);
			CBP->SelectedIndex = indexR;
			CBQ->SelectedIndex = indexR2;
		}
		private: bool Condition() {
			return this->CBP->SelectedIndex == this->CBQ->SelectedIndex;
		}
		private: Void GenerateKeys() {
			if (Condition()) {
				MessageBox::Show("Los numeros primos no deben ser iguales");
			}
			else {
				string NumberPStandard = "";
				MarshalString(CBP->Text, NumberPStandard);
				rsa->SetMyPrivateKeyP(NumberPStandard);
				string NumberQStandard = "";
				MarshalString(CBQ->Text, NumberQStandard);
				rsa->SetMyPrivateKeyQ(NumberQStandard);
				int Dindex = r.Next(250, PrimeList.Count - 250);
				ull d = PrimeList[Dindex];
				rsa->CreateKey(d);
				LBPU->Text = "(" + rsa->GetPublicKey().n + "," + rsa->GetPublicKey().e + ")";
				LBPR->Text = "(" + rsa->GetPublicKey().n + "," + rsa->GetPrivateKey().d + ")";
			}
		}
		
		private: Void BEncryption_Click(Object^ sender, EventArgs^ e) {
			string MensajeEncryp = "";
			MarshalString(TB1->Text, MensajeEncryp);
			rsa->SetMessage(MensajeEncryp);
			vector<ull> aux = rsa->EncryptationMetodRSA();
			TB2->Text = "";
			for (int i = 0; i < aux.size(); i++) {
				String^ visualiza = aux[i].ToString() + " ";
				TB2->Text += visualiza;
			}
		}
		private: Void BDecryption_Click(Object^ sender, EventArgs^ e) {
			String^ tc = TB2->Text;
			string textoCifrado = "";
			MarshalString(TB2->Text, textoCifrado);
			vector<string> stringCodes = split(textoCifrado, ' ');
			vector<ull> codes;
			for (int i = 0; i < stringCodes.size(); i++)
				codes.push_back(stoll(stringCodes[i]));
			string textoOriginal = rsa->DecryptationMethod(codes);
			String^ visualiza = gcnew String(textoOriginal.c_str());
			TB1->Text = visualiza;
		}
		private: Void BGenerarLlave_Click(Object^ sender, EventArgs^ e) {
			GenerateKeys();
		}
	};
}
