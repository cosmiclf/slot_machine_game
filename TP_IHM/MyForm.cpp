#include "MyForm.h"
#include "Form_parametrage.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew TPIHM::MyForm);
	
	return 0;
}
