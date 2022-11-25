//
// Created by dario on 16/11/2022.
//

#include "SelectFrame.h"
#include "wx/wx.h"
#include "Enter.h"
#include "MyApp.h"
#include "Menu.h"


wxTextCtrl *password;
const long Enter::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (Enter, wxFrame)
        EVT_BUTTON(IdButtonConfirm, Enter::Access)

END_EVENT_TABLE() // The button is pressed



Enter::Enter(const wxString &title)
        : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(365, 250)){




   // this->Layout();


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);


    wxFlexGridSizer *fgs = new wxFlexGridSizer(3, 2, 12, -10);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *thetitle = new wxStaticText(panel, -1, wxT("Email"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
   Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);



    wxTextCtrl *tc1 = new wxTextCtrl(panel, -1);
    wxTextCtrl *m_passwordText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);


    fgs->Add(thetitle);
    fgs->Add(tc1, 1, wxEXPAND);
    fgs->Add(password);
    fgs->Add(m_passwordText, 1);
    fgs->Add(Confirm,0,wxLeft,100);

    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox->Add(fgs, 1, wxALL, 10);


    panel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();
    std::string e = tc1->GetValue().ToStdString();
    std::string p = m_passwordText->GetValue().ToStdString();


}

void Enter::Access(wxCommandEvent &event) {
    int x;

}
