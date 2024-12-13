#include <panels/borrow_give_accounts_panel.h>

borrow_give_accounts_panel::borrow_give_accounts_panel(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<borrow_give_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Person Name
    auto* person_name_label = new wxStaticText(this, wxID_ANY, "Person Name:");
    _person_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->person_name());
    _main_sizer->Add(person_name_label, 0, wxALL, 5);
    _main_sizer->Add(_person_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Balance Due
    auto* balance_due_label = new wxStaticText(this, wxID_ANY, "Balance Due:");
    _balance_due_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->balance_due()));
    _main_sizer->Add(balance_due_label, 0, wxALL, 5);
    _main_sizer->Add(_balance_due_ctrl, 0, wxEXPAND | wxALL, 5);

    // Due Date
    auto* due_date_label = new wxStaticText(this, wxID_ANY, "Due Date:");
    _due_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->due_date().value_or(""));
    _main_sizer->Add(due_date_label, 0, wxALL, 5);
    _main_sizer->Add(_due_date_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void borrow_give_accounts_panel::save() {
    _account->person_name(std::string(_person_name_ctrl->GetValue().mb_str()));
    _account->balance_due(std::stod(std::string(_balance_due_ctrl->GetValue().mb_str())));
    std::string due_date = std::string(_due_date_ctrl->GetValue().mb_str());
    _account->due_date(due_date.empty() ? std::nullopt : std::make_optional(due_date));
    _account->print();
    _account->save();
}
