#include <dashboard/home.h>

home::home(): wxFrame(NULL, wxID_ANY, wxT("Dashboard"), wxDefaultPosition,wxDefaultSize, wxDEFAULT_FRAME_STYLE) {
    _main_sizer = new wxBoxSizer(wxVERTICAL);
    _notebook = new wxNotebook(this, wxID_ANY);
    _main_sizer->Add(_notebook, 1, wxEXPAND | wxALL, 10);

    load_accounts();
    load_transactions();

    add_dashboard_page();
    add_create_accounts_page();
    add_transactions_page();
    add_categories_view_page();

    SetSizerAndFit(_main_sizer);
    Layout();
}

void home::add_create_accounts_page() {
    _create_accounts = new create_accounts_panel(_notebook);
    _notebook->AddPage(_create_accounts, "Create Accounts");
}

void home::add_dashboard_page() {
    _dashboard = new dashboard_panel(_notebook);
    _notebook->AddPage(_dashboard, "Dashboard");
}

void home::add_transactions_page() {
    auto dash = new wxPanel(_notebook, wxID_ANY);
    _notebook->AddPage(dash, "Transactions");
}

void home::add_categories_view_page() {
    auto dash = new wxPanel(_notebook, wxID_ANY);
    _notebook->AddPage(dash, "Categories");
}

void home::load_accounts() {
    global_config.accounts.clear();
    for (const auto& table: all_account_types ) {
        auto rows = db.select({}, table);
        for (const auto& row: rows) {
            auto acc = get_account_pointer(table);
            acc->set(row);
            global_config.accounts[acc->id()] = acc;
        }
    }
}

void home::load_transactions() {
    global_config.transactions.clear();
    auto rows = db.select({}, "transactions");
    for (const auto& row: rows) {
        auto tr = std::make_shared<transaction>();
        tr->set(row);
        global_config.transactions[tr->id()] = tr;
    }
}
