#include <panels/dashboard_panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

dashboard_panel::dashboard_panel(wxWindow *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxHORIZONTAL);
}