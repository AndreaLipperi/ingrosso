//
// Created by Andrea Lipperi on 03/04/23.
//

#ifndef INGROSSO_ONLINE_FAVOURITESFRAME_H
#define INGROSSO_ONLINE_FAVOURITESFRAME_H

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




class FavouritesFrame : public wxFrame {
public:
    FavouritesFrame(const wxString &title);
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
    std::string** mat_fav;
    wxGrid *grid;
    wxSpinCtrl* spinCtrl;

};


#endif //INGROSSO_ONLINE_FAVOURITESFRAME_H
