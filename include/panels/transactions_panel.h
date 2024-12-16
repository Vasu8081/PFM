#pragma once

#include <wx/panel.h>
#include <models/transaction.h>
#include <wx/dataview.h>

class transactions_panel : public wxPanel {
public:
    transactions_panel(wxWindow* parent);

    void load_ui();

private:
    wxSizer* _main_sizer;
    wxDataViewListCtrl* _transactions_list;
};