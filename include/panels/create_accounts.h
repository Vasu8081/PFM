#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <enums.h>
#include <panels/bank_accounts_panel.h>
#include <panels/credit_card_accounts_panel.h>
#include <panels/loan_accounts_panel.h>
#include <panels/category_accounts_panel.h>
#include <panels/goal_accounts_panel.h>
#include <panels/chit_accounts_panel.h>
#include <panels/borrow_give_accounts_panel.h>
#include <panels/asset_accounts_panel.h>

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

  // Pointers to all account panels
  bank_accounts_panel* _bank_accounts_panel;
  credit_card_accounts_panel* _credit_card_account_panel;
  loan_accounts_panel* _loan_account_panel;
  category_accounts_panel* _category_account_panel;
  goal_accounts_panel* _goal_account_panel;
  chit_accounts_panel* _chit_account_panel;
  borrow_give_accounts_panel* _borrow_give_account_panel;
  asset_accounts_panel* _asset_account_panel;

  wxTextCtrl* _account_name_ctrl;
  enums::account_type _account_type;
};
