#pragma once

#include <wx/panel.h>

class dashboard_panel : public wxPanel {
public:
  dashboard_panel(wxWindow* parent);

private:
  wxSizer* _main_sizer;
};