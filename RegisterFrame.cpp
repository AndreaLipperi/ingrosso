//
// Created by dario on 23/11/2022.
//

#include "RegisterFrame.h"

const long RegisterFrame::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (RegisterFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, RegisterFrame::Register)

END_EVENT_TABLE()

RegisterFrame::RegisterFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 300)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);


    wxFlexGridSizer *fgs = new wxFlexGridSizer(7, 2, 12, -5);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *type = new wxStaticText(panel, -1, wxT("Type"));
    wxStaticText *business_name = new wxStaticText(panel, -1, wxT("Business_name"));
    wxStaticText *address = new wxStaticText(panel, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(panel, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
    wxStaticText *username = new wxStaticText(panel, -1, wxT("Email"));

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);



    wxTextCtrl *tc1 = new wxTextCtrl(panel, -1);
    wxTextCtrl *tc2 = new wxTextCtrl(panel, -1);
    wxTextCtrl *tc3 = new wxTextCtrl(panel, -1);
    wxTextCtrl *tc4 = new wxTextCtrl(panel, -1);
    wxTextCtrl *tc5= new wxTextCtrl(panel, -1);
    wxTextCtrl *m_passwordText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);


    fgs->Add(type);
    fgs->Add(tc1, 1, wxEXPAND);
    fgs->Add(business_name);
    fgs->Add(tc2,1, wxEXPAND);
    fgs->Add(address);
    fgs->Add(tc3, 1, wxEXPAND);
    fgs->Add(city);
    fgs->Add(tc4, 1);
    fgs->Add(username);
    fgs->Add(tc5, 1, wxEXPAND);
    fgs->Add(password);
    fgs->Add(m_passwordText, 1);
    fgs->Add(Confirm,0,wxLeft,100);

    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox->Add(fgs, 1, wxALL, 10);

    std::string t=tc1->GetValue().ToStdString();
    std::string b_n=tc2->GetValue().ToStdString();
    std::string a=tc3->GetValue().ToStdString();
    std::string c=tc4->GetValue().ToStdString();
    std::string u=tc5->GetValue().ToStdString();
    std::string p=m_passwordText->GetValue().ToStdString();


    panel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();
}

void RegisterFrame::Register(wxCommandEvent &event) {

}
