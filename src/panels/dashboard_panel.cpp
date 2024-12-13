#include <panels/dashboard_panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

dashboard_panel::dashboard_panel(wxWindow *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    _main_sizer = new wxBoxSizer(wxHORIZONTAL);
    load();
}

void dashboard_panel::load() {
    for (const auto& table: all_account_types ) {
        auto rows = db.select({}, table);
        for (const auto& row: rows) {
            auto acc = get_account_pointer(table);
            acc->set(row);
            _accounts.push_back(acc);
        }
    }
}

void dashboard_panel::refresh() {
    _accounts.clear();
    for (const auto& table: all_account_types ) {
        auto rows = db.select({}, table);
        for (const auto& row: rows) {
            auto acc = get_account_pointer(table);
            acc->set(row);
            _accounts.push_back(acc);
        }
    }
}
