//
// Created by dario on 16/11/2022.
//

#include "SelectFrame.h"
#include "wx/wx.h"
#include "Enter.h"
#include "MyApp.h"
#include "Menu.h"
#include "usersMethods.h"


wxTextCtrl *password;
const long Enter::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (Enter, wxFrame)
        EVT_BUTTON(IdButtonConfirm, Enter::Access)

END_EVENT_TABLE() // The button is pressed


std::string e;
std::string p;
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



    tc1 = new wxTextCtrl(panel, -1);
    m_passwordText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);


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



}

void Enter::Access(wxCommandEvent &event) {

    e = tc1->GetValue().ToStdString();
    p = m_passwordText->GetValue().ToStdString();
    int result;
    TableUsers table;
    result = table.access_reg(e, p, 0);
    if (result == 0) {
        //TODO messaggio di errore
    } else{
        Users user;
        std::string TypeUser;
        TypeUser=user.
        if()
    }

}
