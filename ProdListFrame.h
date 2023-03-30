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
    static const long IdButtonSelection;
DECLARE_EVENT_TABLE()


private:
    void IsFavourites(wxCommandEvent &event);
    void selection_data(wxCommandEvent& event);
    void OnCellLeftClick(wxGridEvent& event);
    void ComeBack(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);
    wxButton *FavButton;
    wxButton *CartButton;
    wxTextCtrl *sub;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    wxTextCtrl *quant;
    wxGrid *grid;
    wxRadioButton *selection;
    std::string sub_name;
    std::string disponibility;
    wxChoice* choiceOrder;
    string** mat_store;
};

#endif //INGROSSO_ONLINE_PRODLISTFRAME_H
