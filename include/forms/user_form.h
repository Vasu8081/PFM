#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/user.h>
#include <forms/models_form.h>

class user_form final : public wxPanel, public model_form {
public:
    user_form(wxWindow* parent, std::shared_ptr<user> usr);

    void save() override;

private:
    std::shared_ptr<user> _usr;
    wxSizer* _main_sizer;
    wxTextCtrl* _id_ctrl;
    wxTextCtrl* _name_ctrl;
    wxTextCtrl* _email_ctrl;
    wxTextCtrl* _password_ctrl;
    wxTextCtrl* _mobile_ctrl;
};
