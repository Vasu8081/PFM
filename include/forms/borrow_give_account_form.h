#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/borrow_give_account.h>
#include <forms/models_form.h>

class borrow_give_account_form final : public wxPanel, public model_form {
public:
    borrow_give_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;
    void reset() override;
    void refresh() override;

private:
    std::shared_ptr<borrow_give_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _person_name_ctrl;
    wxTextCtrl* _balance_due_ctrl;
    wxTextCtrl* _due_date_ctrl;
};
