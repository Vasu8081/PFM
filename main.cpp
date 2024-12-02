#include <wx/wx.h>

class PFM : public wxApp {
public:
    bool OnInit() override;
};

bool PFM::OnInit() {
    return true;
}

wxIMPLEMENT_APP(PFM);