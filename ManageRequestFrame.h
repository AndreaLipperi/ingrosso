//
// Created by Andrea Lipperi on 21/04/23.
//

#ifndef INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
#define INGROSSO_ONLINE_MANAGEREQUESTFRAME_H

#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/grid.h"
#include "ordersMethods.h"

class ManageRequestFrame: public wxDialog{
public:
    ManageRequestFrame(const wxString& title);

    static const long IdButtonConfirm;
    static const long IdButtonDeny;
    static const long IdButtonView;

DECLARE_EVENT_TABLE()


private:
    void OnConfirm(wxCommandEvent& event);
    void OnDeny(wxCommandEvent& event);
    void ViewOrder(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);

    wxButton *Confirm;
    wxButton *Deny;
    wxButton *View;
    wxTextCtrl *sub;
    wxTextCtrl *cat;
    wxTextCtrl *name;
    wxTextCtrl *cost;
    wxBoxSizer *sizer;
    wxSpinCtrl* spinCtrl;
    wxGrid *grid;
    std::string username;
    wxChoice* choiceOrder;
    std::string** mat_order;
};




#endif //INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
