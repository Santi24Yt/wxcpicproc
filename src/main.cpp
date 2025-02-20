#include <wx/wx.h>

#include "wxWidgets/wxFbApp.h"

class MyApp : public wxApp
{
  public:

  virtual bool OnInit()
  {
    MainWindow *mainwin = new MainWindow(NULL);
    mainwin->Show(true);

    return true;
  }
};

IMPLEMENT_APP(MyApp)
