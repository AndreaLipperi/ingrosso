//
// Created by Matilde Tarchi on 28/03/23.
//

#ifndef INGROSSO_ONLINE_MENAGEPROFRAME_H
#define INGROSSO_ONLINE_MENAGEPROFRAME_H
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
#include "ProvidersFrame.h"
#include "RegisterFrame.h"
#include "ClientFrame.h"



class MenageProFrame : public wxDialog{
public:
    MenageProFrame(const wxString& title);

    static const long IdButtonConfirm;
DECLARE_EVENT_TABLE()


private:
    void Confirm(wxCommandEvent& event);
    wxButton *ConfirmB;
    wxTextCtrl *tcB_n;
    wxTextCtrl *tcA;
    wxTextCtrl *tcC;
    wxTextCtrl *tcU;
    wxTextCtrl *tcEm;
    wxTextCtrl *m_passwordText;

};


#endif //INGROSSO_ONLINE_MENAGEPROFRAME_H
