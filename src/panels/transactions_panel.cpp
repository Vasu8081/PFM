#include <models/account.h>
#include <panels/transactions_panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

transactions_panel::transactions_panel(wxWindow *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxHORIZONTAL);
    _transactions_list = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES | wxDV_VERT_RULES);
    _main_sizer->Add(_transactions_list, 1, wxEXPAND | wxALL, 10);
    _transactions_list->AppendTextColumn("From Account", wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    _transactions_list->AppendTextColumn("To Account", wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    _transactions_list->AppendTextColumn("Category", wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    _transactions_list->AppendTextColumn("Amount", wxDATAVIEW_CELL_INERT, 100, wxALIGN_RIGHT);
    _transactions_list->AppendTextColumn("Date", wxDATAVIEW_CELL_INERT, 120, wxALIGN_CENTER);
    load_ui();
    SetSizerAndFit(_main_sizer);
}

void transactions_panel::load_ui() {
    _transactions_list->DeleteAllItems();

    for (const auto& transaction : global_config.transactions) {
        auto from_account = global_config.accounts[transaction.second->from_account_id()];
        auto to_account = global_config.accounts[transaction.second->to_account_id()];
        auto cat_account = global_config.accounts[transaction.second->category_account_id()];

        wxVector<wxVariant> row;
        if (from_account) {
            row.push_back(wxVariant(from_account->account_name()));
        }
        else {
            row.push_back(wxVariant(""));
        }

        if (to_account) {
            row.push_back(wxVariant(to_account->account_name()));
        }
        else {
            row.push_back(wxVariant(""));
        }

        if (cat_account) {
            row.push_back(wxVariant(cat_account->account_name()));
        }
        else {
            row.push_back(wxVariant(""));
        }

        row.push_back(wxVariant(std::to_string(transaction.second->amount())));
        row.push_back(wxVariant(transaction.second->date()));

        _transactions_list->AppendItem(row);
    }
}

