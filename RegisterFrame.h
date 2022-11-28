
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
#include "Menu.h"
#include "Enter.h"
#include "RegisterFrame.h"




class RegisterFrame : public wxFrame{
public:
    RegisterFrame(const wxString& title);
    static const long IdButtonConfirm;

    DECLARE_EVENT_TABLE()


private:
    void Register(wxCommandEvent& event);
    wxButton *Confirm;
    wxTextCtrl *tcT;
    wxTextCtrl *tcB_n;
    wxTextCtrl *tcA;
    wxTextCtrl *tcC;
    wxTextCtrl *tcU;
    wxTextCtrl *tcEm;
    wxTextCtrl *m_passwordText;

};


#endif //BUTTON_WXWIDGETS_REGISTERFRAME_H
