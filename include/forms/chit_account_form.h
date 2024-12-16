#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/chit_account.h>
#include <forms/models_form.h>

class chit_account_form final : public wxPanel, public model_form {
public:
    chit_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;

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
