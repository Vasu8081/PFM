#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/user.h>

class user_panel : public wxPanel {
public:
    user_panel(wxWindow* parent, std::shared_ptr<user> usr);

    void save();

private:
    std::shared_ptr<user> _usr;
    wxSizer* _main_sizer;
    wxTextCtrl* _id_ctrl;
    wxTextCtrl* _name_ctrl;
    wxTextCtrl* _email_ctrl;
    wxTextCtrl* _password_ctrl;
    wxTextCtrl* _mobile_ctrl;
};
