#pragma once

#include <wx/panel.h>
#include <models/transaction.h>

class transactions_panel : public wxPanel {
public:
    transactions_panel(wxWindow* parent);

private:
    wxSizer* _main_sizer;
};