//
// Created by dario on 12/11/2022.
//

#include "wx/wxhtml.h"
#include "wx/wx.h"
#ifndef BUTTON_WXWIDGETS_FRAME_H
#define BUTTON_WXWIDGETS_FRAME_H
class SelectSubFrame:public wxFrame {
public:
    SelectSubFrame(const wxString &title);

    static const long IdButtonInsert;
    static const long IdButtonComeBack;
    std::string sub_name;


DECLARE_EVENT_TABLE()
private:
    void ComeBack(wxCommandEvent& event);
    void InsertProduct(wxCommandEvent& event);
    void OnChoice(wxCommandEvent& event);
    wxButton *Insert;
    wxButton *Back;
    wxTextCtrl *tcCategory;
    wxChoice* choiceC;
    wxChoice* choiceSubC;
};
#endif //BUTTON_WXWIDGETS_FRAME_H