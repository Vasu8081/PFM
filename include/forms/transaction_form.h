#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/transaction.h>
#include <forms/models_form.h>
#include <wx/notebook.h>

class transaction_form final : public wxPanel, public model_form {
public:
    transaction_form(wxWindow* parent, std::shared_ptr<transaction> txn);

    void save() override;

    void add_income_page();
    void add_expense_page();
    void add_transfer_page();

private:
    std::shared_ptr<transaction> _txn;
    wxSizer* _main_sizer;
    wxNotebook* _notebook;
    std::vector<model_form*> _forms;
};
