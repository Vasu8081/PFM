#include <panels/asset_accounts_panel.h>

asset_accounts_panel::asset_accounts_panel(wxWindow *parent, std::shared_ptr<account> account)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _account = std::dynamic_pointer_cast<asset_account>(account);
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Asset Name
    auto* asset_name_label = new wxStaticText(this, wxID_ANY, "Asset Name:");
    _asset_name_ctrl = new wxTextCtrl(this, wxID_ANY, _account->asset_name());
    _main_sizer->Add(asset_name_label, 0, wxALL, 5);
    _main_sizer->Add(_asset_name_ctrl, 0, wxEXPAND | wxALL, 5);

    // Asset Type
    auto* asset_type_label = new wxStaticText(this, wxID_ANY, "Asset Type:");
    _asset_type_ctrl = new wxTextCtrl(this, wxID_ANY, _account->asset_type());
    _main_sizer->Add(asset_type_label, 0, wxALL, 5);
    _main_sizer->Add(_asset_type_ctrl, 0, wxEXPAND | wxALL, 5);

    // Cost of Ownership
    auto* cost_of_ownership_label = new wxStaticText(this, wxID_ANY, "Cost of Ownership:");
    _cost_of_ownership_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->cost_of_ownership()));
    _main_sizer->Add(cost_of_ownership_label, 0, wxALL, 5);
    _main_sizer->Add(_cost_of_ownership_ctrl, 0, wxEXPAND | wxALL, 5);

    // Paid Amount
    auto* paid_amount_label = new wxStaticText(this, wxID_ANY, "Paid Amount:");
    _paid_amount_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->paid_amount()));
    _main_sizer->Add(paid_amount_label, 0, wxALL, 5);
    _main_sizer->Add(_paid_amount_ctrl, 0, wxEXPAND | wxALL, 5);

    // Current Market Value
    auto* current_market_value_label = new wxStaticText(this, wxID_ANY, "Current Market Value:");
    _current_market_value_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_account->current_market_value()));
    _main_sizer->Add(current_market_value_label, 0, wxALL, 5);
    _main_sizer->Add(_current_market_value_ctrl, 0, wxEXPAND | wxALL, 5);

    // Purchase Date
    auto* purchase_date_label = new wxStaticText(this, wxID_ANY, "Purchase Date:");
    _purchase_date_ctrl = new wxTextCtrl(this, wxID_ANY, _account->purchase_date());
    _main_sizer->Add(purchase_date_label, 0, wxALL, 5);
    _main_sizer->Add(_purchase_date_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void asset_accounts_panel::save() {
    _account->account_type(enums::ASSET_ACCOUNT);
    _account->asset_name(std::string(_asset_name_ctrl->GetValue().mb_str()));
    _account->asset_type(std::string(_asset_type_ctrl->GetValue().mb_str()));
    _account->cost_of_ownership(std::stod(std::string(_cost_of_ownership_ctrl->GetValue().mb_str())));
    _account->paid_amount(std::stod(std::string(_paid_amount_ctrl->GetValue().mb_str())));
    _account->current_market_value(std::stod(std::string(_current_market_value_ctrl->GetValue().mb_str())));
    _account->purchase_date(std::string(_purchase_date_ctrl->GetValue().mb_str()));
    _account->print();
    if (_account->id().empty()) {
        _account->save();
        global_config.accounts[_account->id()] = _account;
    }
    else {
        _account->save();
    }
}
