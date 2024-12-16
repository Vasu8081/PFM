#include <forms/expense_form.h>
#include <forms/forms_include.h>
#include <forms/income_form.h>
#include <forms/transfer_form.h>

transaction_form::transaction_form(wxWindow* parent, std::shared_ptr<transaction> txn)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _txn = txn;
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    _notebook = new wxNotebook(this, wxID_ANY);
    _main_sizer->Add(_notebook, 1, wxEXPAND | wxALL, 10);

    add_income_page();
    add_expense_page();
    add_transfer_page();

    SetSizer(_main_sizer);
    Layout();
}

void transaction_form::add_income_page() {
    auto form = new income_form(_notebook, _txn);
    _notebook->AddPage(form, wxString("Income Page"));
    _forms.push_back(form);
}

void transaction_form::add_expense_page() {
    auto form = new expense_form(_notebook, _txn);
    _notebook->AddPage(form, wxString("Expense Page"));
    _forms.push_back(form);
}

void transaction_form::add_transfer_page() {
    auto form = new transfer_form(_notebook, _txn);
    _notebook->AddPage(form, wxString("Transfer Page"));
    _forms.push_back(form);
}

void transaction_form::save()
{
    int selected_page = _notebook->GetSelection();
    _forms[selected_page]->save();
}
