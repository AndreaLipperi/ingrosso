//
// Created by dario on 23/11/2022.
//


#include "wx/wx.h"
#include "RegisterFrame.h"

const long RegisterFrame::IdButtonConfirm =::wxNewId();
const long RegisterFrame::IdButtonProvider =::wxNewId();
const long RegisterFrame::IdButtonClient =::wxNewId();

BEGIN_EVENT_TABLE (RegisterFrame, wxDialog)
        EVT_BUTTON(IdButtonConfirm, RegisterFrame::Register)
        EVT_RADIOBUTTON(IdButtonClient, RegisterFrame::IsClient)
        EVT_RADIOBUTTON(IdButtonProvider, RegisterFrame::IsProvider)
END_EVENT_TABLE()

RegisterFrame::RegisterFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs1=new wxFlexGridSizer(1,2, 12,-5);



    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *type = new wxStaticText(panel, -1, wxT("Type"));
    wxStaticText *business_name = new wxStaticText(panel, -1, wxT("Business_name"));
    wxStaticText *address = new wxStaticText(panel, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(panel, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
    wxStaticText *username = new wxStaticText(panel, -1, wxT("Username"));
    wxStaticText *email=new wxStaticText(panel, -1, wxT("Email"));

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    Provider=new wxRadioButton(panel,IdButtonProvider, _T("Provider"), wxDefaultPosition,wxDefaultSize,0 );
    Client=new wxRadioButton(panel, IdButtonClient, _T("Client"), wxDefaultPosition, wxDefaultSize, 0);



    tcB_n = new wxTextCtrl(panel, -1);
    tcA = new wxTextCtrl(panel, -1);
    tcC = new wxTextCtrl(panel, -1);
    tcU= new wxTextCtrl(panel, -1);
    tcEm=new wxTextCtrl(panel, -1);
    m_passwordText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);

    fgs1->Add(Provider,0);
    fgs1->Add(Client,0, wxLEFT, 70);
    fgs->Add(type);
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



void RegisterFrame::IsProvider(wxCommandEvent& event) {
    t="F";
}

void RegisterFrame::IsClient(wxCommandEvent& event) {
    t="C";
}




void RegisterFrame::Register(wxCommandEvent &event) {
    Close();

    std::string b_n = tcB_n->GetValue().ToStdString();
    std::string a = tcA->GetValue().ToStdString();
    std::string c = tcC->GetValue().ToStdString();
    std::string u = tcU->GetValue().ToStdString();
    std::string em = tcEm->GetValue().ToStdString();
    std::string psw = m_passwordText->GetValue().ToStdString();
    TableUsers table;
    int numResult;
    numResult = table.access_reg(em, psw, 1);
    Users *user;

    if (numResult == 0) {
        user = new Users(t, b_n, c, a, em, psw, u);
        table.add(*user);
        cout << table.select_type(em);
    } else {
        wxLogMessage("There is already an account with this email");
    }

}

