#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/asset_account.h>
#include <forms/models_form.h>

class asset_account_form final : public wxPanel, public model_form {
public:
    asset_account_form(wxWindow *parent, std::shared_ptr<account> account);

    void save() override;

private:
    std::shared_ptr<asset_account> _account;
    wxSizer* _main_sizer;
    wxTextCtrl* _asset_name_ctrl;
    wxTextCtrl* _asset_type_ctrl;
    wxTextCtrl* _cost_of_ownership_ctrl;
    wxTextCtrl* _paid_amount_ctrl;
    wxTextCtrl* _current_market_value_ctrl;
    wxTextCtrl* _purchase_date_ctrl;
};

