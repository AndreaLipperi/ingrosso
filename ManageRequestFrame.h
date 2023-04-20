//
// Created by dario on 20/04/2023.
//

#ifndef INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
#define INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/grid.h"
#include "ordersMethods.h"
#include "ViewOrderFrame.h"

class ManageRequestFrame: public wxDialog{
    public:
        ManageRequestFrame(const wxString& title);

            static const long IdButtonConfirm;
            static const long IdButtonView;

        DECLARE_EVENT_TABLE()


    private:
        void OnConfirm(wxCommandEvent& event);
        void ViewOrder(wxCommandEvent& event);

        wxButton *Confirm;
        wxButton *View;
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
    std::string** mat_store;
};



#endif //INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
