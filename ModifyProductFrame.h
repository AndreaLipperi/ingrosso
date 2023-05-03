//
// Created by Andrea Lipperi on 02/05/23.
//

#ifndef INGROSSO_ONLINE_MODIFYPRODUCTFRAME_H
#define INGROSSO_ONLINE_MODIFYPRODUCTFRAME_H


#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/string.h"
#include <wx/spinctrl.h>
#include <string>
#include "ProvidersFrame.h"
#include "categoriesMethods.h"
#include "subcategoriesMethods.h"



class ModifyProductFrame : public wxDialog{
public:
    ModifyProductFrame(const wxString& title, int id_store);

    static const long IdButtonConfirm;
DECLARE_EVENT_TABLE()


private:
    void OnConfirm(wxCommandEvent& event);
    wxButton *Confirm;
    std::string username;
    int id;
    wxBoxSizer *sizer;
    std::string type;
    string** data_store;
    wxTextCtrl *tcD;
    wxSpinCtrlDouble *tcP;
    wxSpinCtrl *tcQ;

};

#endif //INGROSSO_ONLINE_MODIFYPRODUCTFRAME_H
