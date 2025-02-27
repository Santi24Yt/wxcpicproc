#include "MyApp.h"
#include "MainWindow.h"

bool MyApp::OnInit()
{
  srand(time(0));
  wxInitAllImageHandlers();

  MainWindow* mainwin = new MainWindow(NULL);
  mainwin->Show(true);

  return true;
}

int MyApp::OnExit()
{
  return 0;
}