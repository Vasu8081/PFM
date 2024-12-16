#include <forms/forms_include.h>

loan_account_form::loan_account_form(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<loan_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Loan Name
    auto* loan_name_label = new wxStaticText(this, wxID_ANY, "Loan Name:");
    _loan_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->loan_name());
    _main_sizer->Add(loan_name_label, 0, wxALL, 5);
    _main_sizer->Add(_loan_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Loan Account Number
    auto* loan_account_number_label = new wxStaticText(this, wxID_ANY, "Loan Account Number:");
    _loan_account_number_ctrl = new wxTextCtrl(this, wxID_ANY, _account->loan_account_number());
    _main_sizer->Add(loan_account_number_label, 0, wxALL, 5);
    _main_sizer->Add(_loan_account_number_ctrl, 0, wxEXPAND | wxALL, 5);

    // Principal Amount
    auto* principal_amount_label = new wxStaticText(this, wxID_ANY, "Principal Amount:");
    _principal_amount_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->principal_amount()));
    _main_sizer->Add(principal_amount_label, 0, wxALL, 5);
    _main_sizer->Add(_principal_amount_ctrl, 0, wxEXPAND | wxALL, 5);

    // Remaining Principal
    auto* remaining_principal_label = new wxStaticText(this, wxID_ANY, "Remaining Principal:");
    _remaining_principal_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->remaining_principal()));
    _main_sizer->Add(remaining_principal_label, 0, wxALL, 5);
    _main_sizer->Add(_remaining_principal_ctrl, 0, wxEXPAND | wxALL, 5);

    // Interest Rate Per Annum
    auto* interest_rate_per_annum_label = new wxStaticText(this, wxID_ANY, "Interest Rate per Annum:");
    _interest_rate_per_annum_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->interest_rate_per_annum()));
    _main_sizer->Add(interest_rate_per_annum_label, 0, wxALL, 5);
    _main_sizer->Add(_interest_rate_per_annum_ctrl, 0, wxEXPAND | wxALL, 5);

    // Installment Start Date
    auto* installment_start_date_label = new wxStaticText(this, wxID_ANY, "Installment Start Date:");
    _installment_start_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->installment_start_date());
    _main_sizer->Add(installment_start_date_label, 0, wxALL, 5);
    _main_sizer->Add(_installment_start_date_ctrl, 0, wxEXPAND | wxALL, 5);

    // Term in Months
    auto* term_in_months_label = new wxStaticText(this, wxID_ANY, "Term in Months:");
    _term_in_months_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->term_in_months()));
    _main_sizer->Add(term_in_months_label, 0, wxALL, 5);
    _main_sizer->Add(_term_in_months_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void loan_account_form::save() {
    _account->account_type(enums::LOAN_ACCOUNT);
    _account->loan_name(std::string(_loan_name_ctrl->GetValue().mb_str()));
    _account->loan_account_number(std::string(_loan_account_number_ctrl->GetValue().mb_str()));
    _account->principal_amount(std::stod(std::string(_principal_amount_ctrl->GetValue().mb_str())));
    _account->remaining_principal(std::stod(std::string(_remaining_principal_ctrl->GetValue().mb_str())));
    _account->interest_rate_per_annum(std::stod(std::string(_interest_rate_per_annum_ctrl->GetValue().mb_str())));
    _account->installment_start_date(std::string(_installment_start_date_ctrl->GetValue().mb_str()));
    _account->term_in_months(std::stoi(std::string(_term_in_months_ctrl->GetValue().mb_str())));
    _account->print();
    if (_account->id().empty()) {
        _account->save();
        global_config.accounts[_account->id()] = _account;
    }
    else {
        _account->save();
    }
}
