#include <panels/transactions_panel.h>

transaction_panel::transaction_panel(wxWindow* parent, std::shared_ptr<transaction> txn)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _txn = txn;
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    // Description
    auto* description_label = new wxStaticText(this, wxID_ANY, "Description:");
    _description_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->description());
    _main_sizer->Add(description_label, 0, wxALL, 5);
    _main_sizer->Add(_description_ctrl, 0, wxEXPAND | wxALL, 5);

    // Amount
    auto* amount_label = new wxStaticText(this, wxID_ANY, "Amount:");
    _amount_ctrl = new wxTextCtrl(this, wxID_ANY, std::to_string(_txn->amount()));
    _main_sizer->Add(amount_label, 0, wxALL, 5);
    _main_sizer->Add(_amount_ctrl, 0, wxEXPAND | wxALL, 5);

    // Transaction Type
    auto* transaction_type_label = new wxStaticText(this, wxID_ANY, "Transaction Type:");
    _transaction_type_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->transaction_type());
    _main_sizer->Add(transaction_type_label, 0, wxALL, 5);
    _main_sizer->Add(_transaction_type_ctrl, 0, wxEXPAND | wxALL, 5);

    // From Account ID
    auto* from_account_id_label = new wxStaticText(this, wxID_ANY, "From Account ID:");
    _from_account_id_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->from_account_id());
    _main_sizer->Add(from_account_id_label, 0, wxALL, 5);
    _main_sizer->Add(_from_account_id_ctrl, 0, wxEXPAND | wxALL, 5);

    // To Account ID
    auto* to_account_id_label = new wxStaticText(this, wxID_ANY, "To Account ID:");
    _to_account_id_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->to_account_id());
    _main_sizer->Add(to_account_id_label, 0, wxALL, 5);
    _main_sizer->Add(_to_account_id_ctrl, 0, wxEXPAND | wxALL, 5);

    // Category Account ID
    auto* category_account_id_label = new wxStaticText(this, wxID_ANY, "Category Account ID:");
    _category_account_id_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->category_account_id());
    _main_sizer->Add(category_account_id_label, 0, wxALL, 5);
    _main_sizer->Add(_category_account_id_ctrl, 0, wxEXPAND | wxALL, 5);

    // Moved From Account
    auto* moved_from_account_label = new wxStaticText(this, wxID_ANY, "Moved From Account:");
    _moved_from_account_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->moved_from_account());
    _main_sizer->Add(moved_from_account_label, 0, wxALL, 5);
    _main_sizer->Add(_moved_from_account_ctrl, 0, wxEXPAND | wxALL, 5);

    // Date
    auto* date_label = new wxStaticText(this, wxID_ANY, "Date:");
    _date_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->date());
    _main_sizer->Add(date_label, 0, wxALL, 5);
    _main_sizer->Add(_date_ctrl, 0, wxEXPAND | wxALL, 5);

    // Proof Document
    auto* proof_document_label = new wxStaticText(this, wxID_ANY, "Proof Document (Optional):");
    _proof_document_ctrl = new wxTextCtrl(this, wxID_ANY, _txn->proof_document().value_or(""));
    _main_sizer->Add(proof_document_label, 0, wxALL, 5);
    _main_sizer->Add(_proof_document_ctrl, 0, wxEXPAND | wxALL, 5);

    SetSizer(_main_sizer);
    Layout();
}

void transaction_panel::save()
{
    _txn->description(std::string(_description_ctrl->GetValue().mb_str()));
    _txn->amount(std::stod(std::string(_amount_ctrl->GetValue().mb_str())));
    _txn->transaction_type(std::string(_transaction_type_ctrl->GetValue().mb_str()));
    _txn->from_account_id(std::string(_from_account_id_ctrl->GetValue().mb_str()));
    _txn->to_account_id(std::string(_to_account_id_ctrl->GetValue().mb_str()));
    _txn->category_account_id(std::string(_category_account_id_ctrl->GetValue().mb_str()));
    _txn->moved_from_account(std::string(_moved_from_account_ctrl->GetValue().mb_str()));
    _txn->date(std::string(_date_ctrl->GetValue().mb_str()));
    _txn->proof_document(std::optional<std::string>(std::string(_proof_document_ctrl->GetValue().mb_str())));
    _txn->print();
    if (_txn->id().empty()) {
        _txn->save();
        global_config.transactions[_txn->id()] = _txn;
    }
    else {
        _txn->save();
    }
}
