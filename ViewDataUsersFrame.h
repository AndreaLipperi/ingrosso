//
// Created by Andrea Lipperi on 08/05/23.
//

#ifndef INGROSSO_ONLINE_VIEWDATAUSERSFRAME_H
#define INGROSSO_ONLINE_VIEWDATAUSERSFRAME_H

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

class ViewDataUsersFrame : public wxFrame {
public:
    ViewDataUsersFrame(const wxString &title, const std::string &var_city);
    static const long IdButtonBack;
    DECLARE_EVENT_TABLE()


private:
    void OnChoice(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Back;
    wxBoxSizer *sizer;
    wxGrid *grid;
    std::string city;
    std::string type;
    std::string username;
    wxChoice* choiceOrder;
    string** mat_users;
};

#endif //INGROSSO_ONLINE_VIEWDATAUSERSFRAME_H
