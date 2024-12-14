#include <panels/chit_accounts_panel.h>

chit_accounts_panel::chit_accounts_panel(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<chit_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Chit Name
    auto* chit_name_label = new wxStaticText(this, wxID_ANY, "Chit Name:");
    _chit_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->chit_name());
    _main_sizer->Add(chit_name_label, 0, wxALL, 5);
    _main_sizer->Add(_chit_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Monthly Budget
    auto* monthly_budget_label = new wxStaticText(this, wxID_ANY, "Monthly Budget:");
    _monthly_budget_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->monthly_budget()));
    _main_sizer->Add(monthly_budget_label, 0, wxALL, 5);
    _main_sizer->Add(_monthly_budget_ctrl, 0, wxEXPAND | wxALL, 5);

    // Accumulated Balance
    auto* accumulated_balance_label = new wxStaticText(this, wxID_ANY, "Accumulated Balance:");
    _accumulated_balance_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->accumulated_balance()));
    _main_sizer->Add(accumulated_balance_label, 0, wxALL, 5);
    _main_sizer->Add(_accumulated_balance_ctrl, 0, wxEXPAND | wxALL, 5);

    // Mature Amount
    auto* mature_amount_label = new wxStaticText(this, wxID_ANY, "Mature Amount:");
    _mature_amount_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->mature_amount()));
    _main_sizer->Add(mature_amount_label, 0, wxALL, 5);
    _main_sizer->Add(_mature_amount_ctrl, 0, wxEXPAND | wxALL, 5);

    // Mature Date
    auto* mature_date_label = new wxStaticText(this, wxID_ANY, "Mature Date:");
    _mature_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->mature_date().value_or(""));
    _main_sizer->Add(mature_date_label, 0, wxALL, 5);
    _main_sizer->Add(_mature_date_ctrl, 0, wxEXPAND | wxALL, 5);

    // Last Added Date
    auto* last_added_date_label = new wxStaticText(this, wxID_ANY, "Last Added Date:");
    _last_added_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->last_added_date().value_or(""));
    _main_sizer->Add(last_added_date_label, 0, wxALL, 5);
    _main_sizer->Add(_last_added_date_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void chit_accounts_panel::save() {
    _account->account_type(enums::CHIT_ACCOUNT);
    _account->chit_name(std::string(_chit_name_ctrl->GetValue().mb_str()));
    _account->monthly_budget(std::stod(std::string(_monthly_budget_ctrl->GetValue().mb_str())));
    _account->accumulated_balance(std::stod(std::string(_accumulated_balance_ctrl->GetValue().mb_str())));
    _account->mature_amount(std::stod(std::string(_mature_amount_ctrl->GetValue().mb_str())));

    std::string mature_date = std::string(_mature_date_ctrl->GetValue().mb_str());
    _account->mature_date(mature_date.empty() ? std::nullopt : std::make_optional(mature_date));

    std::string last_added_date = std::string(_last_added_date_ctrl->GetValue().mb_str());
    _account->last_added_date(last_added_date.empty() ? std::nullopt : std::make_optional(last_added_date));

    _account->print();
    if (_account->id().empty()) {
        _account->save();
        global_config.accounts[_account->id()] = _account;
    }
    else {
        _account->save();
    }
}
