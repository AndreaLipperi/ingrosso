//
// Created by dario on 23/11/2022.
//


#include "wx/wx.h"
#include "RegisterFrame.h"
#include "cityMethods.h"
#include "SelectFrame.h"

const long RegisterFrame::IdButtonConfirm =::wxNewId();
const long RegisterFrame::IdButtonProvider =::wxNewId();
const long RegisterFrame::IdButtonBack =::wxNewId();
const long RegisterFrame::IdButtonClient =::wxNewId();

BEGIN_EVENT_TABLE (RegisterFrame, wxDialog)
        EVT_BUTTON(IdButtonConfirm, RegisterFrame::Register)
        EVT_BUTTON(IdButtonBack, RegisterFrame::ComeBack)
        EVT_RADIOBUTTON(IdButtonClient, RegisterFrame::IsClient)
        EVT_RADIOBUTTON(IdButtonProvider, RegisterFrame::IsProvider)
END_EVENT_TABLE()

RegisterFrame::RegisterFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs1=new wxFlexGridSizer(1,2, 12,-5);

    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    TableCity table;
    std::vector<std::string> cities;

    cities=table.select();
    wxVector<string> choices;
    for (int k=0; k<table.number_of_city(); k++){
        choices.push_back(cities[k]);
    }
    wxString myString[table.number_of_city()];
    for (int i=0;i<table.number_of_city();i++) {
        myString[i].Append(choices[i]);
    }
    cities.clear();
    choices.clear();

    choiceC=new wxChoice(panel, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceC->Append("Select");
    choiceC->Append(table.number_of_city(),myString);

    wxStaticText *type = new wxStaticText(panel, -1, wxT("Type"));
    wxStaticText *business_name = new wxStaticText(panel, -1, wxT("Business_name"));
    wxStaticText *address = new wxStaticText(panel, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(panel, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
    wxStaticText *username = new wxStaticText(panel, -1, wxT("Username"));
    wxStaticText *email=new wxStaticText(panel, -1, wxT("Email"));

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton (panel,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);
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
    fgs->Add(choiceC, 1, wxEXPAND);
    fgs->Add(username);
    fgs->Add(tcU, 1, wxEXPAND);
    fgs->Add(email);
    fgs->Add(tcEm, 1, wxEXPAND);
    fgs->Add(password);
    fgs->Add(m_passwordText, 1);
    fgs->Add(Confirm,0);
    fgs->Add(Back,0);


    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox->Add(fgs, 1, wxALL, 10);



    panel->SetSizer(hbox);

    Centre();
}



void RegisterFrame::IsProvider(wxCommandEvent& event) {
    t="F";
}

void RegisterFrame::IsClient(wxCommandEvent& event) {
    t="C";
}




void RegisterFrame::Register(wxCommandEvent &event) {
    if (t=="" || tcB_n->IsEmpty() || tcA->IsEmpty() || choiceC->GetSelection() == wxNOT_FOUND || tcU->IsEmpty() || tcEm->IsEmpty() || m_passwordText->IsEmpty()){
        wxMessageBox("Insert every data.", "Error", wxICON_ERROR);
    } else {

        std::string b_n = tcB_n->GetValue().ToStdString();
        std::string a = tcA->GetValue().ToStdString();
        int id_city = choiceC->GetSelection();
        std::string u = tcU->GetValue().ToStdString();
        std::string em = tcEm->GetValue().ToStdString();
        std::string psw = m_passwordText->GetValue().ToStdString();
        int control_digit=0;
        int control_upper=0;
        for(int i=0; i<psw.length();i++){
            if (isdigit(psw[i])){
                control_digit=control_digit+1;
            }
            if (isupper(psw[i])) {
                control_upper=control_upper+1;
            }
        }
        if (control_digit>0 && psw.length()>=8 && control_upper>0) {
            TableUsers table;
            int numResult;
            numResult = table.access_reg(em, psw, 1);
            Users *user;

            if (numResult == 0) {
                user = new Users(t, b_n, a, em, psw, u, id_city);
                table.add(*user);
                Close();
                SelectFrame *home = new SelectFrame(_T("YOUR MARKET RIGHT HERE"), wxPoint(50, 20), wxSize(500, 300));
                home->Show(TRUE);
            } else {
                wxLogMessage("There is already an account with this email");
            }
        } else {
            wxLogMessage("The password should contain a number, a capital letter and a lenght >= of 8 characters");
        }
    }

}
void RegisterFrame::ComeBack(wxCommandEvent &event) {
    Close();
    SelectFrame *home = new SelectFrame(_T("YOUR MARKET RIGHT HERE"), wxPoint(50, 20), wxSize(500, 300));
    home->Show(TRUE);
}

