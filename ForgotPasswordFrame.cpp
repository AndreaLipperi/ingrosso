//
// Created by Andrea Lipperi on 06/05/23.
//

#include "ForgotPasswordFrame.h"
#include "SelectFrame.h"
#include <wx/hyperlink.h>
#include "UsernameGlobal.h"
#include "Enter.h"
#include "wx/wx.h"
#include "MyApp.h"
#include "SelectSubFrame.h"
#include "usersMethods.h"
#include "ClientFrame.h"



const long ForgotPasswordFrame::IdButtonConfirm =::wxNewId();
const long ForgotPasswordFrame::IdButtonChange =::wxNewId();
const long ForgotPasswordFrame::IdButtonBack =::wxNewId();

BEGIN_EVENT_TABLE (ForgotPasswordFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, ForgotPasswordFrame::Insert)
                EVT_BUTTON(IdButtonChange, ForgotPasswordFrame::Change)
                EVT_BUTTON(IdButtonBack, ForgotPasswordFrame::ComeBack)

END_EVENT_TABLE() // The button is pressed


ForgotPasswordFrame::ForgotPasswordFrame(const wxString &title)
        : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)){


    txt_email = new wxStaticText(this, -1, wxT("Email"));
    Confirm=new wxButton (this,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton (this,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    tc1 = new wxTextCtrl(this, -1);

    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(txt_email);
    sizer->Add(tc1, 0, wxEXPAND, 5);
    sizer->Add(Confirm,0);
    sizer->Add(Back,0);

    SetSizer(sizer);
    Centre();



}

void ForgotPasswordFrame::Insert(wxCommandEvent &event){
    if (tc1->IsEmpty()){
        wxMessageBox("Insert your email", "Error", wxICON_ERROR);
    } else {
        std::string e = tc1->GetValue().ToStdString();
        int result;
        TableUsers table;
        result = table.access_reg(e, "", 1);
        if (result == 0) {
            wxLogMessage("There is no account with this email");
        } else {
            sizer->DeleteWindows();
            txt_psw = new wxStaticText(this, -1, wxT("New Password"));
            ChangeButton=new wxButton (this,IdButtonChange,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
            m_passwordText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150, wxDefaultSize.GetHeight()), wxTE_PASSWORD);
            Back=new wxButton (this,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

            sizer->Add(txt_psw);
            sizer->Add(m_passwordText,0, wxEXPAND);
            sizer->Add(ChangeButton,0);
            sizer->Add(Back,0);
            wxSize currentSize = GetSize();
            int newWidth = currentSize.GetWidth() +1;
            int newHeight = currentSize.GetHeight() +1;
            SetSize(newWidth, newHeight);

        }
    }
}

void ForgotPasswordFrame::Change(wxCommandEvent &event) {
    if (m_passwordText->IsEmpty()){
        wxMessageBox("Insert Password.", "Error", wxICON_ERROR);
    } else {
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
            table.changePsw(tc1->GetValue().ToStdString(), psw);
            Close();
            wxLogMessage("Password Changed");
            Enter *MainWin2 = new Enter(_T("ACCESS"));
            MainWin2->ShowModal();
        } else {
            wxLogMessage("The password should contain a number, a capital letter and a lenght >= of 8 characters");
        }
    }
}

void ForgotPasswordFrame::ComeBack(wxCommandEvent &event) {
    Close();
    Enter *MainWin2 = new Enter(_T("ACCESS"));
    MainWin2->ShowModal();
}