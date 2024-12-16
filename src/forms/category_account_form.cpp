#include <forms/forms_include.h>

category_account_form::category_account_form(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<category_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Category Name
    auto* category_name_label = new wxStaticText(this, wxID_ANY, "Category Name:");
    _category_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->category_name());
    _main_sizer->Add(category_name_label, 0, wxALL, 5);
    _main_sizer->Add(_category_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Parent Account ID
    auto* parent_account_id_label = new wxStaticText(this, wxID_ANY, "Parent Account ID:");
    _parent_account_id_ctrl = new wxTextCtrl(this, wxID_ANY, _account->parent_account_id());
    _main_sizer->Add(parent_account_id_label, 0, wxALL, 5);
    _main_sizer->Add(_parent_account_id_ctrl, 0, wxEXPAND | wxALL, 5);

    // Monthly Budget
    auto* monthly_budget_label = new wxStaticText(this, wxID_ANY, "Monthly Budget:");
    _monthly_budget_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->monthly_budget()));
    _main_sizer->Add(monthly_budget_label, 0, wxALL, 5);
    _main_sizer->Add(_monthly_budget_ctrl, 0, wxEXPAND | wxALL, 5);

    // Current Balance
    auto* current_balance_label = new wxStaticText(this, wxID_ANY, "Current Balance:");
    _current_balance_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->current_balance()));
    _main_sizer->Add(current_balance_label, 0, wxALL, 5);
    _main_sizer->Add(_current_balance_ctrl, 0, wxEXPAND | wxALL, 5);

    // Last Added Date
    auto* last_added_date_label = new wxStaticText(this, wxID_ANY, "Last Added Date:");
    _last_added_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->last_added_date().value_or(""));
    _main_sizer->Add(last_added_date_label, 0, wxALL, 5);
    _main_sizer->Add(_last_added_date_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void category_account_form::save() {
    _account->account_type(enums::CATEGORY_ACCOUNT);
    _account->category_name(std::string(_category_name_ctrl->GetValue().mb_str()));
    _account->parent_account_id(std::string(_parent_account_id_ctrl->GetValue().mb_str()));
    _account->monthly_budget(std::stod(std::string(_monthly_budget_ctrl->GetValue().mb_str())));
    _account->current_balance(std::stod(std::string(_current_balance_ctrl->GetValue().mb_str())));
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
