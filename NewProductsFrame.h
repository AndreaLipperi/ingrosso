//
// Created by dario on 05/12/2022.
//

#ifndef INGROSSO_ONLINE_NEWPRODUCTSFRAME_H
#define INGROSSO_ONLINE_NEWPRODUCTSFRAME_H

#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "ProvidersFrame.h"

class NewProductsFrame:public wxFrame {
public:
    NewProductsFrame(const wxString &title);

    static const long IdButtonInsert;
    static const long IdButtonComeBack;


DECLARE_EVENT_TABLE()
private:
    void ComeBack(wxCommandEvent& event);
    void InsertProduct(wxCommandEvent& event);
    wxButton *Insert;
    wxButton *Back;
    wxTextCtrl *tcCategory;
    wxTextCtrl *tcName;
    wxTextCtrl *tcQ_a;
    wxTextCtrl *tcCost;
};

#endif //INGROSSO_ONLINE_NEWPRODUCTSFRAME_H
