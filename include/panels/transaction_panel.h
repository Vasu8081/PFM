#pragma once

#include <wx/panel.h>
#include <models/transaction.h>

class transaction_panel : public wxPanel {
public:
    transaction_panel(wxWindow* parent);

private:
    wxSizer* _main_sizer;
};