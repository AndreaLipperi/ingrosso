//
// Created by Andrea Lipperi on 26/04/23.
//

#ifndef INGROSSO_ONLINE_VIEWORDERFRAME_H
#define INGROSSO_ONLINE_VIEWORDERFRAME_H

#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/grid.h"
#include "ordersMethods.h"

class ViewOrderFrame: public wxDialog {
public:
    ViewOrderFrame(const wxString& title, const std::string &code_order);

    static const long IdButtonBack;

DECLARE_EVENT_TABLE()


private:
    void ComeBack(wxCommandEvent& event);

    wxButton *Back;
    wxTextCtrl *sub;
    wxTextCtrl *disp;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    wxBoxSizer *sizer;
    wxSpinCtrl* spinCtrl;
    wxGrid *grid;
    std::string order;
    std::string username;
    std::string** mat_order;
};


#endif //INGROSSO_ONLINE_VIEWORDERFRAME_H