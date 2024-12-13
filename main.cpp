#include <wx/wx.h>
#include <dashboard/home.h>
#include <config.h>
#include <database/database.h>
#include <models/user.h>

config global_config;

class PFM final : public wxApp {
public:
    bool OnInit() override;
};

bool PFM::OnInit() {
    database db;
    std::unordered_map<std::string, std::string> filters;
    std::string table_name = "users";
    auto res = db.select(filters, table_name);
    user u({});
    for (auto r : res ) {
        u.set(r);
        u.print();
    }
    global_config.user_id = u.id();
    auto dashboard = new home();
    dashboard->Show();
    return true;
}

wxIMPLEMENT_APP(PFM);