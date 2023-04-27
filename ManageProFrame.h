//
// Created by Andrea Lipperi on 31/03/23.
//

#ifndef INGROSSO_ONLINE_MANAGEPROFRAME_H
#define INGROSSO_ONLINE_MANAGEPROFRAME_H

#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/string.h"
#include <string>
#include "ProvidersFrame.h"
#include "categoriesMethods.h"
#include "subcategoriesMethods.h"



class ManageProFrame : public wxDialog{
public:
    ManageProFrame(const wxString& title);

    static const long IdButtonConfirm;
DECLARE_EVENT_TABLE()


private:
    void OnConfirm(wxCommandEvent& event);
    wxButton *Confirm;
    std::string username;
    wxBoxSizer *sizer;
    std::string type;
    string** data_user;
    wxTextCtrl *tcA;
    wxTextCtrl *tcC;
    wxTextCtrl *tcU;
    wxTextCtrl *tcEm;
    wxTextCtrl *m_passwordText;

};


#endif //INGROSSO_ONLINE_MANAGEPROFRAME_H
