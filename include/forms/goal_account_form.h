#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/goal_account.h>
#include <forms/models_form.h>

class goal_account_form final : public wxPanel, public model_form  {
public:
    goal_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;
    void reset() override;
    void refresh() override;

private:
    std::shared_ptr<goal_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _goal_name_ctrl;
    wxTextCtrl* _parent_account_id_ctrl;
    wxTextCtrl* _monthly_budget_ctrl;
    wxTextCtrl* _current_balance_ctrl;
    wxTextCtrl* _target_amount_ctrl;
    wxTextCtrl* _target_date_ctrl;
    wxTextCtrl* _last_added_date_ctrl;
};
