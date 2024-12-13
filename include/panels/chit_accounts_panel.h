#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/chit_account.h>

class chit_accounts_panel : public wxPanel {
public:
    chit_accounts_panel(wxWindow *parent, std::shared_ptr<account> account);

    void save();

private:
    std::shared_ptr<chit_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _chit_name_ctrl;
    wxTextCtrl* _monthly_budget_ctrl;
    wxTextCtrl* _accumulated_balance_ctrl;
    wxTextCtrl* _mature_amount_ctrl;
    wxTextCtrl* _mature_date_ctrl;
    wxTextCtrl* _last_added_date_ctrl;
};
