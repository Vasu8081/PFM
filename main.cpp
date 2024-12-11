#include <wx/wx.h>
#include <database/account_db.h>
#include <database/user_db.h>
#include <database/database.h>

class PFM final : public wxApp {
public:
    bool OnInit() override;
};

bool PFM::OnInit() {
    auto _db = new database("finance_app", "quickwitted", "", "localhost", "5432");
    _db->create_tables();
    auto _udb = new user_db(*_db);
    user usr("vkandula", "vasudhanvarma@gmail.com", "vkandula", 6381851146);
    _udb->add_user(usr);
    return true;
}

wxIMPLEMENT_APP(PFM);