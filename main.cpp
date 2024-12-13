#include <wx/wx.h>
#include <dashboard/home.h>
#include <config.h>
#include <database/user_db.h>

config global_config;

class PFM final : public wxApp {
public:
    bool OnInit() override;
};

bool PFM::OnInit() {
    auto udb = new user_db();
    auto usr = udb->get_all_users();
    // if (usr.size() == 0) {
    //     user u("vkandula", "vasudhanvarma@gmail.com", "vkandula", "6381851146");
    //     udb->add_user(u);
    // }
    // usr = udb->get_all_users();
    global_config.user_id = usr[0].id();
    auto dashboard = new home();
    dashboard->Show();
    return true;
}

wxIMPLEMENT_APP(PFM);