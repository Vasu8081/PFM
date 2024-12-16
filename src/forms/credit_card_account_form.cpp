#include <forms/forms_include.h>

credit_card_account_form::credit_card_account_form(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<credit_card_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Card Name
    auto* card_name_label = new wxStaticText(this, wxID_ANY, "Card Name:");
    _card_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->card_name());
    _main_sizer->Add(card_name_label, 0, wxALL, 5);
    _main_sizer->Add(_card_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Card Number
    auto* card_number_label = new wxStaticText(this, wxID_ANY, "Card Number:");
    _card_number_ctrl = new wxTextCtrl(this, wxID_ANY, _account->card_number());
    _main_sizer->Add(card_number_label, 0, wxALL, 5);
    _main_sizer->Add(_card_number_ctrl, 0, wxEXPAND | wxALL, 5);

    // Expiry Date
    auto* expiry_date_label = new wxStaticText(this, wxID_ANY, "Expiry Date:");
    _expiry_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->expiry_date());
    _main_sizer->Add(expiry_date_label, 0, wxALL, 5);
    _main_sizer->Add(_expiry_date_ctrl, 0, wxEXPAND | wxALL, 5);

    // CVV
    auto* cvv_label = new wxStaticText(this, wxID_ANY, "CVV:");
    _cvv_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->cvv()));
    _main_sizer->Add(cvv_label, 0, wxALL, 5);
    _main_sizer->Add(_cvv_ctrl, 0, wxEXPAND | wxALL, 5);

    // Credit Limit
    auto* credit_limit_label = new wxStaticText(this, wxID_ANY, "Credit Limit:");
    _credit_limit_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->credit_limit()));
    _main_sizer->Add(credit_limit_label, 0, wxALL, 5);
    _main_sizer->Add(_credit_limit_ctrl, 0, wxEXPAND | wxALL, 5);

    // Balance Due
    auto* balance_due_label = new wxStaticText(this, wxID_ANY, "Balance Due:");
    _balance_due_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->balance_due()));
    _main_sizer->Add(balance_due_label, 0, wxALL, 5);
    _main_sizer->Add(_balance_due_ctrl, 0, wxEXPAND | wxALL, 5);

    // Statement Day
    auto* statement_day_label = new wxStaticText(this, wxID_ANY, "Statement Day:");
    _statement_day_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->statement_day()));
    _main_sizer->Add(statement_day_label, 0, wxALL, 5);
    _main_sizer->Add(_statement_day_ctrl, 0, wxEXPAND | wxALL, 5);

    // Billing Date
    auto* billing_date_label = new wxStaticText(this, wxID_ANY, "Billing Date:");
    _billing_date_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->billing_date()));
    _main_sizer->Add(billing_date_label, 0, wxALL, 5);
    _main_sizer->Add(_billing_date_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void credit_card_account_form::save() {
    _account->account_type(enums::CREDIT_CARD_ACCOUNT);
    _account->card_name(std::string(_card_name_ctrl->GetValue().mb_str()));
    _account->card_number(std::string(_card_number_ctrl->GetValue().mb_str()));
    _account->expiry_date(std::string(_expiry_date_ctrl->GetValue().mb_str()));
    _account->cvv(std::stoi(std::string(_cvv_ctrl->GetValue().mb_str())));
    _account->credit_limit(std::stod(std::string(_credit_limit_ctrl->GetValue().mb_str())));
    _account->balance_due(std::stod(std::string(_balance_due_ctrl->GetValue().mb_str())));
    _account->statement_day(std::stoi(std::string(_statement_day_ctrl->GetValue().mb_str())));
    _account->billing_date(std::stoi(std::string(_billing_date_ctrl->GetValue().mb_str())));

    _account->print();
    if (_account->id().empty()) {
        _account->save();
        global_config.accounts[_account->id()] = _account;
    }
    else {
        _account->save();
    }
}
