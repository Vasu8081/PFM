#include <wx/wx.h>
#include <database/account_db.h>
#include <database/user_db.h>
#include <database/database.h>
#include <dashboard/home.h>

class PFM final : public wxApp {
public:
    bool OnInit() override;
};

bool PFM::OnInit() {
    auto _db = new database("finance_app", "quickwitted", "", "localhost", "5432");
    auto dashboard = new home();
    dashboard->Show();
    return true;
}

wxIMPLEMENT_APP(PFM);