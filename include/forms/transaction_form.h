#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <models/transaction.h>
#include <forms/models_form.h>

class transaction_form final : public wxPanel, public model_form {
public:
    transaction_form(wxWindow* parent, std::shared_ptr<transaction> txn);

    void save() override;

private:
    std::shared_ptr<transaction> _txn;
    wxSizer* _main_sizer;
    wxTextCtrl* _description_ctrl;
    wxTextCtrl* _amount_ctrl;
    wxTextCtrl* _transaction_type_ctrl;
    wxTextCtrl* _from_account_id_ctrl;
    wxTextCtrl* _to_account_id_ctrl;
    wxTextCtrl* _category_account_id_ctrl;
    wxTextCtrl* _moved_from_account_ctrl;
    wxTextCtrl* _date_ctrl;
    wxTextCtrl* _proof_document_ctrl;
};
