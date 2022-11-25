//
// Created by dario on 12/11/2022.
//
#include "wx/wxhtml.h"
#include "wx/wx.h"
#ifndef BUTTON_WXWIDGETS_FRAME_H
#define BUTTON_WXWIDGETS_FRAME_H
class Menu: public wxFrame
{
public:
    Menu(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnI(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};
#endif //BUTTON_WXWIDGETS_FRAME_H
