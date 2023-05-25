
//
// Created by dario on 23/11/2022.
//

#ifndef BUTTON_WXWIDGETS_REGISTERFRAME_H
#define BUTTON_WXWIDGETS_REGISTERFRAME_H
#include "wx/wxhtml.h"
#include "wx/wx.h"
#include <string>
#include "usersMethods.h"
#include "users.h"
#include <iostream>
#include <fstream>
#include "MyApp.h"
#include "SelectFrame.h"
#include "SelectSubFrame.h"
#include "Enter.h"
#include "ProvidersFrame.h"
#include "RegisterFrame.h"
#include "ClientFrame.h"




class RegisterFrame : public wxFrame{
public:
    RegisterFrame(const wxString& title);

    static const long IdButtonConfirm;
    static const long IdButtonBack;
    static const long IdButtonProvider;
    static const long IdButtonVP;
    static const long IdButtonClient;
DECLARE_EVENT_TABLE()


private:
    void Register(wxCommandEvent& event);
    void IsProvider(wxCommandEvent& event);
    void IsClient(wxCommandEvent& event);
    void ViewPass(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    void OnTextChange(wxCommandEvent& event);
    wxFlexGridSizer *fgs;
    wxButton *Confirm;
    wxButton *ViewP;
    wxButton *Back;
    wxRadioButton *Provider;
    wxRadioButton *Client;
    std::string t;
    wxChoice* choiceC;
    wxTextCtrl *tcB_n;
    wxTextCtrl *tcA;
    wxTextCtrl *tcC;
    wxTextCtrl *tcU;
    wxTextCtrl *tcEm;
    wxTextCtrl *m_passwordText;
    std::string messageError;
    std::string messageCorrect;
    std::string txt_button;
    wxStaticText *txt_message;
    wxTextCtrl *m_passwordConf;
    wxStaticText *txt_conf_psw;

};


#endif //BUTTON_WXWIDGETS_REGISTERFRAME_H
