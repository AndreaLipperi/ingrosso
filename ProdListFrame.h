//
// Created by Andrea Lipperi on 22/03/23.
//

#ifndef INGROSSO_ONLINE_PRODLISTFRAME_H
#define INGROSSO_ONLINE_PRODLISTFRAME_H
#include "wx/wxhtml.h"
#include "wx/wx.h"
#include <string>
#include "usersMethods.h"
#include "users.h"
#include "storeMethods.h"
#include <iostream>
#include <fstream>
#include "MyApp.h"
#include "SelectFrame.h"
#include "SelectSubFrame.h"
#include "Enter.h"
#include "ProvidersFrame.h"
#include "RegisterFrame.h"
#include "ClientFrame.h"
#include "wx/grid.h"




class ProdListFrame : public wxFrame {
public:
    ProdListFrame(const wxString &title, const std::string &sub, const std::string &disp);
    static const long IdButtonFav;
    static const long IdButtonCart;
    static const long IdButtonInsert;
DECLARE_EVENT_TABLE()


private:
    void IsFavourites(wxCommandEvent &event);
    void IsCart(wxCommandEvent& event);
    void IsInsert(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);
    wxButton *FavButton;
    wxButton *CartButton;
    wxButton *InsertButton;
    wxTextCtrl *sub;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    wxBoxSizer *sizer;
    wxSpinCtrl* spinCtrl;
    wxGrid *grid;
    std::string sub_name;
    std::string disponibility;
    wxChoice* choiceOrder;
    wxChoice* choiceQuantity;
    string** mat_store;
};

#endif //INGROSSO_ONLINE_PRODLISTFRAME_H
