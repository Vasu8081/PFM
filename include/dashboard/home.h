#pragma once

#include <wx/wx.h>
#include <panels/create_accounts.h>
#include <panels/dashboard_panel.h>
#include <panels/transactions_panel.h>

class home: public wxFrame {
public:
    home();
    void load_accounts();
    void load_transactions();
    void add_dashboard_page();
    void add_create_accounts_page();
    void add_transactions_page();
    void add_categories_view_page();


private:
    wxSizer* _main_sizer;
    create_accounts_panel* _create_accounts;
    dashboard_panel* _dashboard;
    transactions_panel* _transactions;
    wxNotebook* _notebook;
    database db;
};