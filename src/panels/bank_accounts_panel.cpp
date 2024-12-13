#include <panels/bank_accounts_panel.h>

bank_accounts_panel::bank_accounts_panel(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<bank_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Bank Name
    auto* bank_name_label = new wxStaticText(this, wxID_ANY, "Bank Name:");
    _bank_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->bank_name());
    _main_sizer->Add(bank_name_label, 0, wxALL, 5);
    _main_sizer->Add(_bank_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Account Number
    auto* account_number_label = new wxStaticText(this, wxID_ANY, "Account Number:");
    _account_number_ctrl = new wxTextCtrl(this, wxID_ANY, _account->account_number());
    _main_sizer->Add(account_number_label, 0, wxALL, 5);
    _main_sizer->Add(_account_number_ctrl, 0, wxEXPAND | wxALL, 5);

    // Balance
    auto* balance_label = new wxStaticText(this, wxID_ANY, "Balance:");
    _balance_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->balance()));
    _main_sizer->Add(balance_label, 0, wxALL, 5);
    _main_sizer->Add(_balance_ctrl, 0, wxEXPAND | wxALL, 5);

    // Hold Amount
    auto* hold_amount_label = new wxStaticText(this, wxID_ANY, "Hold Amount:");
    _hold_amount_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->hold_amount()));
    _main_sizer->Add(hold_amount_label, 0, wxALL, 5);
    _main_sizer->Add(_hold_amount_ctrl, 0, wxEXPAND | wxALL, 5);

    // IFSC Code
    auto* ifsc_code_label = new wxStaticText(this, wxID_ANY, "IFSC Code:");
    _ifsc_code_ctrl = new wxTextCtrl(this, wxID_ANY, _account->ifsc_code().value_or(""));
    _main_sizer->Add(ifsc_code_label, 0, wxALL, 5);
    _main_sizer->Add(_ifsc_code_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void bank_accounts_panel::save() {
    _account->account_number(std::string(_account_number_ctrl->GetValue().mb_str()));
    _account->bank_name(std::string(_bank_name_ctrl->GetValue().mb_str()));
    _account->balance(std::stod(std::string(_balance_ctrl->GetValue().mb_str())));
    _account->hold_amount(std::stod(std::string(_hold_amount_ctrl->GetValue().mb_str())));
    std::string ifsc_code = std::string(_ifsc_code_ctrl->GetValue().mb_str());
    _account->ifsc_code(ifsc_code.empty() ? std::nullopt : std::make_optional(ifsc_code));
    _account->print();
    _account->save();
}
