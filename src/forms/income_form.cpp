#include <forms/income_form.h>
#include <models/account.h>

income_form::income_form(wxWindow* parent, std::shared_ptr<transaction> transaction)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize), _transaction(transaction)
{
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    auto to_account_label = new wxStaticText(this, wxID_ANY, "To Account:");
    _to_account_ctrl = new wxComboBox(this, wxID_ANY);
    _main_sizer->Add(to_account_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_to_account_ctrl, 0, wxALL | wxEXPAND, 5);

    auto category_account_label = new wxStaticText(this, wxID_ANY, "Category:");
    _category_account_ctrl = new wxComboBox(this, wxID_ANY);
    _main_sizer->Add(category_account_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_category_account_ctrl, 0, wxALL | wxEXPAND, 5);

    for (auto acc : global_config.accounts) {
        wxString account_name = wxString::FromUTF8(acc.second->account_name());
        auto* account_id_data = new wxString(acc.first);
        std::cout<< account_name <<" "<< account_id_data << std::endl;
        if (acc.second->account_type() == enums::account_type::CATEGORY_ACCOUNT) {
            _category_account_ctrl->Append(account_name, account_id_data);
        } else {
            _to_account_ctrl->Append(account_name, account_id_data);
        }
    }

    auto description_label = new wxStaticText(this, wxID_ANY, "Description:");
    _description_ctrl = new wxTextCtrl(this, wxID_ANY);
    _main_sizer->Add(description_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_description_ctrl, 0, wxALL | wxEXPAND, 5);

    auto amount_label = new wxStaticText(this, wxID_ANY, "Amount:");
    _amount_ctrl = new wxTextCtrl(this, wxID_ANY);
    _main_sizer->Add(amount_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_amount_ctrl, 0, wxALL | wxEXPAND, 5);

    auto date_label = new wxStaticText(this, wxID_ANY, "Date:");
    _date_ctrl = new wxDatePickerCtrl(this, wxID_ANY);
    _main_sizer->Add(date_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_date_ctrl, 0, wxALL | wxEXPAND, 5);

    auto file_label = new wxStaticText(this, wxID_ANY, "Attachment:");
    _file_ctrl = new wxFilePickerCtrl(this, wxID_ANY);
    _main_sizer->Add(file_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_file_ctrl, 0, wxALL | wxEXPAND, 5);

    SetSizer(_main_sizer);
    Layout();
}

void income_form::save() {
    int to_account_selection = _to_account_ctrl->GetSelection();
    int category_account_selection = _category_account_ctrl->GetSelection();

    wxString from_account_id = (to_account_selection != wxNOT_FOUND && _to_account_ctrl->GetClientData(to_account_selection))
        ? *static_cast<wxString*>(_to_account_ctrl->GetClientData(to_account_selection))
        : "";
    wxString category_account_id = (category_account_selection != wxNOT_FOUND && _category_account_ctrl->GetClientData(category_account_selection))
        ? *static_cast<wxString*>(_category_account_ctrl->GetClientData(category_account_selection))
        : "";

    wxString description = _description_ctrl->GetValue();
    wxString amount_str = _amount_ctrl->GetValue();
    wxDateTime date = _date_ctrl->GetValue();
    wxString file_path = _file_ctrl->GetPath();

    double amount = 0.0;
    if (!amount_str.ToDouble(&amount)) {
        wxMessageBox("Invalid amount entered.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    if (from_account_id.IsEmpty() || category_account_id.IsEmpty() || amount <= 0) {
        wxMessageBox("Please fill all required fields with valid data.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    _transaction->transaction_type("INCOME");
    _transaction->from_account_id(from_account_id.ToStdString());
    _transaction->category_account_id(category_account_id.ToStdString());
    _transaction->description(description.ToStdString());
    _transaction->amount(amount);
    _transaction->date(date.FormatISODate().ToStdString());
    _transaction->proof_document(file_path.ToStdString());
    _transaction->print();
    _transaction->save();
}
