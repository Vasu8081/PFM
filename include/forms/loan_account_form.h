#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/loan_account.h>
#include <forms/models_form.h>

class loan_account_form final : public wxPanel, public model_form {
public:
    loan_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;
    void reset() override;
    void refresh() override;

private:
    std::shared_ptr<loan_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _loan_name_ctrl;
    wxTextCtrl* _loan_account_number_ctrl;
    wxTextCtrl* _principal_amount_ctrl;
    wxTextCtrl* _remaining_principal_ctrl;
    wxTextCtrl* _interest_rate_per_annum_ctrl;
    wxTextCtrl* _installment_start_date_ctrl;
    wxTextCtrl* _term_in_months_ctrl;
};
