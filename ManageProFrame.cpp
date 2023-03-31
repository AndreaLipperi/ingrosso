//
// Created by Andrea Lipperi on 31/03/23.
//

#include "ManageProFrame.h"
#include "UsernameGlobal.h"
#include "usersMethods.h"
#include "users.h"


const long ManageProFrame::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (ManageProFrame, wxDialog)
                EVT_BUTTON(IdButtonConfirm, ManageProFrame::OnConfirm)
END_EVENT_TABLE()

ManageProFrame::ManageProFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    username=UsernameGlobal::GetInstance().GetValueUsername();
    type=UsernameGlobal::GetInstance().GetValueType();


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs1=new wxFlexGridSizer(1,2, 12,-5);



    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *address = new wxStaticText(panel, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(panel, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(panel, -1, wxT("Password"));
    wxStaticText *usernameText = new wxStaticText(panel, -1, wxT("Username"));
    wxStaticText *email=new wxStaticText(panel, -1, wxT("Email"));

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Conferma"),wxDefaultPosition,wxDefaultSize,0);
    TableUsers table;
    data_user=new string *[1];
    for (int k = 0; k < 1; k++) {
        data_user[k] = new string[5];
    }
    data_user=table.select_data(username);
    tcA = new wxTextCtrl(panel, wxID_ANY,data_user[0][0]);
    tcC = new wxTextCtrl(panel, wxID_ANY,data_user[0][1]);
    tcU= new wxTextCtrl(panel, wxID_ANY,username);
    tcEm=new wxTextCtrl(panel, wxID_ANY,data_user[0][2]);
    m_passwordText = new wxTextCtrl(panel, wxID_ANY, data_user[0][3], wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);


    fgs->Add(fgs1);
    fgs->Add(address);
    fgs->Add(tcA, 1, wxEXPAND);
    fgs->Add(city);
    fgs->Add(tcC, 1);
    fgs->Add(usernameText);
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


void ManageProFrame::OnConfirm(wxCommandEvent &event) {
    Close();

    std::string b_n=data_user[0][4];
    std::string new_address =tcA->GetValue().ToStdString();
    std::string new_city=tcC->GetValue().ToStdString();
    std::string new_username=tcU->GetValue().ToStdString();
    std::string new_email=tcEm->GetValue().ToStdString();
    std:string new_pass=m_passwordText->GetValue().ToStdString();
    Users *user=new Users(type,b_n,new_city,new_address,new_email,new_pass,new_username);
    TableUsers table;
    std::string email = table.select_email(username);
    UsernameGlobal::GetInstance().SetValueUsername(user->get_username());
    table.changeData(email,*user);


}
