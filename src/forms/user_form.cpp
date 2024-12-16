#include <forms/forms_include.h>

user_form::user_form(wxWindow* parent, std::shared_ptr<user> usr)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _usr = usr;
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // ID
    auto* id_label = new wxStaticText(this, wxID_ANY, "ID:");
    _id_ctrl = new wxTextCtrl(this, wxID_ANY, _usr->id());
    _main_sizer->Add(id_label, 0, wxALL, 5);
    _main_sizer->Add(_id_ctrl, 0, wxEXPAND | wxALL, 5);

    // Name
    auto* name_label = new wxStaticText(this, wxID_ANY, "Name:");
    _name_ctrl = new wxTextCtrl(this, wxID_ANY, _usr->name());
    _main_sizer->Add(name_label, 0, wxALL, 5);
    _main_sizer->Add(_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Email
    auto* email_label = new wxStaticText(this, wxID_ANY, "Email:");
    _email_ctrl = new wxTextCtrl(this, wxID_ANY, _usr->email());
    _main_sizer->Add(email_label, 0, wxALL, 5);
    _main_sizer->Add(_email_ctrl, 0, wxEXPAND | wxALL, 5);

    // Password
    auto* password_label = new wxStaticText(this, wxID_ANY, "Password:");
    _password_ctrl = new wxTextCtrl(this, wxID_ANY, _usr->password(), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    _main_sizer->Add(password_label, 0, wxALL, 5);
    _main_sizer->Add(_password_ctrl, 0, wxEXPAND | wxALL, 5);

    // Mobile (Optional)
    auto* mobile_label = new wxStaticText(this, wxID_ANY, "Mobile (Optional):");
    _mobile_ctrl = new wxTextCtrl(this, wxID_ANY, _usr->mobile().has_value() ? std::to_string(_usr->mobile().value()) : "");
    _main_sizer->Add(mobile_label, 0, wxALL, 5);
    _main_sizer->Add(_mobile_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void user_form::save()
{
    _usr->id(std::string(_id_ctrl->GetValue().mb_str()));
    _usr->name(std::string(_name_ctrl->GetValue().mb_str()));
    _usr->email(std::string(_email_ctrl->GetValue().mb_str()));
    _usr->password(std::string(_password_ctrl->GetValue().mb_str()));

    std::optional<long> mobile = std::nullopt;
    if (!_mobile_ctrl->GetValue().IsEmpty()) {
        mobile = std::stol(std::string(_mobile_ctrl->GetValue().mb_str()));
    }
    _usr->mobile(mobile);
    _usr->print();
    _usr->save();
}
