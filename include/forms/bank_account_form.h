#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/bank_account.h>
#include <forms/models_form.h>

class bank_account_form final : public wxPanel, public model_form {
public:
  bank_account_form(wxWindow *parent, std::shared_ptr<account> account);

  void save() override;
  void reset() override;
  void refresh() override;

private:
  std::shared_ptr<bank_account> _account;
  wxSizer* _main_sizer;
  wxTextCtrl* _account_name_ctrl;
  wxTextCtrl* _account_number_ctrl;
  wxTextCtrl* _bank_name_ctrl;
  wxTextCtrl* _balance_ctrl;
  wxTextCtrl* _hold_amount_ctrl;
  wxTextCtrl* _ifsc_code_ctrl;
};
