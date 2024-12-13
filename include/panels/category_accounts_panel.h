#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/category_account.h>

class category_accounts_panel : public wxPanel {
public:
    category_accounts_panel(wxWindow *parent, std::shared_ptr<account> account);

    void save();

private:
    std::shared_ptr<category_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _category_name_ctrl;
    wxTextCtrl* _parent_account_id_ctrl;
    wxTextCtrl* _monthly_budget_ctrl;
    wxTextCtrl* _current_balance_ctrl;
    wxTextCtrl* _last_added_date_ctrl;
};
