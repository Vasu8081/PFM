#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/category_account.h>
#include <forms/models_form.h>

class category_account_form final : public wxPanel, public model_form {
public:
    category_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;

private:
    std::shared_ptr<category_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _category_name_ctrl;
    wxTextCtrl* _parent_account_id_ctrl;
    wxTextCtrl* _monthly_budget_ctrl;
    wxTextCtrl* _current_balance_ctrl;
    wxTextCtrl* _last_added_date_ctrl;
};
