#include "FiFo.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main(cli::array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew FiFoRSACryptography::FiFo());
}