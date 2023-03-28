//
// Created by Matilde Tarchi on 28/03/23.
//

#include "MenageProFrame.h"

std::string t;
std::string b_n;
std::string a;
std::string c;
std::string em;
std::string psw;
std::string u;


const long MenageProFrame::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (MenageProFrame, wxDialog)
                EVT_BUTTON(IdButtonConfirm, MenageProFrame::Confirm)
END_EVENT_TABLE()

RegisterFrame::RegisterFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs1=new wxFlexGridSizer(1,2, 12,-5);



    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *business_name = new wxStaticText(panel, -1, wxT("Business_name"));
    wxStaticText *address = new wxStaticText(panel, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(panel, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
    wxStaticText *username = new wxStaticText(panel, -1, wxT("Username"));
    wxStaticText *email=new wxStaticText(panel, -1, wxT("Email"));

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Conferma"),wxDefaultPosition,wxDefaultSize,0);


    tcB_n = new wxTextCtrl(panel, wxID_ANY,"");
    tcA = new wxTextCtrl(panel, wxID_ANY,"");
    tcC = new wxTextCtrl(panel, wxID_ANY,"");
    tcU= new wxTextCtrl(panel, wxID_ANY,"");
    tcEm=new wxTextCtrl(panel, wxID_ANY,"");
    m_passwordText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);


    fgs->Add(fgs1);
    fgs->Add(business_name);
    fgs->Add(tcB_n,1, wxEXPAND);
    fgs->Add(address);
    fgs->Add(tcA, 1, wxEXPAND);
    fgs->Add(city);
    fgs->Add(tcC, 1);
    fgs->Add(username);
    fgs->Add(tcU, 1, wxEXPAND);
    fgs->Add(email);
    fgs->Add(tcEm, 1, wxEXPAND);
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


void MenageProFrame::Confirm(wxCommandEvent &event) {
    Close();

    b_n = tcB_n->GetValue().ToStdString();
    a = tcA->GetValue().ToStdString();
    c = tcC->GetValue().ToStdString();
    u = tcU->GetValue().ToStdString();
    em = tcEm->GetValue().ToStdString();
    psw = m_passwordText->GetValue().ToStdString();
    TableUsers table;


}