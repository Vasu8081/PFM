#include <forms/transfer_form.h>
#include <models/account.h>

transfer_form::transfer_form(wxWindow* parent, std::shared_ptr<transaction> transaction)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize), _transaction(transaction)
{
    _main_sizer = new wxBoxSizer(wxVERTICAL);
    refresh();
    SetSizer(_main_sizer);
    Layout();
}

void transfer_form::save() {
    int from_account_selection = _from_account_ctrl->GetSelection();
    int to_account_selection = _to_account_ctrl->GetSelection();

    wxString from_account_id = (from_account_selection != wxNOT_FOUND && _from_account_ctrl->GetClientData(from_account_selection))
        ? *static_cast<wxString*>(_from_account_ctrl->GetClientData(from_account_selection))
        : "";
    wxString to_account_id = (to_account_selection != wxNOT_FOUND && _to_account_ctrl->GetClientData(to_account_selection))
        ? *static_cast<wxString*>(_to_account_ctrl->GetClientData(to_account_selection))
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

    if (from_account_id.IsEmpty() || to_account_id.IsEmpty() || amount <= 0) {
        wxMessageBox("Please fill all required fields with valid data.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    _transaction->transaction_type("EXPENSE");
    _transaction->from_account_id(from_account_id.ToStdString());
    global_config.accounts[from_account_id.ToStdString()]->expense(amount);
    global_config.accounts[from_account_id.ToStdString()]->save();
    _transaction->to_account_id(to_account_id.ToStdString());
    global_config.accounts[to_account_id.ToStdString()]->income(amount);
    global_config.accounts[to_account_id.ToStdString()]->save();
    _transaction->description(description.ToStdString());
    _transaction->amount(amount);
    _transaction->date(date.FormatISODate().ToStdString());
    _transaction->proof_document(file_path.ToStdString());
    _transaction->print();
    _transaction->save();
}

void transfer_form::reset() {
    _transaction = std::make_shared<transaction>();
    refresh();
}

void transfer_form::refresh() {
    _main_sizer->Clear(true);
    auto from_account_label = new wxStaticText(this, wxID_ANY, "From Account:");
    _from_account_ctrl = new wxComboBox(this, wxID_ANY);
    _main_sizer->Add(from_account_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_from_account_ctrl, 0, wxALL | wxEXPAND, 5);

    auto to_account_label = new wxStaticText(this, wxID_ANY, "To Account:");
    _to_account_ctrl = new wxComboBox(this, wxID_ANY);
    _main_sizer->Add(to_account_label, 0, wxALL | wxEXPAND, 5);
    _main_sizer->Add(_to_account_ctrl, 0, wxALL | wxEXPAND, 5);

    for (auto acc : global_config.accounts) {
        wxString account_name = wxString::FromUTF8(acc.second->account_name());
        auto* account_id_data = new wxString(acc.first);
        if (acc.second->account_type() != enums::account_type::CATEGORY_ACCOUNT) {
            _from_account_ctrl->Append(account_name, account_id_data);
        }
        _to_account_ctrl->Append(account_name, account_id_data);
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
    Layout();
}
