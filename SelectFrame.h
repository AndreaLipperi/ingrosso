//
// Created by dario on 12/11/2022.
//
#include "wx/wx.h"
#include "wx/wxhtml.h"
#ifndef BUTTON_WXWIDGETS_MYFRAME_H
#define BUTTON_WXWIDGETS_MYFRAME_H



class SelectFrame: public wxFrame // MainFrame is the class for our window,
{
    // It contains the window and all objects in it
public:
    SelectFrame(const wxString &title, const wxPoint &pos, const wxSize &size );

    static const long IdButtonAccess;
    static const long IdButtonRegister;

DECLARE_EVENT_TABLE()

private:
    void OnAccess( wxCommandEvent& event );
    void OnRegister(wxCommandEvent& event);
    wxButton *HelloWorld;
    wxButton *Register;
};

enum
{
    BUTTON_Hello = wxID_HIGHEST + 1 // declares an id which will be used to call our button
};

#endif