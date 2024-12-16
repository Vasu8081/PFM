#include <wx/panel.h>
#include <models/transaction.h>
#include <forms/models_form.h>
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/datectrl.h>
#include <wx/filepicker.h>

class income_form : public wxPanel, public model_form {
public:
  income_form(wxWindow* parent, std::shared_ptr<transaction> transaction);
  void save() override; //gets all values from each control

private:
  wxSizer* _main_sizer;
  wxComboBox* _to_account_ctrl;
  wxComboBox* _category_account_ctrl;
  wxTextCtrl* _description_ctrl;
  wxTextCtrl* _amount_ctrl;
  wxDatePickerCtrl* _date_ctrl;
  wxFilePickerCtrl* _file_ctrl;
  std::shared_ptr<transaction> _transaction;
};
