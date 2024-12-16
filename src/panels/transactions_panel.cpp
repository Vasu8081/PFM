#include <panels/transactions_panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

transactions_panel::transactions_panel(wxWindow *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxHORIZONTAL);
}