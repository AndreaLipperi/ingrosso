//
// Created by Andrea Lipperi on 08/05/23.
//

#ifndef INGROSSO_ONLINE_SELECTCITYFRAME_H
#define INGROSSO_ONLINE_SELECTCITYFRAME_H

#include "wx/wxhtml.h"
#include "wx/wx.h"

class SelectCityFrame :public wxFrame {
public:
    SelectCityFrame(const wxString &title);

    static const long IdButtonInsert;
    static const long IdButtonComeBack;


DECLARE_EVENT_TABLE()
private:
    void ComeBack(wxCommandEvent& event);
    void InsertCity(wxCommandEvent& event);
    wxButton *Insert;
    wxButton *Back;
    wxChoice* choiceC;
};

#endif //INGROSSO_ONLINE_SELECTCITYFRAME_H
