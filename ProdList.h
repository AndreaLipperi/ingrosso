//
// Created by Andrea Lipperi on 22/03/23.
//

#ifndef INGROSSO_ONLINE_PRODLIST_H
#define INGROSSO_ONLINE_PRODLIST_H
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
#include "wx/grid.h"




class ProdListFrame : public wxFrame {
public:
    ProdListFrame(const wxString &title);

    static const long IdButtonConfirm;
    static const long IdButtonComeBack;
DECLARE_EVENT_TABLE()


private:
    void IsConfirm(wxCommandEvent &event);

    void ComeBack(wxCommandEvent& event);

    wxButton *Confirm;
    wxButton *Back;
    wxTextCtrl *sub;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    wxTextCtrl *quant;
};

#endif //INGROSSO_ONLINE_PRODLIST_H
