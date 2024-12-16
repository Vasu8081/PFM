#pragma once

#include <wx/wx.h>
#include <wx/notebook.h>
#include <enums.h>
#include <forms/forms_include.h>

class create_accounts_panel : public wxPanel {
public:
  create_accounts_panel(wxWindow* parent);

  void add_bank_account_page();
  void add_credit_card_account_page();
  void add_loan_account_page();
  void add_category_account_page();
  void add_goal_account_page();
  void add_chit_account_page();
  void add_borrow_give_account_page();
  void add_asset_account_page();

  void on_save(wxCommandEvent& event);

private:
  wxSizer* _main_sizer;
  wxNotebook* _notebook;

  std::vector<model_form*> _form;
  wxTextCtrl* _account_name_ctrl;
  enums::account_type _account_type;
};
