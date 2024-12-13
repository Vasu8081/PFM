#pragma once

#include <wx/panel.h>
#include <models/account.h>

class dashboard_panel : public wxPanel {
public:
  dashboard_panel(wxWindow* parent);

  void load();

  void refresh();

private:
  wxSizer* _main_sizer;
  std::vector<std::shared_ptr<account>> _accounts;
  database db;
};