//
// Created by Andrea Lipperi on 04/05/23.
//

#ifndef INGROSSO_ONLINE_CHOOSESTATUSFRAME_H
#define INGROSSO_ONLINE_CHOOSESTATUSFRAME_H


#include "wx/wxhtml.h"
#include "wx/wx.h"
class ChooseStatusFrame :public wxFrame {
public:
    ChooseStatusFrame(const wxString &title);

    static const long IdButtonInsert;
    static const long IdButtonComeBack;


    DECLARE_EVENT_TABLE()
private:
    void ComeBack(wxCommandEvent& event);
    void InsertProduct(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);
    wxButton *Insert;
    wxBoxSizer *sizer;
    wxButton *Back;
    wxChoice* choice;
    std::string type;
};

#endif //INGROSSO_ONLINE_CHOOSESTATUSFRAME_H
