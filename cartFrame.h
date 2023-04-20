//
// Created by Matilde Tarchi on 20/04/23.
//

#ifndef INGROSSO_ONLINE_CARTFRAME_H
#define INGROSSO_ONLINE_CARTFRAME_H
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

class cartFrame : public wxFrame {
public:
    cartFrame(const wxString &title);
    static const long IdButtonRemove;
    static const long IdButtonOrder;
    static const long IdButtonComeBack;
DECLARE_EVENT_TABLE()


private:
    void IsRemove(wxCommandEvent &event);
    void IsOrder(wxCommandEvent &event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Remove;
    wxBoxSizer *sizer;
    wxButton *Order;
    wxButton *Back;
    wxTextCtrl *sub;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    std::string username;
    std::string** mat_cart;
    wxGrid *grid;
    wxSpinCtrl* spinCtrl;
};

#endif //INGROSSO_ONLINE_FAVOURITESFRAME_H
