//
// Created by Matilde Tarchi on 20/04/23.
//

#ifndef INGROSSO_ONLINE_STOREFRAME_H
#define INGROSSO_ONLINE_STOREFRAME_H
#include "wx/wxhtml.h"
#include "wx/wx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "SelectSubFrame.h"
#include "UsernameGlobal.h"
#include "ProvidersFrame.h"
#include "wx/grid.h"


class storeFrame : public wxFrame {
public:
    storeFrame(const wxString &title, const std::string &sub, const std::string &disp);
    static const long IdButtonRemove;
    static const long IdButtonBack;
DECLARE_EVENT_TABLE()


private:
    void IsRemove(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);
    void IsComeBack(wxCommandEvent& event);
    wxButton *BackButton;
    wxButton *RemoveButton;
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

#endif //INGROSSO_ONLINE_STOREFRAME_H
