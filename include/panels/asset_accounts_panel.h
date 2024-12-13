#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/asset_account.h>

class asset_accounts_panel : public wxPanel {
public:
    asset_accounts_panel(wxWindow *parent, std::shared_ptr<account> account);

    void save();

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

