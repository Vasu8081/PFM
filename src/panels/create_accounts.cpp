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
    _bank_accounts_panel = new bank_accounts_panel(_notebook, std::make_shared<bank_account>());
    _notebook->AddPage(_bank_accounts_panel, "Bank Account");
}

void create_accounts_panel::add_credit_card_account_page(){
    _credit_card_account_panel = new credit_card_accounts_panel(_notebook, std::make_shared<credit_card_account>());
    _notebook->AddPage(_credit_card_account_panel, "Credit Card Account");
}

void create_accounts_panel::add_loan_account_page(){
    _loan_account_panel = new loan_accounts_panel(_notebook, std::make_shared<loan_account>());
    _notebook->AddPage(_loan_account_panel, "Loan Account");
}

void create_accounts_panel::add_category_account_page(){
    _category_account_panel = new category_accounts_panel(_notebook, std::make_shared<category_account>());
    _notebook->AddPage(_category_account_panel, "Category Account");
}

void create_accounts_panel::add_goal_account_page(){
    _goal_account_panel = new goal_accounts_panel(_notebook, std::make_shared<goal_account>());
    _notebook->AddPage(_goal_account_panel, "Goal Account");
}

void create_accounts_panel::add_chit_account_page(){
    _chit_account_panel = new chit_accounts_panel(_notebook, std::make_shared<chit_account>());
    _notebook->AddPage(_chit_account_panel, "Chit Account");
}

void create_accounts_panel::add_borrow_give_account_page(){
    _borrow_give_account_panel = new borrow_give_accounts_panel(_notebook, std::make_shared<borrow_give_account>());
    _notebook->AddPage(_borrow_give_account_panel, "Borrow/Give Account");
}

void create_accounts_panel::add_asset_account_page(){
    _asset_account_panel = new asset_accounts_panel(_notebook, std::make_shared<asset_account>());
    _notebook->AddPage(_asset_account_panel, "Asset Account");
}

void create_accounts_panel::on_save(wxCommandEvent& event){
    int selected_page = _notebook->GetSelection();
    wxString selected_label = _notebook->GetPageText(selected_page);

    if (selected_label == "Bank Account"){
        _bank_accounts_panel->save();
    } else if (selected_label == "Credit Card Account") {
        _credit_card_account_panel->save();
    } else if (selected_label == "Loan Account") {
        _loan_account_panel->save();
    } else if (selected_label == "Category Account") {
        _category_account_panel->save();
    } else if (selected_label == "Goal Account") {
        _goal_account_panel->save();
    } else if (selected_label == "Chit Account") {
        _chit_account_panel->save();
    } else if (selected_label == "Borrow/Give Account") {
        _borrow_give_account_panel->save();
    } else if (selected_label == "Asset Account") {
        _asset_account_panel->save();
    }
}
