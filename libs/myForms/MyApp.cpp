#include "MyApp.h"
#include "MainWindow.h"

bool MyApp::OnInit()
{
  wxInitAllImageHandlers();

  MainWindow* mainwin = new MainWindow(NULL);
  mainwin->Show(true);

  return true;
}

int MyApp::OnExit()
{
  return 0;
}