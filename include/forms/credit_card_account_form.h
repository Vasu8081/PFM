#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/credit_card_account.h>
#include <forms/models_form.h>

class credit_card_account_form final : public wxPanel, public model_form {
public:
    credit_card_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;
    void reset() override;
    void refresh() override;

private:
    std::shared_ptr<credit_card_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _card_name_ctrl;
    wxTextCtrl* _card_number_ctrl;
    wxTextCtrl* _expiry_date_ctrl;
    wxTextCtrl* _cvv_ctrl;
    wxTextCtrl* _credit_limit_ctrl;
    wxTextCtrl* _balance_due_ctrl;
    wxTextCtrl* _statement_day_ctrl;
    wxTextCtrl* _billing_date_ctrl;
};
