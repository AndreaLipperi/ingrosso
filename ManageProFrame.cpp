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



    wxStaticText *address = new wxStaticText(this, -1, wxT("Address"));
    wxStaticText *city = new wxStaticText(this, -1, wxT("City"));
    wxStaticText *password = new wxStaticText(this, -1, wxT("Password"));
    wxStaticText *usernameText = new wxStaticText(this, -1, wxT("Username"));
    wxStaticText *email=new wxStaticText(this, -1, wxT("Email"));

    Confirm=new wxButton (this,IdButtonConfirm,_T ("Confirm"),wxDefaultPosition,wxDefaultSize,0);
    TableUsers table;
    data_user=new string *[1];
    for (int k = 0; k < 1; k++) {
        data_user[k] = new string[5];
    }
    data_user=table.select_data(username);
    tcA = new wxTextCtrl(this, wxID_ANY,data_user[0][0]);
    tcC = new wxTextCtrl(this, wxID_ANY,data_user[0][1]);
    tcU= new wxTextCtrl(this, wxID_ANY,username);
    tcEm=new wxTextCtrl(this, wxID_ANY,data_user[0][2]);
    m_passwordText = new wxTextCtrl(this, wxID_ANY, data_user[0][3], wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(address);
    sizer->Add(tcA, 1, wxALL, 5);
    sizer->Add(city);
    sizer->Add(tcC,1, wxALL, 5);
    sizer->Add(usernameText);
    sizer->Add(tcU, 1, wxALL, 5);
    sizer->Add(email);
    sizer->Add(tcEm, 1, wxALL, 5);
    sizer->Add(password);
    sizer->Add(m_passwordText,1, wxALL, 5);
    sizer->Add(Confirm,0);


    SetSizer(sizer);

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
