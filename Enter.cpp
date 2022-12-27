//
// Created by dario on 09/12/2022.
//

//
// Created by dario on 16/11/2022.
//

#include "SelectFrame.h"
#include "wx/wx.h"
#include "Enter.h"
#include "MyApp.h"
#include "Menu.h"
#include "usersMethods.h"
#include "ClientFrame.h"
#include "ProvidersFrame.h"



const long Enter::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (Enter, wxDialog)
                EVT_BUTTON(IdButtonConfirm, Enter::Access)

END_EVENT_TABLE() // The button is pressed


std::string e;
std::string p;
Enter::Enter(const wxString &title)
        : wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(365, 250)){




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
    fgs->Add(Confirm,0);

    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox->Add(fgs, 1, wxALL, 10);


    panel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();



}

void Enter::Access(wxCommandEvent &event) {

    Hide();

    e = tc1->GetValue().ToStdString();
    p = m_passwordText->GetValue().ToStdString();
    int result;
    TableUsers table;
    result = table.access_reg(e, p, 0);
    if (result == 0) {
        wxLogMessage("Incorrect email or password");
    } else {
        std::string TypeUser;
        TypeUser = table.select_type(e);
        if (TypeUser == "F") {
            ProvidersFrame *ProvidersWin = new ProvidersFrame(_T("HOME"), wxPoint(50, 20), wxSize(500, 300));
            ProvidersWin->Show(TRUE);
        } else {
            ClientFrame *ClientWin = new ClientFrame(_T("HOME"), wxPoint(50, 20), wxSize(500, 300));
            ClientWin->Show(TRUE);
        }
    }
}