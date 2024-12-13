#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/borrow_give_account.h>

class borrow_give_accounts_panel : public wxPanel {
public:
    borrow_give_accounts_panel(wxWindow *parent, std::shared_ptr<account> account);

    void save();

private:
    std::shared_ptr<borrow_give_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _person_name_ctrl;
    wxTextCtrl* _balance_due_ctrl;
    wxTextCtrl* _due_date_ctrl;
};
