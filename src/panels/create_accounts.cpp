#include <panels/create_accounts.h>

create_accounts_panel::create_accounts_panel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxVERTICAL);

    _notebook = new wxNotebook(this, wxID_ANY);
    _main_sizer->Add(_notebook, 1, wxEXPAND | wxALL, 10);

    add_bank_account_page();
    add_credit_card_account_page();
    add_loan_account_page();
    add_category_account_page();
    add_goal_account_page();
    add_chit_account_page();
    add_borrow_give_account_page();
    add_asset_account_page();
    auto form = new transaction_form(_notebook, std::make_shared<transaction>());
    _notebook->AddPage(form, "Transaction");
    _form.push_back(form);

    auto* button_sizer = new wxBoxSizer(wxHORIZONTAL);
    auto* ok_button = new wxButton(this, wxID_OK, "Save");
    ok_button->Bind(wxEVT_BUTTON, &create_accounts_panel::on_save, this);
    auto* cancel_button = new wxButton(this, wxID_CANCEL, "Cancel");
    button_sizer->Add(ok_button, 0, wxALL, 5);
    button_sizer->Add(cancel_button, 0, wxALL, 5);

    _main_sizer->Add(button_sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    SetSizerAndFit(_main_sizer);
    Layout();
}

void create_accounts_panel::add_bank_account_page(){
    auto form = new bank_account_form(_notebook, std::make_shared<bank_account>());
    _notebook->AddPage(form, "Bank Account");
    _form.push_back(form);
}

void create_accounts_panel::add_credit_card_account_page(){
    auto form = new credit_card_account_form(_notebook, std::make_shared<credit_card_account>());
    _notebook->AddPage(form, "Credit Card Account");
    _form.push_back(form);
}

void create_accounts_panel::add_loan_account_page(){
    auto form = new loan_account_form(_notebook, std::make_shared<loan_account>());
    _notebook->AddPage(form, "Loan Account");
    _form.push_back(form);
}

void create_accounts_panel::add_category_account_page(){
    auto form = new category_account_form(_notebook, std::make_shared<category_account>());
    _notebook->AddPage(form, "Category Account");
    _form.push_back(form);
}

void create_accounts_panel::add_goal_account_page(){
    auto form = new goal_account_form(_notebook, std::make_shared<goal_account>());
    _notebook->AddPage(form, "Goal Account");
    _form.push_back(form);
}

void create_accounts_panel::add_chit_account_page(){
    auto form = new chit_account_form(_notebook, std::make_shared<chit_account>());
    _notebook->AddPage(form, "Chit Account");
    _form.push_back(form);
}

void create_accounts_panel::add_borrow_give_account_page(){
    auto form = new borrow_give_account_form(_notebook, std::make_shared<borrow_give_account>());
    _notebook->AddPage(form, "Borrow/Give Account");
    _form.push_back(form);
}

void create_accounts_panel::add_asset_account_page(){
    auto form = new asset_account_form(_notebook, std::make_shared<asset_account>());
    _notebook->AddPage(form, "Asset Account");
    _form.push_back(form);
}

void create_accounts_panel::on_save(wxCommandEvent& event){
    int selected_page = _notebook->GetSelection();
    _form[selected_page]->save();
    _form[selected_page]->reset();
    for (int i = 0; i < _form.size(); i++) {
        _form[i]->refresh();
    }
}
