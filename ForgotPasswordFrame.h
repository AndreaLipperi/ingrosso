//
// Created by Andrea Lipperi on 06/05/23.
//

#ifndef INGROSSO_ONLINE_FORGOTPASSWORDFRAME_H
#define INGROSSO_ONLINE_FORGOTPASSWORDFRAME_H

#include <wx/wx.h>
#include "wx/wxhtml.h"

class ForgotPasswordFrame : public wxFrame{
public:
    ForgotPasswordFrame(const wxString& title);
    static const long IdButtonConfirm;
    static const long IdButtonChange;
    static const long IdButtonBack;

DECLARE_EVENT_TABLE()

private:
    void Insert(wxCommandEvent& event);
    void Change(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Confirm;
    wxButton *Back;
    wxButton *ChangeButton;
    wxStaticText *txt_email;
    wxStaticText *txt_psw;
    wxBoxSizer *sizer;
    wxTextCtrl *m_passwordText;
    wxTextCtrl *tc1;
};



#endif //INGROSSO_ONLINE_FORGOTPASSWORDFRAME_H
