#include <panels/transaction_panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

transaction_panel::transaction_panel(wxWindow *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxHORIZONTAL);
}